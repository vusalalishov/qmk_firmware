#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
	_WORKMAN,
	_DEV_LEFT, 
	_DEV_RIGHT, 
	_NUM,
	_SYM,
	_FUNC,
	_NAV,
};

// Aliases for readability
#define QWERTY        DF(_QWERTY)
#define WORKMAN       DF(_WORKMAN)

#define MT_CMD_SPC   MT(MOD_LGUI, KC_SPC)

#define MO_DEV       MO(_DEV)
#define MO_NUM       MO(_NUM)

#define LT_SYM_F            LT(_SYM, KC_F)
#define LT_NUM_A            LT(_NUM, KC_A)
#define LT_NAV_S            LT(_NAV, KC_S)
#define LT_DEV_D            LT(_DEV_RIGHT, KC_D)
#define LT_DEV_SCLN         LT(_DEV_LEFT, KC_SCLN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
	     KC_ESC  , KC_Q     , KC_W     , KC_E       , KC_R     , KC_T    ,                      /**/                        KC_Y    , KC_U    , KC_I   , KC_O    , KC_P        , KC_BSPC ,
	     KC_TAB  , LT_NUM_A , LT_NAV_S , LT_DEV_D   , LT_SYM_F , KC_G    ,                      /**/                        KC_H    , KC_J    , KC_K   , KC_L    , LT_DEV_SCLN , KC_QUOT ,
	     KC_RALT , KC_Z     , KC_X     , KC_C       , KC_V     , KC_B    , XXXXXXX  , XXXXXXX , /**/ XXXXXXX , XXXXXXX    , KC_N    , KC_M    , KC_DOT , KC_UNDS , KC_SLSH     , XXXXXXX ,
                                         KC_KB_MUTE , XXXXXXX  , KC_LALT , KC_LCTRL , KC_LSFT , /**/ KC_ENT  , MT_CMD_SPC , XXXXXXX , XXXXXXX , WORKMAN
    ),

    [_WORKMAN] = LAYOUT(
	     _______ , KC_Q , KC_D , KC_R    , KC_W    , KC_B    ,                     /**/                     KC_J    , KC_F    , KC_U    , KC_P    , KC_SCLN , KC_BSPC ,
	     _______ , KC_A , KC_S , KC_H    , KC_T    , KC_G    ,                     /**/                     KC_Y    , KC_N    , KC_E    , KC_O    , KC_I    , KC_DQUO ,
	     _______ , KC_Z , KC_X , KC_M    , KC_C    , KC_V    , _______ , _______ , /**/ _______ , _______ , KC_K    , KC_L    , _______ , _______ , _______ , _______ ,
                                 _______ , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , QWERTY
    ),

    [_DEV_LEFT] = LAYOUT(
	     XXXXXXX , XXXXXXX , KC_HASH , KC_AT   , KC_EXLM , XXXXXXX ,                     /**/                     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
	     XXXXXXX , KC_TILD , KC_CIRC , KC_PERC , KC_DLR  , XXXXXXX ,                     /**/                     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
	     XXXXXXX , XXXXXXX , XXXXXXX , KC_ASTR , KC_AMPR , XXXXXXX , XXXXXXX , XXXXXXX , /**/ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                                       XXXXXXX , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , XXXXXXX
    ),

    [_DEV_RIGHT] = LAYOUT(
	     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                     /**/                     KC_PIPE , KC_LT   , KC_GT   , KC_GRV  , XXXXXXX , _______ ,
	     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                     /**/                     KC_BSLS , KC_QUES , KC_PLUS , KC_EQL  , XXXXXXX , XXXXXXX ,
	     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , /**/ XXXXXXX , XXXXXXX , XXXXXXX , KC_EXLM , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                                       XXXXXXX , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , XXXXXXX
    ),

    [_NUM] = LAYOUT(
	     _______ , _______ , _______ , _______ , _______ , _______ ,                     /**/                     KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , _______ ,
	     _______ , _______ , _______ , _______ , _______ , _______ ,                     /**/                     KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______ ,
	     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                                       _______ , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , _______
    ),

    [_NAV] = LAYOUT(
	     _______ , _______ , _______ , _______ , _______ , _______ ,                     /**/                     _______ , _______ , _______ , _______  , _______ , _______ ,
	     _______ , _______ , _______ , _______ , _______ , _______ ,                     /**/                     KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , _______ , _______ ,
	     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ ,
                                       _______ , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , _______
    ),

    [_FUNC] = LAYOUT(
	     _______ , _______ , _______ , _______ , _______ , _______ ,                     /**/                     _______ , KC_F1   , KC_F2 , KC_F3 , KC_F10 , _______ ,
	     _______ , _______ , _______ , _______ , _______ , _______ ,                     /**/                     _______ , KC_F4   , KC_F5 , KC_F6 , KC_F11 , _______ ,
	     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , KC_F7   , KC_F8 , KC_F9 , KC_F12 , _______ ,
                                       _______ , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , _______
    ),

    [_SYM] = LAYOUT(
	     _______ , _______ , _______ , _______ , _______ , _______ ,                     /**/                     LGUI(KC_LEFT)  , KC_LCBR , KC_RCBR , KC_MINS , KC_SLSH , _______ ,
	     _______ , _______ , _______ , _______ , _______ , _______ ,                     /**/                     LGUI(KC_RIGHT) , KC_LPRN , KC_RPRN , KC_COMM , KC_COLN , _______ ,
	     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , /**/ _______ , _______ , LGUI(KC_GRV)   , KC_LBRC , KC_RBRC , _______ , _______ , _______ ,
                                       _______ , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______        , _______ , _______
    ),

    // [_LAYER] = LAYOUT(
	//      _______ , _______ , _______ , _______ , _______ , _______ ,                     /**/           _______ , _______ , _______ , _______ , _______ , _______ ,
	//      _______ , _______ , _______ , _______ , _______ , _______ ,                     /**/           _______ , _______ , _______ , _______ , _______ , _______ ,
	//      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    //                                    _______ , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , _______
    // ),
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }
bool oled_task_user(void) {
    if (is_keyboard_master()) {
		oled_write_P(PSTR("Primary here!\n\n"), false);
    } else {
        oled_write_P(PSTR("Secondary here!\n\n"), false);
    }
    return false;
}
#endif

