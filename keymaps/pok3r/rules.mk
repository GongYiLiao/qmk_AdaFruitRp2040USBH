# TAP_DANCE_ENABLE = yes
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
NKRO_ENABLE = yes

VPATH += keyboards/converter/adafruit_rp2040_usbh/keymaps/common

SRC += ../common/lkg_tap_dances.c
SRC += ../common/lkg_key_process.c
