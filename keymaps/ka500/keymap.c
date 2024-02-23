/* Copyright 2021 Michael Stapelberg
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "lkg_km_common.h"
#include "lkg_tap_dances.h"
#include "lkg_combos.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
  
   Keymap: Default Layer in DVORAK
  
   ,-------------------------------------------------------------------------------------------------------------------.    ,--------------------.
   |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | PSCR | SLCK |   PAUS |    | LGUI | RGUI | MENU |
   |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------.    |------+------+------+------.
   | ESC    |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8   |  9(  |  0)  | \|     |    |  NL  |      |  /   |  *   | 
   |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|    |------+------+------+------|
   | Tab    |  ':  |  ,<  |  .>  |   P  |   Y  |                           |   F  |   G  |   C  |   R  |   L  | /?     |    |   7  |   8  |   9  |   -  | 
   |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|    |------+------+------+------|
   | =+     |   A  |   O  |   E  |   U  |   I  |                           |   D  |   H  |   T  |   N  |   S  | -_     |    |   4  |   5  |   6  |   +  | 
   |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|    |------+------+------+------|
   | Shift  |  ;:  |   Q  |   J  |   K  |   X  |                           |   B  |   M  |   W  |   V  |   Z  | Shift  |    |   1  |   2  |   3  | Ent  | 
   `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'    `------+------+------+------'
            | L2`~ | GU/M | Left | Right|                                         | Up   | Down | GU/[ | L2-]}|		                  |   .  | 
            `---------------------------'                                         `---------------------------'		                  `------' 
                                          ,-------------.         ,--------------.
                                          | TD16 | TD18 |         | TD19 | TD17 |
                                   ,------|------|------|         |-------+------+------.  ,------.
                                   |      |      | L1PU |         | L1PU  |      |      |  |      |
                                   |Space | BSPC |------|         |-------| ENTR | Space|  |  0   |
                                   |      |      | L3PU |         | L3PU  |      |      |  |      |
                                   `--------------------'         `---------------------'  `------' 

   TD16: tap: OSM(LCTL);  held: LCTL;  tap-then-hold: Mo(_NAVI)
   TD16: tap: OSM(RCTL);  held: RCTL;  tap-then-hold: Mo(_NAVI)
   TD16: tap: OSM(LALT);  held: LALT;  tap-then-hold: Mo(_NAVI)
   TD16: tap: RALT;       held: LALT;  tap-then-hold: Mo(_NAVI)


 */

[_DVORAK] = LAYOUT_ka500(
			 KC_NO,
			 KC_F1,                    KC_F2,              KC_F3 ,             KC_F4,                KC_F5,           KC_F6,
			 KC_F7,                    KC_F8,              KC_F9,              KC_F10,               KC_F11,          KC_F12,
			 KC_PSCR,                  KC_SCRL,            KC_PAUS,

			 KC_LGUI,                  KC_RGUI,            KC_APP,
		   
			 KC_ESC,
			 KC_1,                     KC_2,               KC_3,               KC_4,                 KC_5,
			 KC_6,                     KC_7,               KC_8,               KC_9,                 KC_0,
			 KC_BSLS,
		   
		                                   KC_NUM,                                 KC_PSLS,              KC_PAST,             
		   
			 KC_TAB,
			 KC_QUOT,                  KC_COMM,            KC_DOT,             KC_P,                 KC_Y,
			 KC_F,                     KC_G,               KC_C,               KC_R,                 KC_L,
			 KC_SLSH,
		   
		                                   KC_P7,              KC_P8,              KC_P9,                KC_PMNS,                 
		   
			 KC_EQL,
			 KC_A,                     KC_O,               KC_E,               KC_U,                 KC_I,
			 KC_D,                     KC_H,               KC_T,               KC_N,                 KC_S,
			 KC_MINS,
		   
		                                   KC_P4,              KC_P5,              KC_P6,                KC_PPLS,

			 OSM(MOD_LSFT),
			 KC_SCLN,                  KC_Q,               KC_J,               KC_K,                 KC_X,
			 KC_B,                     KC_M,               KC_W,               KC_V,                 KC_Z,
			 OSM(MOD_RSFT),
		   
		                                   KC_P1,              KC_P2,              KC_P3,                KC_PENT,             
		   
			 LT(_NAVI, KC_GRV),        LGUI_T(KC_APP),     KC_LEFT,            KC_RGHT,
			 KC_UP,                    KC_DOWN,            RGUI_T(KC_LBRC),    LT(_NAVI, KC_RBRC),

                                                   KC_PDOT,
		   
			 TD(DANCE_16),             TD(DANCE_18),
			 TD(DANCE_19),             TD(DANCE_17),
		   
			 LT(_NAVI, KC_HOME),       LT(_EMACS_0, KC_END),
		   
			 KC_SPC,                   KC_BSPC,

			 LT(_NAVI, KC_PGUP),       LT(_EMACS_0, KC_PGDN),

			 KC_ENTER,                 KC_SPC,

		         KC_P0
			 ),

