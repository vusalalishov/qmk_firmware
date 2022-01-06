#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
	_PROG,
};

enum {
	TD_COL_SEM,
};

// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
	     KC_ESC  , KC_Q , KC_W    , KC_E    , KC_R    , KC_T                 ,                     /**/                     KC_Y                 , KC_U    , KC_I    , KC_O   , KC_P           , KC_BSPC  ,
	     KC_TAB  , KC_A , KC_S    , KC_D    , KC_F    , KC_G                 ,                     /**/                     KC_H                 , KC_J    , KC_K    , KC_L   , TD(TD_COL_SEM) , CTL_QUOT ,
	     KC_LSFT , KC_Z , KC_X    , KC_C    , KC_V    , KC_B                 , KC_LBRC , KC_CAPS , /**/ KC_TRNS , KC_RBRC , KC_N                 , KC_M    , KC_COMM , KC_DOT , KC_SLSH        , KC_TRNS  ,
                          KC_TRNS , KC_TRNS , KC_TRNS , MT(MOD_LSFT, KC_ENT) , KC_LCMD           , /**/           KC_RALT , MT(MOD_RCTL, KC_SPC) , KC_TRNS , KC_TRNS , KC_APP
    ),

    [_PROG] = LAYOUT(
	     KC_ESC  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
	     KC_TAB , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,TD(TD_COL_SEM),CTL_QUOT,
	     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC,KC_CAPS,                     KC_TRNS  , KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                KC_TRNS , KC_TRNS, KC_TRNS, MT(MOD_LSFT, KC_ENT) ,KC_LCMD       ,     KC_RALT    , MT(MOD_RCTL, KC_SPC) ,KC_TRNS, KC_TRNS, KC_APP
    ),

};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Semicolon(;), twice for Colon(:)
    [TD_COL_SEM] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
};
