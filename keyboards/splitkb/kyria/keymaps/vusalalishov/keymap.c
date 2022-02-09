#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
	_WORKMAN,
	_DEV, 
	_NUM,
	_SYM,
};

enum {
	TD_QUOT_DOULE,
};

// Aliases for readability
#define QWERTY        DF(_QWERTY)
#define WORKMAN       DF(_WORKMAN)

#define MT_A_LSFT    MT(MOD_LSFT, KC_A)
#define MT_SCLN_RSFT MT(MOD_RSFT, KC_SCLN)
#define MT_CMD_SPC   MT(MOD_LGUI, KC_SPC)

#define MO_DEV       MO(_DEV)

#define LT_NUM_ENT       LT(_NUM, KC_ENT)
#define LT_SYM_F         LT(_SYM, KC_F)

// Tap dance
#define TD_QUOT      TD(TD_QUOT_DOULE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
	     KC_ESC  , KC_Q      , KC_W , KC_E    , KC_R     , KC_T    ,                      /**/                            KC_Y    , KC_U    , KC_I   , KC_O    , KC_P         , KC_BSPC ,
	     KC_TAB  , MT_A_LSFT , KC_S , KC_D    , LT_SYM_F , KC_G    ,                      /**/                            KC_H    , KC_J    , KC_K   , KC_L    , MT_SCLN_RSFT , TD_QUOT ,
	     KC_RGUI , KC_Z      , KC_X , KC_C    , KC_V     , KC_B    , XXXXXXX  , XXXXXXX , /**/ XXXXXXX    , XXXXXXX     , KC_N    , KC_M    , KC_DOT , KC_UNDS , _______      , XXXXXXX ,
                                      XXXXXXX , XXXXXXX  , KC_LALT , KC_LCTRL , MO_DEV  , /**/ LT_NUM_ENT , MT_CMD_SPC  , XXXXXXX , XXXXXXX , WORKMAN
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
	     XXXXXXX , XXXXXXX , KC_3    , KC_2    , KC_1    , XXXXXXX ,                     /**/                     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , _______ ,
	     XXXXXXX , KC_0    , KC_6    , KC_5    , KC_4    , XXXXXXX ,                     /**/                     KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , XXXXXXX , XXXXXXX ,
	     XXXXXXX , XXXXXXX , KC_9    , KC_8    , KC_7    , XXXXXXX , XXXXXXX , XXXXXXX , /**/ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX ,
                                       XXXXXXX , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______ , _______ , XXXXXXX
    ),

    [_SYM] = LAYOUT(
	     _______ , _______ , _______ , _______ , _______ , _______ ,                     /**/                     LGUI(KC_LEFT)  , KC_LCBR , KC_RCBR , KC_MINS , KC_SLSH , _______ ,
	     _______ , _______ , _______ , _______ , _______ , _______ ,                     /**/                     LGUI(KC_RIGHT) , KC_LPRN , KC_RPRN , KC_COMM , KC_COLN , _______ ,
	     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______        , KC_LBRC , KC_RBRC , _______ , _______ , _______ ,
                                       _______ , _______ , _______ , _______ , _______ , /**/ _______ , _______ , _______        , _______ , _______
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
	[TD_QUOT_DOULE] = ACTION_TAP_DANCE_DOUBLE(KC_DQUO, KC_QUOT),
};