/*
  
   Keymap: layer 1 - Navigation keys 0 
  
   ,-------------------------------------------------------------------------------------------------------------------.     ,--------------------.        
   |   L0   |  F13 |  F14 |  F15 | F16  | F17  | F18  | F19  |  F20 | F21  |  F22 |  F23 |  F24 |      |      |	 NKRO  |     |      |      |      |  
   |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------.     +------+------+------+------.
   |   TD4  | TD5  |  TD6 |  TD7 |  TD8 |  TD9 |                           | TD10 | TD11 | TD12 | TD13 | TD14 |  TD15  |     |      |      |      |      | 
   |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|     +------+------+------+------+
   |        |  V+  |  TD2 | MCU  | MB1  | MWU  |                           |      |      |  U   |      |      |        |     |      |      |      |      | 
   |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|     +------+------+------+------+
   |        | MWL  | MCL  | MCd  | MCR  | MWR  |                           | MB1  |  L   |  D   |  R   |      |        |     |      |      |      |      | 
   |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|     +------+------+------+------+
   |        | TD3  | BBW  | WSC  | BFW  | MWD  |                           |      |      |      |      |      |        |     |      |      |      |      | 
   `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'     +------+------+------+------'
            |      |      |      |      |                                         |      |      |      |      |		                   |      |        
            `---------------------------'                                         `---------------------------'		                   `------'        
                                          ,-------------.         ,--------------.
                                          |      |      |         |       |      |
                                   ,------|------|------|         |-------+------+------.  ,------.
                                   |      |      |      |         |       |      |      |  |      |
                                   |      |      |------|         |-------|      |      |  |      |
                                   |      |      |      |         |       |      |      |  |      |
                                   `--------------------'         `---------------------'  `------'


        L0:   tap to _DVORAK
        TD2:  tap: mouse button 2, held: mouse button 3
	TD3:  tap: volume down, held mute 
        TD4:  tap: F1,  held: LCTL + F1,  double-tap: LALT + F1,  tap-then-held: LCTL+ALT+F1
        TD5:  tap: F2,  held: LCTL + F2,  double-tap: LALT + F2,  tap-then-held: LCTL+ALT+F2
        TD6:  tap: F3,   eld: LCTL + F1,  double-tap: LALT + F3,  tap-then-held: LCTL+ALT+F1
        TD7:  tap: F4,  held: LCTL + F1,  double-tap: LALT + F4,  tap-then-held: LCTL+ALT+F4
        TD8:  tap: F5,  held: LCTL + F1,  double-tap: LALT + F5,  tap-then-held: LCTL+ALT+F5
        TD9:  tap: F6,  held: LCTL + F6,  double-tap: LALT + F16, tap-then-held: LCTL+ALT+F6
        TD10: tap: F7,  held: LCTL + F7,  double-tap: LALT + F7,  tap-then-held: LCTL+ALT+F7
        TD11: tap: F8,  held: LCTL + F8,  double-tap: LALT + F18, tap-then-held: LCTL+ALT+F8
        TD12: tap: F9,  held: LCTL + F9,  double-tap: LALT + F9,  tap-then-held: LCTL+ALT+F9
        TD13: tap: F10, held: LCTL + F10, double-tap: LALT + F10, tap-then-held: LCTL+ALT+F10
        TD14: tap: F11, held: LCTL + F11, double-tap: LALT + F11, tap-then-held: LCTL+ALT+F11
        TD15: tap: F12, held: LCTL + F12, double-tap: LALT + F12, tap-then-held: LCTL+ALT+F12

 */

