


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
  DANCE_0,       // TD0:    tap: Space; hold: Enter; 
  DANCE_1,       // TD1:    tap: F3; hold: Mouse wheel up
  DANCE_2,       // TD2:    tap: tap: OSM(RALT); hold: LALT 
  DANCE_3,       // TD3:    tap: ], hold: mouse left click
};                                                                                                     
