#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "led.h"
#include "keymap_extras/keymap_neo2.h"

// Layer names
#define BASE 0      // default layer
#define PMQ  1      // poor man’s QWERTZ
#define PMN  2      // poor man’s Neo
#define FMU  3      // FMU layer
#define NHL  4      // Neo’s software layer 4 rebuilt in Hardware


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0: default
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  TAB  │  1  │  2  │  3  │  4  │  5  │  `  │     │  ´  │  6  │  7  │  8  │  9  │  0  │ BKSPC │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │   Y   │  X  │  V  │  L  │  C  │  W  │ HOM │     │ END │  K  │  H  │  G  │  F  │  Q  │  ß    │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤  E  │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │ Mod3  │  U  │  I  │  A  │  E  │  O  ├─────┤     ├─────┤  S  │  N  │  R  │  T  │  D  │ Mod3  │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤ TL2 │     │ TL3 ├─────╄─────╃─────┼─────┼─────┼───────┤
 * │ LSHFT │  Ü  │  Ö  │  Ä  │  P  │  Z  │     │     │     │  B  │  M  │  ,  │  .  │  J  │ Shift │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │ CTL │ ALT │ MO1 │ Win │ Mod4│                             │ Mod4│ Win │ MO1 │ ALT │ CTL │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │  ←  │  ↑  │ │  ↓  │  →  │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │  ─  │ │  ─  │     │     │
 *                             │ SPC │ RTN ├─────┤ ├─────┤ RTN │ SPC │
 *                             │     │     │ HYP │ │ MEH │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
[BASE] = LAYOUT_ergodox(
        // left hand
        KC_TAB,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   NE_GRV,
        NE_Y,      NE_X,  NE_V,  NE_L,  NE_C,  NE_W,  KC_HOME,
        NE_L3L,   NE_U,  NE_I,  NE_A,  NE_E,  NE_O,
        KC_LSFT,    NE_UDIA, NE_ODIA, NE_ADIA, NE_P,  NE_Z,  TG(PMQ),
        KC_LCTL,    KC_LALT,MO(FMU),KC_LGUI,NE_L4L,
                                                    KC_LEFT,    KC_UP,
                                                                KC_MINS,
                                            KC_SPC, KC_ENT,    ALL_T(KC_NO),
        // right hand
        NE_ACUT,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSPC,
        KC_END,     NE_K,  NE_H,  NE_G,  NE_F,  NE_Q,  NE_SS,
                    NE_S,  NE_N,  NE_R,  NE_T,  NE_D,  NE_L3R,
        TG(PMN),    NE_B,  NE_M,  KC_COMM,KC_DOT, NE_J,  KC_RSFT,
                            NE_L4R,KC_RGUI,MO(FMU),KC_LALT,KC_RCTL,
        KC_DOWN,    KC_RGHT,
        KC_MINS,
        MEH_T(KC_NO),KC_ENT,KC_SPC
    ),

/* Layer 1: poor man’s QWERTZ
 * based on kaimi’s layout
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  TAB  │  1  │  2  │  3  │  4  │  5  │  `  │     │  ´  │  6  │  7  │  8  │  9  │  0  │ BKSPC │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │   C   │  P  │  T  │  F  │  K  │  L  │ HOM │     │ END │  B  │  A  │  S  │  G  │  V  │  Y    │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤  E  │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │ Mod3  │  D  │  H  │  Ö  │  O  │  I  ├─────┤     ├─────┤  U  │  -  │  Z  │  E  │  X  │ Mod3  │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤(TL2)│     │(TL3)├─────╄─────╃─────┼─────┼─────┼───────┤
 * │ LSHFT │  Ä  │  Q  │  R  │  W  │  N  │     │     │     │  J  │  M  │  ,  │  .  │  ẞ  │ Shift │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │ CTL │ ALT │ MO1 │ Win │ MO4 │                             │ M04 │ Win │ MO1 │ ALT │ CTL │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │  ←  │  ↑  │ │  ↓  │  →  │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │  ─  │ │  ─  │     │     │
 *                             │ SPC │ RTN ├─────┤ ├─────┤ RTN │ SPC │
 *                             │     │     │ HYP │ │ MEH │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
