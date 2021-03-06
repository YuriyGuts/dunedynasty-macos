/** @file src/saveload/unit.c Load/save routines for Unit. */

#include <string.h>

#include "saveload.h"
#include "../pool/unit.h"
#include "../pool/pool.h"
#include "../unit.h"

static const SaveLoadDesc s_saveUnitOrientation[] = {
	SLD_ENTRY (dir24,  SLDT_INT8, speed),
	SLD_ENTRY (dir24,  SLDT_INT8, target),
	SLD_ENTRY (dir24,  SLDT_INT8, current),
	SLD_END
};

static const SaveLoadDesc s_saveUnit[] = {
	SLD_SLD   (Unit,              o, g_saveObject),
	SLD_EMPTY (      SLDT_UINT16),
	SLD_ENTRY (Unit, SLDT_UINT16, currentDestination.x),
	SLD_ENTRY (Unit, SLDT_UINT16, currentDestination.y),
	SLD_ENTRY (Unit, SLDT_UINT16, originEncoded),
	SLD_ENTRY (Unit, SLDT_UINT8,  actionID),
	SLD_ENTRY (Unit, SLDT_UINT8,  nextActionID),
	SLD_ENTRY2(Unit, SLDT_UINT8,  fireDelay, SLDT_UINT16),
	SLD_ENTRY (Unit, SLDT_UINT16, distanceToDestination),
	SLD_ENTRY (Unit, SLDT_UINT16, targetAttack),
	SLD_ENTRY (Unit, SLDT_UINT16, targetMove),
	SLD_ENTRY (Unit, SLDT_UINT8,  amount),
	SLD_ENTRY (Unit, SLDT_UINT8,  deviated),
	SLD_ENTRY (Unit, SLDT_UINT16, targetLast.x),
	SLD_ENTRY (Unit, SLDT_UINT16, targetLast.y),
	SLD_ENTRY (Unit, SLDT_UINT16, targetPreLast.x),
	SLD_ENTRY (Unit, SLDT_UINT16, targetPreLast.y),
	SLD_SLD2  (Unit, orientation, s_saveUnitOrientation, 2),
	SLD_ENTRY (Unit, SLDT_UINT8,  speedPerTick),
	SLD_ENTRY (Unit, SLDT_UINT8,  speedRemainder),
	SLD_ENTRY (Unit, SLDT_UINT8,  speed),
	SLD_ENTRY (Unit, SLDT_UINT8,  movingSpeed),
	SLD_ENTRY (Unit, SLDT_UINT8,  wobbleIndex),
	SLD_ENTRY (Unit,  SLDT_INT8,  spriteOffset),
	SLD_ENTRY (Unit, SLDT_UINT8,  blinkCounter),
	SLD_ENTRY (Unit, SLDT_UINT8,  team),
	SLD_ENTRY (Unit, SLDT_UINT16, timer),
	SLD_ARRAY (Unit, SLDT_UINT8,  route, 14),
	SLD_END
};

static const SaveLoadDesc s_saveUnitNewIndex[] = {
	SLD_ENTRY (Object, SLDT_UINT16, index),
	SLD_END
};

static const SaveLoadDesc s_saveUnitNew[] = {
	SLD_ENTRY (Unit, SLDT_UINT16, fireDelay),
	SLD_ENTRY (Unit, SLDT_UINT8,  deviatedHouse),
	SLD_EMPTY (      SLDT_UINT8),
	SLD_EMPTY2(      SLDT_UINT16, 6),
	SLD_END
};

static uint32 SaveLoad_Unit_ExtraFlags(void *object, uint32 value, bool loading);

static const SaveLoadDesc s_saveUnit2[] = {
	SLD_ENTRY (Unit, SLDT_UINT16, o.index),
	SLD_CALLB (Unit, SLDT_UINT8,  permanentFollow,SaveLoad_Unit_ExtraFlags),
	SLD_ENTRY2(Unit, SLDT_UINT8,  squadID,        SLDT_UINT32),
	SLD_ENTRY2(Unit, SLDT_UINT8,  aiSquad,        SLDT_UINT32),
	SLD_END
};
assert_compile(sizeof(enum HouseType) == sizeof(uint32));
assert_compile(sizeof(enum SquadID) == sizeof(uint32));

/**
 * Load all Units from a file.
 * @param fp The file to load from.
 * @param length The length of the data chunk.
 * @return True if and only if all bytes were read successful.
 */
