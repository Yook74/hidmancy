#include <furi.h>
#include <furi_hal_usb.h>
#include <furi_hal_usb_hid.h>

#include "hid.h"

#define key_down_time 5
#define key_up_time 5

void tap_key(uint16_t keycode) {
    furi_hal_hid_kb_press(keycode);
    furi_delay_ms(key_down_time);
    furi_hal_hid_kb_release(keycode);
    furi_delay_ms(key_up_time);
}

void tap_key_shifted(uint16_t keycode) {
    furi_hal_hid_kb_press(KEY_MOD_LEFT_SHIFT);
    furi_hal_hid_kb_press(keycode);
    furi_delay_ms(key_down_time);
    furi_hal_hid_kb_release(keycode);
    furi_hal_hid_kb_release(KEY_MOD_LEFT_SHIFT);
    furi_delay_ms(key_up_time);
}

void configure_usb_as_hid() {
    furi_hal_usb_set_config(&usb_hid, NULL);
    furi_delay_ms(800); // tested it, this is needed before it's safe to ues
}

void revert_usb_configuration() {
    furi_hal_usb_set_config(&usb_cdc_single, NULL);
}

void type_string(const char* str) {
    while(*str) {
        char c = *str++;
        if(c >= 'a' && c <= 'z') {
            tap_key(HID_KEYBOARD_A + (c - 'a'));
        } else if(c >= 'A' && c <= 'Z') {
            tap_key_shifted(HID_KEYBOARD_A + (c - 'A'));
        } else if(c >= '1' && c <= '9') {
            tap_key(HID_KEYBOARD_1 + (c - '1'));
        } // TODO special characters
    }
}
