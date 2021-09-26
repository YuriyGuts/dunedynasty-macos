/** @file src/table/windowdesc.c WindowDesc file table. */

#include "enum_string.h"
#include "types.h"

#include "../gui/widget.h"
#include "../input/scancode.h"

WindowDesc g_optionsWindowDesc = {
	/* index       */ 16,
	/* stringID    */ STR_DUNE_II_THE_BATTLE_FOR_ARRAKIS,
	/* addArrows   */ false,
	/* widgetCount */ 7,
	{ /* widgets */
		{ /* 0 */
		/* stringID      */ STR_LOAD_A_GAME,
		/* offsetX       */ 16,
		/* offsetY       */ 23,
		/* width         */ 208,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 1 */
		/* stringID      */ STR_SAVE_THIS_GAME,
		/* offsetX       */ 16,
		/* offsetY       */ 40,
		/* width         */ 208,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 2 */
		/* stringID      */ STR_GAME_CONTROLS,
		/* offsetX       */ 16,
		/* offsetY       */ 57,
		/* width         */ 208,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 3 */
		/* stringID      */ STR_RESTART_SCENARIO,
		/* offsetX       */ 16,
		/* offsetY       */ 74,
		/* width         */ 208,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 4 */
		/* stringID      */ STR_PICK_ANOTHER_HOUSE,
		/* offsetX       */ 16,
		/* offsetY       */ 91,
		/* width         */ 208,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 5 */
		/* stringID      */ STR_CONTINUE_GAME,
		/* offsetX       */ 120,
		/* offsetY       */ 110,
		/* width         */ 104,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ SCANCODE_ESCAPE,
		},
		{ /* 6 */
		/* stringID      */ STR_QUIT_PLAYING,
		/* offsetX       */ 16,
		/* offsetY       */ 110,
		/* width         */ 104,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		}
	}
};

WindowDesc g_gameControlWindowDesc = {
	/* index       */ 16,
	/* stringID    */ STR_GAME_CONTROLS,
	/* addArrows   */ false,
	/* widgetCount */ 6,
	{ /* widgets */
		{ /* 0 */
		/* stringID      */ -10, /* Music state. */
		/* offsetX       */ 128, /* Was 152, but 128 matches v1.0. */
		/* offsetY       */ 22,
		/* width         */ 46,  /* Was 80. */
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 1 */
		/* stringID      */ -11, /* Sound state. */
		/* offsetX       */ 128, /* Was 152, but 128 matches v1.0. */
		/* offsetY       */ 39,
		/* width         */ 46,  /* Was 80. */
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 2 */
		/* stringID      */ -12, /* Game speed. */
		/* offsetX       */ 128, /* Was 152, but 128 matches v1.0. */
		/* offsetY       */ 56,
		/* width         */ 104, /* Was 80. */
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 3 */
		/* stringID      */ -13, /* Hints state */
		/* offsetX       */ 128, /* Was 152, but 128 matches v1.0. */
		/* offsetY       */ 73,
		/* width         */ 46,  /* Was 80. */
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 4 */
		/* stringID      */ -14, /* Subtitle state */
		/* offsetX       */ 128, /* Was 152, but 128 matches v1.0. */
		/* offsetY       */ 90,
		/* width         */ 46,  /* Was 80. */
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 5 */
		/* stringID      */ STR_PREVIOUS,
		/* offsetX       */ 96,
		/* offsetY       */ 110,
		/* width         */ 136,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ SCANCODE_ESCAPE,
		},
		{ /* 6 */
		/* stringID      */ STR_NULL,
		/* offsetX       */ 0,
		/* offsetY       */ 0,
		/* width         */ 0,
		/* height        */ 0,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		}
	}
};

