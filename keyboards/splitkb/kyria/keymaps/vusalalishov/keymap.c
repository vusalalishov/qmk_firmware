#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
	_SYM,
	_NUM,
};

enum {
	TD_COL_SEM,
	TD_QUOT_DOULE,
	TD_DOT_COMM,
	TD_SLSH_BCKSLH,
	TD_UNDS_MIN,
	TD_P_PIPE
};

// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define TD_QUOT TD(KC_DQUO, KC_QUOTE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
	     KC_ESC  , KC_Q , KC_W    , KC_E    , KC_R    , KC_T                 ,                      /**/                                             KC_Y    , KC_U    , KC_I            , KC_O               , TD(TD_P_PIPE)      , KC_BSPC           ,
	     KC_TAB  , KC_A , KC_S    , KC_D    , KC_F    , KC_G                 ,                      /**/                                             KC_H    , KC_J    , KC_K            , KC_L               , TD(TD_COL_SEM)     , TD(TD_QUOT_DOULE) ,
	     KC_LSFT , KC_Z , KC_X    , KC_C    , KC_V    , KC_B    , KC_LBRC              , KC_CAPS  , /**/           KC_TRNS  , KC_RBRC              , KC_N    , KC_M    , TD(TD_DOT_COMM) , TD(TD_UNDS_MIN)    , TD(TD_SLSH_BCKSLH) , KC_TRNS           ,
                                    KC_TRNS , KC_TRNS , KC_LCMD , MT(MOD_LSFT, KC_ENT) , MO(_SYM) , /**/           MO(_NUM) , MT(MOD_RCTL, KC_SPC) , KC_RALT , KC_TRNS , KC_APP
    ),

    [_SYM] = LAYOUT(
	     _______ , KC_GRV  , KC_HASH , KC_AT   , KC_EXLM , _______                  ,                /**/                               _______ , KC_LCBR , KC_RCBR , KC_LT   , KC_GT   , _______ ,
	     _______ , _______ , KC_CIRC , KC_PERC , KC_DLR  , _______                  ,                /**/                               _______ , KC_LPRN , KC_RPRN , KC_QUES , KC_PLUS , _______ ,
	     _______ , _______ , KC_TILD , KC_ASTR , KC_AMPR , _______ , _______ , _______ ,             /**/           _______ , _______ , _______ , KC_LBRC , KC_RBRC , KC_EQL  , _______ , _______ ,
                                       _______ , _______ , _______ , _______ , _______ ,             /**/           _______ , _______ , _______ , _______ , _______
    ),

    [_NUM] = LAYOUT(
	     _______ , KC_0    , KC_3    , KC_2    , KC_1, _______                     ,                /**/                               _______ , _______ , _______ , _______  , _______ , _______ ,
	     _______ , _______ , KC_6    , KC_5    , KC_4, _______                     ,                /**/                               KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , _______ , _______ ,
	     _______ , _______ , KC_9    , KC_8    , KC_7, _______     , _______ , _______ ,            /**/           _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ ,
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
	[TD_DOT_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMM),
	[TD_SLSH_BCKSLH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
	[TD_UNDS_MIN] = ACTION_TAP_DANCE_DOUBLE(KC_UNDS, KC_MINS),
	[TD_P_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_PIPE),
};