[PMQ] = LAYOUT_ergodox(
        // left hand
        KC_TAB,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_EQL,
        DE_C,       DE_P,   DE_T,   DE_F,   DE_K,   DE_L,   KC_HOME,
        NE_L3L,   DE_D,   DE_H,   DE_ODIA,DE_O,   DE_I,
        KC_LSFT,    DE_ADIA,DE_Q,   DE_R,   DE_W,   DE_N,   KC_TRNS,
        KC_LCTL,    KC_LALT,MO(FMU),KC_LGUI,MO(NHL),
                                                    KC_LEFT,    KC_UP,
                                                                KC_MINS,
                                            KC_SPC, KC_ENT,    ALL_T(KC_NO),
        // right hand
        DE_ACUT,    KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSPC,
        KC_END,     DE_B,   DE_A,   DE_S,   DE_G,   DE_V,   DE_Y,
                    DE_U,   DE_MINS,DE_Z,   DE_E,   DE_X,   NE_L3R,
        KC_TRNS,    DE_J,   DE_M,   DE_COMM,DE_DOT, DE_SS,  KC_RSFT,
                            MO(NHL),KC_RGUI,MO(FMU),KC_LALT,KC_RCTL,
        KC_DOWN,    KC_RGHT,
        KC_MINS,
        MEH_T(KC_NO),KC_ENT,KC_SPC
    ),

