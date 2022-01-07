#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
	_SYM,
	_NUM,
};

enum {
	TD_COL_SEM,
	TD_QUOT_DOULE
};

// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define TD_QUOT TD(KC_DQUO, KC_QUOTE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
	     KC_ESC  , KC_Q , KC_W    , KC_E    , KC_R    , KC_T                 ,                      /**/                                             KC_Y    , KC_U    , KC_I    , KC_O   , KC_P           , KC_BSPC            ,
	     KC_TAB  , KC_A , KC_S    , KC_D    , KC_F    , KC_G                 ,                      /**/                                             KC_H    , KC_J    , KC_K    , KC_L   , TD(TD_COL_SEM) , TD(TD_QUOT_DOULE)  ,
	     KC_LSFT , KC_Z , KC_X    , KC_C    , KC_V    , KC_B    , KC_LBRC              , KC_CAPS  , /**/           KC_TRNS  , KC_RBRC              , KC_N    , KC_M    , KC_COMM , KC_DOT , KC_SLSH        , KC_TRNS            ,
                                    KC_TRNS , KC_TRNS , KC_LCMD , MT(MOD_LSFT, KC_ENT) , MO(_SYM) , /**/           MO(_NUM) , MT(MOD_RCTL, KC_SPC) , KC_RALT , KC_TRNS , KC_APP
    ),

    [_SYM] = LAYOUT(
	     _______ , _______ , KC_GRV  , KC_AT   , KC_DLR  , KC_ASTR                 ,                /**/                               KC_LT   , KC_LCBR , KC_RCBR , KC_EQL  , KC_UNDS , _______ ,
	     _______ , _______ , KC_TILD , KC_CIRC , KC_HASH , _______                 ,                /**/                               KC_GT   , KC_LPRN , KC_RPRN , KC_PLUS , KC_MINS , _______ ,
	     _______ , _______ , KC_AMPR , KC_PIPE , KC_PERC , _______ , _______ , _______ ,            /**/           _______ , _______ , KC_EXLM , KC_LBRC , KC_RBRC , KC_QUES , KC_BSLS , _______ ,
                                       _______ , _______ , _______ , _______ , _______ ,            /**/           _______ , _______ , _______ , _______ , _______
    ),

    [_NUM] = LAYOUT(
	     _______ , _______ , KC_0    , KC_3    , KC_2    , KC_1                    ,                /**/                               _______ , _______ , _______ , _______ , _______ , _______ ,
	     _______ , _______ , _______ , KC_6    , KC_5    , KC_4                    ,                /**/                               _______ , _______ , _______ , _______ , _______ , _______ ,
	     _______ , _______ , _______ , KC_9    , KC_8    , KC_7    , _______ , _______ ,            /**/           _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                                       _______ , _______ , _______ , _______ , _______ ,            /**/           _______ , _______ , _______ , _______ , _______
    ),


    // [_LAYER] = LAYOUT(
	//      _______ , _______ , _______ , _______ , _______ , _______                 ,                /**/                               _______ , _______ , _______ , _______ , _______ , _______ ,
	//      _______ , _______ , _______ , _______ , _______ , _______                 ,                /**/                               _______ , _______ , _______ , _______ , _______ , _______ ,
	//      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,            /**/           _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    //                                    _______ , _______ , _______ , _______ , _______ ,            /**/           _______ , _______ , _______ , _______ , _______
    // ),
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_COL_SEM] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
	[TD_QUOT_DOULE] = ACTION_TAP_DANCE_DOUBLE(KC_DQUO, KC_QUOT),
};
