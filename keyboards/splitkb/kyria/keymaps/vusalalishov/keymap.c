#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
	_DEV, 
	_NUM,
};

enum {
	TD_COL_SEM,
	TD_QUOT_DOULE,
	TD_DOT_COMM,
	TD_UNDS_MIN,
};

// Aliases for readability
#define QWERTY       DF(_QWERTY)
#define MT_LALT_LBRC MT(MOD_LALT, KC_LBRC)
#define MT_LCMD_PRN  MT(MOD_LGUI, KC_LPRN)
#define MT_LSFT_CRB  MT(MOD_LSFT, KC_LCBR)
#define LT_DEV_ENT   LT(_DEV, KC_ENT)
#define LT_NUM_SPC   LT(_NUM, KC_SPC)
#define MT_RSFT_CBR  MT(MOD_RSFT, KC_RCBR)
#define MT_RCTL_PRN  MT(MOD_RCTL, KC_RPRN)
#define MT_RALT_BRC  MT(MOD_RALT, KC_RBRC)
#define TD_DOT       TD(TD_DOT_COMM)
#define TD_UNDS      TD(TD_UNDS_MIN)
#define TD_COL       TD(TD_COL_SEM)
#define TD_QUOT      TD(TD_QUOT_DOULE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
	     KC_ESC , KC_Q , KC_W , KC_E    , KC_R         , KC_T        ,                              /**/                                      KC_Y        , KC_U        , KC_I   , KC_O    , KC_P    , KC_BSPC ,
	     KC_TAB , KC_A , KC_S , KC_D    , KC_F         , KC_G        ,                              /**/                                      KC_H        , KC_J        , KC_K   , KC_L    , TD_COL  , TD_QUOT ,
	     KC_NUM , KC_Z , KC_X , KC_C    , KC_V         , KC_B        , XXXXXXX     , XXXXXXX    ,   /**/           KC_PIPE    , KC_BSLS     , KC_N        , KC_M        , TD_DOT , TD_UNDS , KC_SLSH , XXXXXXX ,
                                XXXXXXX , MT_LALT_LBRC , MT_LCMD_PRN , MT_LSFT_CRB , LT_DEV_ENT ,   /**/           LT_NUM_SPC , MT_RSFT_CBR , MT_RCTL_PRN , MT_RALT_BRC , XXXXXXX
    ),

    [_DEV] = LAYOUT(
	     XXXXXXX , XXXXXXX , KC_HASH , KC_AT   , KC_EXLM , XXXXXXX ,                                 /**/                               XXXXXXX , KC_LT   , KC_GT   , KC_GRV  , XXXXXXX , _______ ,
	     XXXXXXX , XXXXXXX , KC_CIRC , KC_PERC , KC_DLR  , XXXXXXX ,                                 /**/                               XXXXXXX , KC_QUES , KC_PLUS , KC_EQL  , XXXXXXX , XXXXXXX ,
	     XXXXXXX , XXXXXXX , KC_TILD , KC_ASTR , KC_AMPR , XXXXXXX , XXXXXXX , XXXXXXX ,             /**/           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                                       XXXXXXX , _______ , _______ , _______ , _______ ,             /**/           _______ , _______ , _______ , _______ , XXXXXXX
    ),

    [_NUM] = LAYOUT(
	     XXXXXXX , XXXXXXX , KC_3    , KC_2    , KC_1    , XXXXXXX ,                                 /**/                               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , _______ ,
	     XXXXXXX , KC_0    , KC_6    , KC_5    , KC_4    , XXXXXXX ,                                 /**/                               KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , XXXXXXX , XXXXXXX ,
	     XXXXXXX , XXXXXXX , KC_9    , KC_8    , KC_7    , XXXXXXX , XXXXXXX , XXXXXXX ,             /**/           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX ,
                                       XXXXXXX , _______ , _______ , _______ , _______ ,             /**/           _______ , _______ , _______ , _______ , XXXXXXX
    ),


    // [_LAYER] = LAYOUT(
	//      _______ , _______ , _______ , _______ , _______ , _______ ,                                /**/                               _______ , _______ , _______ , _______ , _______ , _______ ,
	//      _______ , _______ , _______ , _______ , _______ , _______ ,                                /**/                               _______ , _______ , _______ , _______ , _______ , _______ ,
	//      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,            /**/           _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    //                                    _______ , _______ , _______ , _______ , _______ ,            /**/           _______ , _______ , _______ , _______ , _______
    // ),
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_COL_SEM] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
	[TD_QUOT_DOULE] = ACTION_TAP_DANCE_DOUBLE(KC_DQUO, KC_QUOT),
	[TD_DOT_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMM),
	[TD_UNDS_MIN] = ACTION_TAP_DANCE_DOUBLE(KC_UNDS, KC_MINS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case LALT_T(KC_LBRC):
			if (record->tap.count && record->event.pressed) {
				tap_code16(KC_LBRC);
				return false;
			}
			break;
		case LGUI_T(KC_LPRN):
			if (record->tap.count && record->event.pressed) {
				tap_code16(KC_LPRN);
				return false;
			}
			break;
		case LSFT_T(KC_LCBR):
			if (record->tap.count && record->event.pressed) {
				tap_code16(KC_LCBR);
				return false;
			}
			break;
		case RALT_T(KC_RBRC):
			if (record->tap.count && record->event.pressed) {
				tap_code16(KC_RBRC);
				return false;
			}
			break;
		case RCTL_T(KC_RPRN):
			if (record->tap.count && record->event.pressed) {
				tap_code16(KC_RPRN);
				return false;
			}
			break;
		case RSFT_T(KC_RCBR):
			if (record->tap.count && record->event.pressed) {
				tap_code16(KC_RCBR);
				return false;
			}
			break;
		default:
			return true;
	}
	return true;
}

