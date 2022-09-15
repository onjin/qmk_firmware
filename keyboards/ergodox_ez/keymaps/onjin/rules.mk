EXTRAFLAGS += -flto
LEADER_ENABLE = yes
KEY_LOCK_ENABLE = yes
CAPS_WORD_ENABLE = yes

AUDIO_ENABLE = no
BOOTMAGIC_ENABLE = no

CONSOLE_ENABLE = no
COMMAND_ENABLE = yes

ORYX_CONFIGURATOR = yes

RGBLIGHT_ENABLE = yes
SWAP_HANDS_ENABLE = yes

# prevent double presses problem
# https://github.com/qmk/qmk_firmware/issues/6269
DEBOUNCE_TYPE = sym_defer_g
DEBOUNCE = 45
UNICODE_ENABLE = yes