[_NAVI] = LAYOUT_ka500(
		       TO(_DVORAK),
		       KC_F13,              KC_F14,             KC_F15,           KC_F16,           KC_F17,          KC_F18,
		       KC_F19,              KC_F20,             KC_F21,           KC_F22,           KC_F23,          KC_F24,
		       KC_NO,               KC_NO,              NK_ON,

		       KC_NO,               KC_NO,              KC_NO,
		   
		       TD(DANCE_4),
		       TD(DANCE_5),         TD(DANCE_6),        TD(DANCE_7),      TD(DANCE_8),      TD(DANCE_9),
		       TD(DANCE_10),        TD(DANCE_11),       TD(DANCE_12),     TD(DANCE_13),     TD(DANCE_14),
		       TD(DANCE_15),
		   
		       KC_NO,                                   KC_NO,            KC_NO,     
		   
		       KC_NO,
		       KC_VOLU,             TD(DANCE_2),        KC_MS_U,          KC_MS_BTN1,       KC_WH_U,
		       KC_NO,               KC_NO,              KC_UP,            KC_NO,            KC_NO,
		       KC_NO,
		   
		       KC_NO,               KC_NO,              KC_NO,            KC_NO,             
		   
		       KC_NO,
		       KC_WH_L,             KC_MS_L,            KC_MS_D,          KC_MS_R,          KC_WH_R,
		       KC_NO,               KC_LEFT,            KC_DOWN,          KC_RIGHT,         KC_NO,
		       KC_NO,
		   
		       KC_NO,               KC_NO,              KC_NO,            KC_NO,             

		       KC_NO,
		       TD(DANCE_3),         KC_WBAK,            KC_WSCH,          KC_WFWD,          KC_WH_D,
		       KC_NO,               KC_NO,              KC_NO,            KC_NO,            KC_NO,
		       KC_NO,
		   		   
		       KC_NO,               KC_NO,            KC_NO,            KC_NO,             

		       KC_NO,               KC_NO,              KC_NO,            KC_NO,
		       KC_NO,               KC_NO,              KC_NO,            KC_NO,

                       KC_NO,
		   
		       KC_NO,               KC_NO,
		       KC_NO,               KC_NO,
		   
		       KC_NO,               KC_NO,
		   
		       KC_NO,               KC_NO,

		       KC_NO,               KC_NO,

		       KC_NO,               KC_NO,

		       KC_NO
		       ),