/* Layer 2: poor man’s Neo
 * based on kaimi’s layout
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  TAB  │  1  │  2  │  3  │  4  │  5  │  `  │     │  ´  │  6  │  7  │  8  │  9  │  0  │ BKSPC │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │   Y   │  X  │  V  │  L  │  C  │  W  │ HOM │     │ END │  K  │  H  │  G  │  F  │  Q  │  ß    │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤  E  │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │ Mod3  │  U  │  I  │  A  │  E  │  O  ├─────┤     ├─────┤  S  │  N  │  R  │  T  │  D  │ Mod3  │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤(TL2)│     │(TL3)├─────╄─────╃─────┼─────┼─────┼───────┤
 * │ LSHFT │  Ü  │  Ö  │  Ä  │  P  │  Z  │     │     │     │  B  │  M  │  ,  │  .  │  J  │ Shift │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │ CTL │ ALT │ MO1 │ Win │ MO4 │                             │ M04 │ Win │ MO1 │ ALT │ CTL │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │  ←  │  ↑  │ │  ↓  │  →  │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │  ─  │ │  ─  │     │     │
 *                             │ SPC │ RTN ├─────┤ ├─────┤ RTN │ SPC │
 *                             │     │     │ HYP │ │ MEH │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
[PMN] = LAYOUT_ergodox(
        KC_TAB,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_EQL,
        DE_Y,       DE_X,   DE_V,   DE_L,   DE_C,   DE_W,   KC_HOME,
        KC_NO,      DE_U,   DE_I,   DE_A,   DE_E,   DE_O,
        KC_LSFT,    DE_UDIA,DE_ODIA,DE_ADIA,DE_P,   DE_Z,   KC_TRNS,
        KC_LCTL,    KC_LALT,MO(FMU),KC_LGUI,MO(NHL),
                                                    KC_LEFT,    KC_UP,
                                                                KC_MINS,
                                            KC_SPC, KC_ENT,    ALL_T(KC_NO),
        // right hand
        DE_ACUT,    KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSPC,
        KC_END,     DE_K,   DE_H,   DE_G,   DE_F,   DE_Q,   DE_SS,
                    DE_S,   DE_N,   DE_R,   DE_T,   DE_D,   KC_NO,
        KC_TRNS,    DE_B,   DE_M,   KC_COMM,KC_DOT, DE_J,   KC_RSFT,
                            MO(NHL),KC_RGUI,MO(FMU),KC_LALT,KC_RCTL,
        KC_DOWN,    KC_RGHT,
        KC_MINS,
        MEH_T(KC_NO),KC_ENT,KC_SPC
    ),

/* Layer 3: F-keys, Mouse and Unicode
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │     │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │  ┌  │  ┬  │  ┐  │  ─  │  │  │     │     │     │  ↔  │  ←  │  →  │  ↑  │  ↓  │       │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │       │  ├  │  ┼  │  ┤  │  〈 │  〉 ├─────┤     ├─────┤     │  ✓  │  ✕  │  •  │  ∶  │       │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤(TL2)│     │(TL3)├─────╄─────╃─────┼─────┼─────┼───────┤
 * │       │  └  │  ┴  │  ┘  │     │     │     │     │     │  ⇔  │  ⇐  │  ⇒  │  ⇑  │  ⇓  │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │(MO1)│     │(MO4)│                             │(MO4)│     │(MO1)│     │     │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │ Ms← │ Ms↑ │ │ Ms↓ │ Ms→ │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │ MLC │ │ MRC │     │     │
 *                             │     │     ├─────┤ ├─────┤     │     │
 *                             │     │     │     │ │     │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
[FMU] = LAYOUT_ergodox(
        // left hand
        KC_TRNS,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,
        KC_TRNS,    UC(0x250C),UC(0x252C),UC(0x2510),UC(0x2500),UC(0x2502),KC_TRNS,
        KC_TRNS,    UC(0x251C),UC(0x253C),UC(0x2524),UC(0x3008),UC(0x3009),
        KC_TRNS,    UC(0x2514),UC(0x2534),UC(0x2518),KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
                                                     KC_MS_L,   KC_MS_U,
                                                                KC_BTN1,
                                            KC_TRNS, KC_TRNS,   KC_TRNS,
        // right hand
        KC_F7,      KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_TRNS,
        KC_TRNS,    UC(0x2194),UC(0x2190),UC(0x2192),UC(0x2191),UC(0x2193),KC_TRNS,
                    KC_TRNS,   UC(0x2713),UC(0x2715),UC(0x2022),UC(0x2236),KC_TRNS,
        KC_TRNS,    UC(0x21D4),UC(0x21D0),UC(0x21D2),UC(0x21D1),UC(0x21D3),KC_TRNS,
                               KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_MS_D,    KC_MS_R,
        KC_BTN2,
        KC_TRNS,    KC_TRNS,   KC_TRNS
    ),

/* Layer 4: Neo’s software layer 4 rebuilt in Hardware
 * based on kaimi’s layout
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │ PgUp│ BSpc│  ↑  │ Del │ PgDn│     │     │     │     │  7  │  8  │  9  │  +  │   −   │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │       │ Home│  ←  │  ↓  │  →  │ End ├─────┤     ├─────┤     │  4  │  5  │  6  │  ,  │   .   │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤(TL2)│     │(TL3)├─────╄─────╃─────┼─────┼─────┼───────┤
 * │       │ Esc │ Tab │ Ins │ Ret │ Undo│     │     │     │     │  1  │  2  │  3  │     │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │(MO1)│     │(MO4)│                             │(MO4)│     │(MO1)│     │     │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │     │     │ │     │     │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │     │ │     │     │     │
 *                             │     │     ├─────┤ ├─────┤     │     │
 *                             │     │     │     │ │     │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
[NHL] = LAYOUT_ergodox(
        // left hand
        KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,      KC_PGUP,KC_BSPC,KC_UP,  KC_DEL, KC_PGDN,KC_NO,
        KC_NO,      KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END,
        KC_NO,      KC_ESC, KC_TAB, KC_INS, KC_ENT, KC_UNDO,KC_TRNS,
        KC_NO,      KC_NO,  KC_TRNS,KC_NO,  KC_TRNS,
                                                    KC_NO,      KC_NO,
                                                                KC_NO,
                                            KC_NO,  KC_NO,      KC_NO,
        // right hand
        KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,      KC_NO,  KC_7,   KC_8,   KC_9,   DE_PLUS,DE_MINS,
                    KC_NO,  KC_4,   KC_5,   KC_6,   KC_COMM,KC_DOT,
        KC_TRNS,    KC_NO,  KC_1,   KC_2,   KC_3,   KC_NO,  KC_NO,
                            KC_TRNS,KC_NO,  KC_TRNS,KC_NO,  KC_NO,
        KC_NO,      KC_NO,
        KC_NO,
        KC_NO,      KC_NO,  KC_NO
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [BASE] = ACTION_FUNCTION(BASE),
    [PMQ]  = ACTION_FUNCTION(PMQ),
    [PMN]  = ACTION_FUNCTION(PMN),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX);
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void)
{
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case FMU:
            ergodox_right_led_1_on();
        break;
        case PMQ:
            ergodox_right_led_2_on();
        break;
        case PMN:
            ergodox_right_led_3_on();
        break;
        default:
            if(host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) {
                ergodox_led_all_set(LED_BRIGHTNESS_HI);
                ergodox_right_led_1_on();
            }
            else {
                ergodox_board_led_off();
            }
        break;
    }

};


// Override Unicode start method to use NE_U instead of KC_U
void unicode_input_start (void) {
    register_code(KC_LCTL);
    register_code(KC_LSFT);
    register_code(NE_U);
    unregister_code(NE_U);
    unregister_code(KC_LSFT);
    unregister_code(KC_LCTL);
};