bool Unit_Load(FILE *fp, uint32 length)
{
	while (length > 0) {
		Unit *u;
		Unit ul;

		memset(&ul, 0, sizeof(ul));

		/* Read the next Unit from disk */
		if (!SaveLoad_Load(s_saveUnit, fp, &ul)) return false;

		length -= SaveLoad_GetLength(s_saveUnit);

		ul.o.script.scriptInfo = g_scriptUnit;
		ul.o.script.script = g_scriptUnit->start + (size_t)ul.o.script.script;
		ul.o.script.delay = 0;
		ul.timer = 0;
		ul.o.seenByHouses |= 1 << ul.o.houseID;

		/* In case the new ODUN chunk is not available, Ordos is always the one who deviated */
		if (ul.deviated != 0) ul.deviatedHouse = HOUSE_ORDOS;

		/* ENHANCEMENT -- Due to wrong parameter orders of Unit_Create in original Dune2,
		 *  it happened that units exists with houseID 13. This in fact are Trikes with
		 *  the wrong houseID. So remove those units completely from the savegame. */
		if (ul.o.houseID == 13) continue;

		/* Get the Unit from the pool */
		u = Unit_Get_ByIndex(ul.o.index);
		if (u == NULL) return false;

		/* Copy over the data */
		*u = ul;

		/* Extra data. */
		u->lastPosition = u->o.position;
		u->permanentFollow = false;
		u->detonateAtTarget = false;
		u->deviationDecremented = false;
		u->squadID = SQUADID_INVALID;
		u->aiSquad = SQUADID_INVALID;
	}
	if (length != 0) return false;

	Unit_Recount();

	return true;
}

/**
 * Save all Units to a file. It converts pointers to indices where needed.
 * @param fp The file to save to.
 * @return True if and only if all bytes were written successful.
 */
bool Unit_Save(FILE *fp)
{
	PoolFindStruct find;

	find.houseID = HOUSE_INVALID;
	find.type    = 0xFFFF;
	find.index   = 0xFFFF;

	while (true) {
		Unit *u;
		Unit su;

		u = Unit_Find(&find);
		if (u == NULL) break;
		su = *u;

		if (!SaveLoad_Save(s_saveUnit, fp, &su)) return false;
	}

	return true;
}

/**
 * Load all new information of Units from a file.
 * @param fp The file to load from.
 * @param length The length of the data chunk.
 * @return True if and only if all bytes were read successful.
 */
bool UnitNew_Load(FILE *fp, uint32 length)
{
	while (length > 0) {
		Unit *u;
		Object o;

		/* Read the next index from disk */
		if (!SaveLoad_Load(s_saveUnitNewIndex, fp, &o)) return false;

		length -= SaveLoad_GetLength(s_saveUnitNewIndex);

		/* Get the Unit from the pool */
		u = Unit_Get_ByIndex(o.index);
		if (u == NULL) return false;

		/* Read the "new" information for this unit */
		if (!SaveLoad_Load(s_saveUnitNew, fp, u)) return false;

		length -= SaveLoad_GetLength(s_saveUnitNew);
	}
	if (length != 0) return false;

	return true;
}

/**
 * Save all new Units information to a file. It converts pointers to indices
 *   where needed.
 * @param fp The file to save to.
 * @return True if and only if all bytes were written successful.
 */
bool UnitNew_Save(FILE *fp)
{
	PoolFindStruct find;

	find.houseID = HOUSE_INVALID;
	find.type    = 0xFFFF;
	find.index   = 0xFFFF;

	while (true) {
		Unit *u;
		Unit su;

		u = Unit_Find(&find);
		if (u == NULL) break;
		su = *u;

		if (!SaveLoad_Save(s_saveUnitNewIndex, fp, &su.o)) return false;
		if (!SaveLoad_Save(s_saveUnitNew, fp, &su)) return false;
	}

	return true;
}

/*--------------------------------------------------------------*/

static uint32
SaveLoad_Unit_ExtraFlags(void *object, uint32 value, bool loading)
{
	Unit *u = object;

	if (loading) {
		/* Note: lowest 3 bits used to store deviatedHouse.  That is now stored in the ODUN block. */
		u->permanentFollow  = (value & 0x80) ? true : false;
		u->detonateAtTarget = (value & 0x40) ? true : false;
		return 0;
	}
	else {
		value = 0;
		if (u->permanentFollow)  value |= 0x80;
		if (u->detonateAtTarget) value |= 0x40;
		return value;
	}
}

bool
Unit_Load2(FILE *fp, uint32 length)
{
	while (length > 0) {
		Unit ul;
		if (!SaveLoad_Load(s_saveUnit2, fp, &ul))
			return false;

		length -= SaveLoad_GetLength(s_saveUnit2);

		Unit *u = Unit_Get_ByIndex(ul.o.index);
		if (u == NULL)
			return false;

		/* Extra data. */
		u->permanentFollow = ul.permanentFollow;
		u->detonateAtTarget = ul.detonateAtTarget;
		u->squadID = ul.squadID;
		u->aiSquad = ul.aiSquad;
	}

	if (length != 0)
		return false;

	return true;
}

bool
Unit_Save2(FILE *fp)
{
	PoolFindStruct find;

	find.houseID = HOUSE_INVALID;
	find.type    = 0xFFFF;
	find.index   = 0xFFFF;

	while (true) {
		Unit *u = Unit_Find(&find);
		if (u == NULL)
			break;

		if (!SaveLoad_Save(s_saveUnit2, fp, u))
			return false;
	}

	return true;
}