/*
  
   Keymap: layer 2 - Navigation keys 1
  
   ,---------------------------------------------------------------------------------------------------.                      ,--------------------.        
   |        |      |      |      |      |      |      |      |      |      |      |      |      |      |		      |      |      |      |        
   |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------.      +------+------+------+------. 
   |  C-F1  | C-F2 | C-F3 | C-F4 | C-F5 | C-F6 |                           | C-F7 | C-F8 | C-F9 | C-F10| C-F11| C-F12  |      |      |      |      |      | 
   |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|      +------+------+------+------+ 
   |        |      |      |      | Prev | Vol+ |                           | Find |      |      |      |      | MPause |      |      |      |      |      | 
   |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|      +------+------+------+------+ 
   |  Stop  |      | Exec |      |      | Mute |                           |      | Help |      | Next | Selc | Again  |      |      |      |      |      | 
   |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|      +------+------+------+------+ 
   |        | Undo | Cut  | Copy |Paste | Vol- |                           |      | Menu |      |      |      |        |      |      |      |      |      | 
   `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'      +------+------+------+------' 
            |      |      | CA-L | CA-R |                                         | CA-U | CA-D |      |      |		                    |      |        
            `---------------------------'                                         `---------------------------'		                    `------'        
                                          ,-------------.         ,--------------.					                                    
                                          |      |      |         |       |      |
                                   ,------|------|------|         |-------+------+------.  ,------. 
                                   |      | CA-  |      |         |       |      |      |  |      | 
                                   |      | DEL  |------|         |-------|      |      |  |      | 
                                   |      |      |      |         |       |      |      |  |      | 
                                   `--------------------'         `--------------------'   `------' 
 											            

[_NAVI] = LAYOUT_ka500(
			 KC_NO,
			 KC_NO,               KC_NO,              KC_NO,            KC_NO,            KC_NO,           KC_NO,
			 KC_NO,               KC_NO,              KC_NO,            KC_NO,            KC_NO,           KC_NO,
			 KC_NO,               KC_NO,              KC_NO,

			 KC_NO,               KC_NO,              KC_NO,
		   
			 LCTL(KC_F1),
			 LCTL(KC_F2),         LCTL(KC_F3),        LCTL(KC_F4),      LCTL(KC_F5),      LCTL(KC_F6),
			 LCTL(KC_F7),         LCTL(KC_F8),        LCTL(KC_F9),      LCTL(KC_F10),     LCTL(KC_F11),
			 LCTL(KC_F12),
		   
		                              KC_NO,                               KC_NO,            KC_NO,             
		   
			 KC_NO,
			 KC_NO,               KC_NO,              KC_NO,            KC_MPRV,          KC_VOLU,
			 KC_FIND,             KC_NO,              KC_UP,            KC_NO,            KC_NO,
			 KC_MPLY,
		   
		                              KC_NO,              KC_NO,            KC_NO,            KC_NO,             
		   
			 KC_STOP,
			 KC_NO,               KC_NO,              KC_EXEC,          KC_NO,            KC_MUTE,
			 KC_NO,               KC_HELP,            KC_NO,            KC_MNXT,          KC_SLCT,
			 KC_AGIN,
		   
		                              KC_NO,              KC_NO,            KC_NO,            KC_NO,             

			 KC_NO,
			 KC_UNDO,             KC_CUT,             KC_COPY,          KC_PSTE,          KC_VOLD,
			 KC_NO,               KC_MENU,            KC_NO,            KC_NO,            KC_NO,
			 KC_NO,
		   
		                              KC_NO,              KC_NO,            KC_NO,            KC_NO,             

			 KC_NO,               KC_NO,              LCA(KC_LEFT),     LCA(KC_RIGHT),
			 LCA(KC_UP),          LCA(KC_DOWN),       KC_NO,            KC_NO,

                                                                  KC_NO,
		   
			 KC_NO,               KC_NO,
			 KC_NO,               KC_NO,
		   
			 KC_NO,               KC_NO,
		   
			 KC_NO,               LCA(KC_DEL),

			 KC_NO,               KC_NO,

			 KC_NO,               KC_NO,

		         KC_NO
			 ),

*/

