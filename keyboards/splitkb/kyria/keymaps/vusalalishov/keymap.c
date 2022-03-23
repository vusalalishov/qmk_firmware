#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
	_WORKMAN,
	_DEV, 
	_NUM,
	_SYM,
	_FUNC,
};

// Aliases for readability
#define QWERTY        DF(_QWERTY)
#define WORKMAN       DF(_WORKMAN)

#define MT_CMD_SPC   MT(MOD_LGUI, KC_SPC)

#define MO_DEV       MO(_DEV)
#define MO_NUM       MO(_NUM)

#define LT_DEV_ENT       LT(_DEV, KC_ENT)
#define LT_SYM_F         LT(_SYM, KC_F)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
	     KC_ESC  , KC_Q , KC_W , KC_E    , KC_R     , KC_T    ,                      /**/                           KC_Y   , KC_U    , KC_I   , KC_O    , KC_P    , KC_BSPC ,
	     KC_TAB  , KC_A , KC_S , KC_D    , LT_SYM_F , KC_G    ,                      /**/                           KC_H   , KC_J    , KC_K   , KC_L    , KC_SCLN , KC_QUOT ,
	     KC_RALT , KC_Z , KC_X , KC_C    , KC_V     , KC_B    , XXXXXXX  , XXXXXXX , /**/ XXXXXXX    , XXXXXXX    , KC_N   , KC_M    , KC_DOT , KC_UNDS , KC_SLSH , XXXXXXX ,
                                 XXXXXXX , XXXXXXX  , KC_LSFT , KC_LCTRL , MO_DEV  , /**/ LT_DEV_ENT , MT_CMD_SPC , MO_NUM , KC_LALT , WORKMAN
    ),

    [_WORKMAN] = LAYOUT(
	     _______ , KC_Q , KC_D , KC_R    , KC_W    , KC_B    ,                     /**/                     KC_J    , KC_F    , KC_U    , KC_P    , KC_SCLN , KC_BSPC ,
	     _______ , KC_A , KC_S , KC_H    , KC_T    , KC_G    ,                     /**/                     KC_Y    , KC_N    , KC_E    , KC_O    , KC_I    , KC_QUOT ,
	     _______ , KC_Z , KC_X , KC_M    , KC_C    , KC_V    , _______ , _______ , /**/ _______ , _______ , KC_K    , KC_L    , _______ , _______ , _______ , _______ ,
                                 _______ , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , QWERTY
    ),

    [_DEV] = LAYOUT(
	     XXXXXXX , XXXXXXX , KC_HASH , KC_AT   , KC_EXLM , XXXXXXX ,                     /**/                     KC_PIPE , KC_LT   , KC_GT   , KC_GRV  , XXXXXXX , _______ ,
	     XXXXXXX , KC_TILD , KC_CIRC , KC_PERC , KC_DLR  , XXXXXXX ,                     /**/                     KC_BSLS , KC_QUES , KC_PLUS , KC_EQL  , XXXXXXX , XXXXXXX ,
	     XXXXXXX , XXXXXXX , XXXXXXX , KC_ASTR , KC_AMPR , XXXXXXX , XXXXXXX , XXXXXXX , /**/ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                                       XXXXXXX , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , XXXXXXX
    ),

    [_NUM] = LAYOUT(
	     _______ , _______ , _______ , _______ , _______ , _______  ,                     /**/                     _______ , KC_1   , KC_2 , KC_3 , KC_0    , _______ ,
	     _______ , _______ , KC_LEFT , KC_UP   , KC_DOWN , KC_RIGHT ,                     /**/                     _______ , KC_4   , KC_5 , KC_6 , _______ , _______ ,
	     _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ , /**/ _______ , _______ , _______ , KC_7   , KC_8 , KC_9 , _______ , _______ ,
                                       _______ , _______ , _______  , _______ , _______ , /**/ _______ , _______ , _______ , _______ , _______
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

