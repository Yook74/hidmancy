#ifndef HIDMANCY_HID_H
#define HIDMANCY_HID_H


void tap_key(uint16_t keycode);
void tap_key_shifted(uint16_t keycode);
void configure_usb_as_hid();
void revert_usb_configuration();
void type_string(const char* str);

#endif //HIDMANCY_HID_H