WindowDesc g_yesNoWindowDesc = {
	/* index       */ 18,
	/* stringID    */ STR_ARE_YOU_SURE_YOU_WANT_TO_QUIT_PLAYING,
	/* addArrows   */ false,
	/* widgetCount */ 2,
	{ /* widgets */
		{ /* 0 */
		/* stringID      */ STR_YES,
		/* offsetX       */ 8,
		/* offsetY       */ 30,
		/* width         */ 72,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 1 */
		/* stringID      */ STR_NO,
		/* offsetX       */ 224,
		/* offsetY       */ 30,
		/* width         */ 72,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 2 */
		/* stringID      */ STR_NULL,
		/* offsetX       */ 0,
		/* offsetY       */ 0,
		/* width         */ 0,
		/* height        */ 0,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 3 */
		/* stringID      */ STR_NULL,
		/* offsetX       */ 0,
		/* offsetY       */ 0,
		/* width         */ 0,
		/* height        */ 0,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 4 */
		/* stringID      */ STR_NULL,
		/* offsetX       */ 0,
		/* offsetY       */ 0,
		/* width         */ 0,
		/* height        */ 0,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 5 */
		/* stringID      */ STR_NULL,
		/* offsetX       */ 0,
		/* offsetY       */ 0,
		/* width         */ 0,
		/* height        */ 0,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 6 */
		/* stringID      */ STR_NULL,
		/* offsetX       */ 0,
		/* offsetY       */ 0,
		/* width         */ 0,
		/* height        */ 0,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		}
	}
};

WindowDesc g_saveLoadWindowDesc = {
	/* index       */ 17,
	/* stringID    */ STR_SELECT_A_SAVED_GAME_TO_LOAD,
	/* addArrows   */ true,
	/* widgetCount */ 6,
	{ /* widgets */
		{ /* 0 */
		/* stringID      */ -1, /* First savegame name. */
		/* offsetX       */ 16,
		/* offsetY       */ 39,
		/* width         */ 256,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 1 */
		/* stringID      */ -2, /* Second savegame name. */
		/* offsetX       */ 16,
		/* offsetY       */ 56,
		/* width         */ 256,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 2 */
		/* stringID      */ -3, /* Third savegame name. */
		/* offsetX       */ 16,
		/* offsetY       */ 73,
		/* width         */ 256,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 3 */
		/* stringID      */ -4, /* Fourth savegame name. */
		/* offsetX       */ 16,
		/* offsetY       */ 90,
		/* width         */ 256,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 4 */
		/* stringID      */ -5, /* Fifth savegame name. */
		/* offsetX       */ 16,
		/* offsetY       */ 107,
		/* width         */ 256,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 5 */
		/* stringID      */ STR_CANCEL,
		/* offsetX       */ 176,
		/* offsetY       */ 126,
		/* width         */ 96,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ SCANCODE_ESCAPE,
		},
		{ /* 6 */
		/* stringID      */ STR_NULL,
		/* offsetX       */ 0,
		/* offsetY       */ 0,
		/* width         */ 0,
		/* height        */ 0,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		}
	}
};

WindowDesc g_savegameNameWindowDesc = {
	/* index       */ 14,
	/* stringID    */ STR_ENTER_A_DESCRIPTION_OF_YOUR_SAVED_GAME,
	/* addArrows   */ false,
	/* widgetCount */ 2,
	{ /* widgets */
		{ /* 0 */
		/* stringID      */ STR_SAVE,
		/* offsetX       */ 8,
		/* offsetY       */ 38,
		/* width         */ 72,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ SCANCODE_ENTER,
		},
		{ /* 1 */
		/* stringID      */ STR_CANCEL,
		/* offsetX       */ 208,
		/* offsetY       */ 38,
		/* width         */ 72,
		/* height        */ 15,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ SCANCODE_ESCAPE,
		},
		{ /* 2 */
		/* stringID      */ STR_NULL,
		/* offsetX       */ 0,
		/* offsetY       */ 0,
		/* width         */ 0,
		/* height        */ 0,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 3 */
		/* stringID      */ STR_NULL,
		/* offsetX       */ 0,
		/* offsetY       */ 0,
		/* width         */ 0,
		/* height        */ 0,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 4 */
		/* stringID      */ STR_NULL,
		/* offsetX       */ 0,
		/* offsetY       */ 0,
		/* width         */ 0,
		/* height        */ 0,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 5 */
		/* stringID      */ STR_NULL,
		/* offsetX       */ 0,
		/* offsetY       */ 0,
		/* width         */ 0,
		/* height        */ 0,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		},
		{ /* 6 */
		/* stringID      */ STR_NULL,
		/* offsetX       */ 0,
		/* offsetY       */ 0,
		/* width         */ 0,
		/* height        */ 0,
		/* labelStringID */ STR_NULL,
		/* shortcut2     */ 0,
		}
	}
};
