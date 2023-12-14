


typedef struct {
  bool is_press_action;
  uint8_t step;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD,
  DOUBLE_TAP,   
  TAP_THEN_HOLD,
  DOUBLE_SINGLE_TAP,
  MORE_TAPS
};


uint8_t dance_step(tap_dance_state_t *state);

enum tap_dance_codes {
  DANCE_0,       // TD0:    tap: OSM(LSFT); hold: L-Shift; double-tap: OSL(_EMACS_0); tap-then-hold: MO(_NAVI); 
  DANCE_1,       // TD1:    tap: OSM(RSFT); hold: R-Shift; double-tap: OSL(_EMACS_0); tap-then-hold: MO(_NAVI);
  DANCE_2,       // TD2:    tap: mouse right click, hold: mouse middle click
  DANCE_3,       // TD3:    tap: decrease volume, hold: mute
  DANCE_4,       // TD4:    tap: LCTL-F1, double-tap LALT-F1
  DANCE_5,       // TD5:    tap: LCTL-F2, double-tap LALT-F2
  DANCE_6,       // TD6:    tap: LCTL-F3, double-tap LALT-F3
  DANCE_7,       // TD7:    tap: LCTL-F4, double-tap LALT-F4
  DANCE_8,       // TD8:    tap: LCTL-F5, double-tap LALT-F5
  DANCE_9,       // TD9:    tap: LCTL-F6, double-tap LALT-F6
  DANCE_10,      // TD10:   tap: LCTL-F7, double-tap LALT-F7
  DANCE_11,      // TD11:   tap: LCTL-F8, double-tap LALT-F8
  DANCE_12,      // TD12:   tap: LCTL-F9, double-tap LALT-F9
  DANCE_13,      // TD13:   tap: LCTL-F10, double-tap LALT-F10
  DANCE_14,      // TD14:   tap: LCTL-F11, double-tap LALT-F11
  DANCE_15,      // TD15:   tap: LCTL-F12, double-tap LALT-F12
  DANCE_16,      // TD16:   tap: OSM(LCTL); hold: LCTL; double-tap: TO(_NAVI)
  DANCE_17,      // TD17:   tap: OSM(RCTL); hold: LCTL; double-tap: TO(_NAVI)
  DANCE_18,      // TD18:   tap: OSM(LALT); hold: LALT; double-tap: OSL(_EMacs_0)
  DANCE_19,      // TD19:   tap: RALT; hold: LALT; double-tap: OSL(_EMACS_0)
};                                                                                                     
