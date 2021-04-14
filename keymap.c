#include QMK_KEYBOARD_H

/* Activates layer 1 when held, otherwise caps lock */
#define CAPS_MO LT(1, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  LAYOUT_all(
    KC_ESC    ,           KC_F1   , KC_F2   , KC_F3  , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8    , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,                     KC_PGUP ,
    KC_GRV    ,           KC_1    , KC_2    , KC_3   , KC_4    , KC_5    , KC_6    , KC_7    , KC_8     , KC_9    , KC_0    , KC_MINS , KC_EQL  , KC_GRV  , KC_BSPC , KC_INS ,
    KC_TAB    ,           KC_Q    , KC_W    , KC_E   , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I     , KC_O    , KC_P    , KC_LBRC , KC_RBRC ,           KC_BSLS , KC_DEL  ,
    CAPS_MO   ,           KC_A    , KC_S    , KC_D   , KC_F    , KC_G    , KC_H    , KC_J    , KC_K     , KC_L    , KC_SCLN , KC_QUOT , KC_ENT  ,                     KC_PGDN ,
    KC_LSFT   , KC_NUBS , KC_Z    , KC_X    , KC_C   , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM  , KC_DOT  , KC_SLSH , KC_RSFT ,                     KC_UP   ,
    KC_LCTL   , KC_LGUI , KC_LALT ,                               KC_SPC ,                                MO(1)   , KC_RCTL ,                     KC_LEFT , KC_DOWN , KC_RGHT
  ),

  LAYOUT_all(
    KC_TRNS ,           KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , DEBUG   , EEPROM_RESET ,                     RESET   ,
    KC_TRNS ,           KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS      , KC_TRNS , KC_DEL  , KC_TRNS ,
    KC_TRNS ,           KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS      ,           KC_TRNS , KC_TRNS ,
    KC_TRNS ,           KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS      ,                     KC_TRNS ,
    KC_TRNS , KC_TRNS , KC_TRNS , KC_DEL  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                          BL_INC  ,
    KC_TRNS , KC_TRNS , KC_TRNS ,                               KC_TRNS ,                               KC_TRNS , KC_TRNS ,                          KC_TRNS , BL_DEC  , KC_TRNS
  ),

};


void keyboard_post_init_user(void) {
  backlight_disable();
}


layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case 1:
      backlight_enable();
      break;

    default:
      backlight_disable();
      break;
  }

  return state;
}


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CAPS_MO:
      return true;
    default:
      return false;
  }
}