/* 
 
   Keymap: layer 3 - Emacs keybindings 0
  
   ,---------------------------------------------------------------------------------------------------.                      ,--------------------.        
   |        |      |      |      |      |      |      |      |      |      |      |      |      |      |		      |      |      |      |        
   |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------.      +------+------+------+------. 
   |  QM16  | QM5  | QM6  | QM7  | QM11 | QM17 |                           | QM13 |      |      | QM25 | QM4  | QM15   |      |      |      |      |      | 
   |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|      +------+------+------+------+ 
   |        |      |      |      | QM14 |      |                           |  QM0 |      | QM22 | QM23 | QM20 |        |      |      |      |      |      | 
   |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|      +------+------+------+------+ 
   |        |      |      |      | QM19 | QM24 |                           | QM12 |      | QM21 |      |  QM1 |        |      |      |      |      |      | 
   |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|      +------+------+------+------+ 
   |        |      | QM18 |      | QM3  |      |                           |  QM2 |      |  QM8 |      |      |        |      |      |      |      |      | 
   `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'      +------+------+------+------' 
            |      |      |      |      |                                         |      |      | QM9  | QM10 |		                    |      |        
            `---------------------------'                                         `---------------------------'		                    `------'        
                                          ,-------------.         ,--------------.					                                    
                                          |      | QM28 |         | QM29  |      |
                                   ,------|------|------|         |-------+------+------.  ,------. 
                                   |      |      |      |         |       |      |      |  |      | 
                                   | QM26 | QM27 |------|         |-------| QM30 | QM31 |  |      | 
                                   |      |      |      |         |       |      |      |  |      | 
                                   `--------------------'         `--------------------'   `------' 

        QM0:   C-x C-f  open file 
	QM1:   C-x C-s  save fie  
        QM2:   C-x C-b  list buffers
	QM3:   C-x K enter kill current buffer without asking
	QM4:   C-x 0 close window
	QM5:   C-x 1 close other window
	QM6:   C-x 2 split frame into two windows, horizontally
	QM7:   C-x 3 split frame into two windows, vertically
	QM8:   C-x C-w write file
	QM9:   C-x { last paragraph
	QM10:  C-x } next paragraph
	QM11:  C-x 4 b select buffer in other window
	QM12:  C-x 4 d open dired in other window
	QM13:  C-x ^ grow window taller
	QM14:  C-x C-p mark page
	QM15:  C-x 5 0 close frame
	QM16:  C-x 5 1 close other frames
	QM17   C-x 5 2 create new frame
	QM18:  C-x C-q toggle read-only mode
	QM19:  C-x C-u uppercase region
	QM20:  C-x C-l lowercase region
	QM21:  C-x C-t transpose lines
	QM22:  C-c C-c execute code (ess or elpy)
	QM23:  C-x r s save to register
	QM24:  C-x r i insert from register
	QM25:  (_)
	QM26:  C-x r r copy rectangle to register
	QM27:  C-x r k kill rectangle
	QM28:  C-x r o open rectangle shifting right text 
	QM29:  C-x r t prefix each line with a string
	QM30:  C-x r c blank out rectangle 
	QM31:  C-x r y yank rectange 
 */											            

[_EMACS_0] = LAYOUT_ka500(
			  KC_NO,
			  KC_NO,               KC_NO,              KC_NO,            KC_NO,            KC_NO,           KC_NO,
			  KC_NO,               KC_NO,              KC_NO,            KC_NO,            KC_NO,           KC_NO,
			  KC_NO,               KC_NO,              KC_NO,

			  KC_NO,               KC_NO,              KC_NO,
		   
			  QK_MACRO_16,
			  QK_MACRO_5,          QK_MACRO_6,         QK_MACRO_7,       QK_MACRO_11,      QK_MACRO_17,
			  QK_MACRO_13,         KC_NO,              KC_NO,            QK_MACRO_25,      QK_MACRO_4,
			  QK_MACRO_15,
		   
 		                               KC_NO,                                KC_NO,           KC_NO,             
		   
			  KC_NO,
			  KC_NO,               KC_NO,              KC_NO,            QK_MACRO_14,      KC_NO,
			  QK_MACRO_0,          KC_NO,              QK_MACRO_22,      QK_MACRO_23,      QK_MACRO_20,
			  KC_NO,
		   
	   	                               KC_NO,              KC_NO,            KC_NO,            KC_NO,             
		   
			  KC_NO,
			  KC_NO,               KC_NO,              KC_NO,            QK_MACRO_19,      QK_MACRO_24,
			  QK_MACRO_12,         KC_NO,              QK_MACRO_21,      KC_NO,            QK_MACRO_1,
			  KC_NO,
		   
 		                               KC_NO,              KC_NO,            KC_NO,            KC_NO,             

			  KC_NO,
			  KC_NO,               QK_MACRO_18,        KC_NO,            QK_MACRO_3,       KC_NO,
			  QK_MACRO_2,          KC_NO,              QK_MACRO_8,       KC_NO,            KC_NO,
			  KC_NO,
		   
		                               KC_NO,              KC_NO,            KC_NO,            KC_NO,             

			  KC_NO,               KC_NO,              KC_NO,            KC_NO,
			  KC_NO,               KC_NO,              QK_MACRO_9,       QK_MACRO_10,

                                                                   KC_NO,
		   
			  KC_NO,               QK_MACRO_28,
			  QK_MACRO_29,         KC_NO,
		   
			  KC_NO,               KC_NO,
		   
			  QK_MACRO_26,         QK_MACRO_27,

			  KC_NO,               KC_NO,

			  QK_MACRO_30,         QK_MACRO_31,

		          KC_NO
			  ),

};



#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)


