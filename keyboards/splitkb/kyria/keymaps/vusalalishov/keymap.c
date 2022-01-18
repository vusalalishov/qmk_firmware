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

#define MT_CMD_SPC   MT(MOD_LGUI, KC_SPC)
#define MT_SFT_ENT   MT(MOD_LSFT, KC_ENT)

#define MO_DEV       MO(_DEV)
#define MO_NUM       MO(_NUM)

#define MT_ALT_PRN   MT(MOD_LALT, KC_LPRN)
#define MT_CTRL_PRN  MT(MOD_LCTL, KC_RPRN)

// Tap dance
#define TD_DOT       TD(TD_DOT_COMM)
#define TD_UNDS      TD(TD_UNDS_MIN)
#define TD_COL       TD(TD_COL_SEM)
#define TD_QUOT      TD(TD_QUOT_DOULE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
	     KC_ESC  , KC_Q , KC_W , KC_E    , KC_R    , KC_T    ,                           /**/                            KC_Y    , KC_U    , KC_I   , KC_O    , KC_P    , KC_BSPC ,
	     KC_TAB  , KC_A , KC_S , KC_D    , KC_F    , KC_G    ,                           /**/                            KC_H    , KC_J    , KC_K   , KC_L    , TD_COL  , TD_QUOT ,
	     KC_RGUI , KC_Z , KC_X , KC_C    , KC_V    , KC_B    , MO_DEV     , KC_LCBR    , /**/ KC_RCBR , MO_NUM         , KC_N    , KC_M    , TD_DOT , TD_UNDS , KC_SLSH , XXXXXXX ,
                                 XXXXXXX , XXXXXXX , KC_LBRC , MT_CMD_SPC , MT_ALT_PRN , /**/ MT_CTRL_PRN , MT_SFT_ENT , KC_RBRC , XXXXXXX , XXXXXXX
    ),

    [_DEV] = LAYOUT(
	     XXXXXXX , XXXXXXX , KC_HASH , KC_AT   , KC_EXLM , XXXXXXX ,                     /**/                     XXXXXXX , KC_LT   , KC_GT   , KC_GRV  , XXXXXXX , _______ ,
	     XXXXXXX , XXXXXXX , KC_CIRC , KC_PERC , KC_DLR  , XXXXXXX ,                     /**/                     XXXXXXX , KC_QUES , KC_PLUS , KC_EQL  , XXXXXXX , XXXXXXX ,
	     XXXXXXX , XXXXXXX , KC_TILD , KC_ASTR , KC_AMPR , XXXXXXX , XXXXXXX , XXXXXXX , /**/ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PIPE , KC_BSLS , XXXXXXX , XXXXXXX ,
                                       XXXXXXX , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , XXXXXXX
    ),

    [_NUM] = LAYOUT(
	     XXXXXXX , XXXXXXX , KC_3    , KC_2    , KC_1    , XXXXXXX ,                     /**/                     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , _______ ,
	     XXXXXXX , KC_0    , KC_6    , KC_5    , KC_4    , XXXXXXX ,                     /**/                     KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , XXXXXXX , XXXXXXX ,
	     XXXXXXX , XXXXXXX , KC_9    , KC_8    , KC_7    , XXXXXXX , XXXXXXX , XXXXXXX , /**/ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX ,
                                       XXXXXXX , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , XXXXXXX
    ),


    // [_LAYER] = LAYOUT(
	//      _______ , _______ , _______ , _______ , _______ , _______ ,                     /**/           _______ , _______ , _______ , _______ , _______ , _______ ,
	//      _______ , _______ , _______ , _______ , _______ , _______ ,                     /**/           _______ , _______ , _______ , _______ , _______ , _______ ,
	//      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    //                                    _______ , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , _______
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
		case LALT_T(KC_LPRN):
			if (record->tap.count && record->event.pressed) {
				tap_code16(KC_LPRN);
				return false;
			}
			break;
		case LCTL_T(KC_RPRN):
			if (record->tap.count && record->event.pressed) {
				tap_code16(KC_RPRN);
				return false;
			}
			break;
		default:
			return true;
	}
	return true;
}

