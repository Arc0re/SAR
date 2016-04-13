//------------------------------------------------------------------------------
// SAR (Simple Ascii Renderer) library
// deps: SDL2, SDL2_image
//------------------------------------------------------------------------------

#ifndef __SAR_MAIN__
#define __SAR_MAIN__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

//------------------------------------------------------------------------------
// Enumerations
//------------------------------------------------------------------------------

// ASCII CP437 255 charACTERS
enum ascii_characters
{
	char_null = 0,
	char_empty_smiley = 1,
	char_smiley = 2,
	char_heart = 3,
	char_diamond = 4,
	char_club = 5,
	char_spade = 6,
	char_dot = 7,
	char_inverse_dot = 8,
	char_circle = 9,
	char_inverse_circle = 10,
	char_male_mars = 11,
	char_female_venus = 12,
	char_single_note = 13,
	char_double_note = 14,
	char_star = 15,
	char_right_fat_arrow = 16,
	char_left_fat_arrow = 17,
	char_double_vertical_arrow = 18,
	char_double_exclamation_mark = 19,
	char_paragraph = 20,
	char_section = 21,
	char_bar = 22,
	char_underscored_double_vertical_arrow = 23,
	char_up_arrow = 24,
	char_down_arrow = 25,
	char_right_arrow = 26,
	char_left_arrow = 27,
	char_inverted_not_sign = 28,
	char_double_horizontal_arrow = 29,
	char_up_fat_arrow = 30,
	char_down_fat_arrow = 31,
	char_space = 32,
	char_exclamation_mark = 33,
	char_quotes = 34,
	char_hash = 35,
	char_dollar = 36,
	char_percent = 37,
	char_ampersand = 38,
	char_apostrophe = 39,
	char_open_bracket = 40,
	char_close_bracket = 41,
	char_asterisk = 42,
	char_plus = 43,
	char_comma = 44,
	char_dash = 45,
	char_full_stop = 46,
	char_slash = 47,
	char_zero = 48,
	char_one = 49,
	char_two = 50,
	char_three = 51,
	char_four = 52,
	char_five = 53,
	char_six = 54,
	char_seven = 55,
	char_eight = 56,
	char_nine = 57,
	char_colon = 58,
	char_semi_colon = 59,
	char_less_than = 60,
	char_equals = 61,
	char_greater_than = 62,
	char_question_mark = 63,
	char_at = 64,
	char_uppercase_a = 65,
	char_uppercase_b = 66,
	char_uppercase_c = 67,
	char_uppercase_d = 68,
	char_uppercase_e = 69,
	char_uppercase_f = 70,
	char_uppercase_g = 71,
	char_uppercase_h = 72,
	char_uppercase_i = 73,
	char_uppercase_j = 74,
	char_uppercase_k = 75,
	char_uppercase_l = 76,
	char_uppercase_m = 77,
	char_uppercase_n = 78,
	char_uppercase_o = 79,
	char_uppercase_p = 80,
	char_uppercase_q = 81,
	char_uppercase_r = 82,
	char_uppercase_s = 83,
	char_uppercase_t = 84,
	char_uppercase_u = 85,
	char_uppercase_v = 86,
	char_uppercase_w = 87,
	char_uppercase_x = 88,
	char_uppercase_y = 89,
	char_uppercase_z = 90,
	char_open_square_bracket = 91,
	char_backslash = 92,
	char_close_square_bracket = 93,
	char_caret = 94,
	char_underscore = 95,
	char_grave_accent = 96,
	char_lowercase_a = 97,
	char_lowercase_b = 98,
	char_lowercase_c = 99,
	char_lowercase_d = 100,
	char_lowercase_e = 101,
	char_lowercase_f = 102,
	char_lowercase_g = 103,
	char_lowercase_h = 104,
	char_lowercase_i = 105,
	char_lowercase_j = 106,
	char_lowercase_k = 107,
	char_lowercase_l = 108,
	char_lowercase_m = 109,
	char_lowercase_n = 110,
	char_lowercase_o = 111,
	char_lowercase_p = 112,
	char_lowercase_q = 113,
	char_lowercase_r = 114,
	char_lowercase_s = 115,
	char_lowercase_t = 116,
	char_lowercase_u = 117,
	char_lowercase_v = 118,
	char_lowercase_w = 119,
	char_lowercase_x = 120,
	char_lowercase_y = 121,
	char_lowercase_z = 122,
	char_open_brace = 123,
	char_pipe = 124,
	char_close_brace = 125,
	char_tilde = 126,
	char_delete = 127,
	char_latin_capital_letter_c_with_cedilla = 128,
	char_latin_small_letter_u_with_diaeresis = 129,
	char_latin_small_letter_e_with_acute = 130,
	char_latin_small_letter_a_with_circumflex = 131,
	char_latin_small_letter_a_with_diaeresis = 132,
	char_latin_small_letter_a_with_grave = 133,
	char_latin_small_letter_a_with_ring_above = 134,
	char_latin_small_letter_c_with_cedilla = 135,
	char_latin_small_letter_e_with_circumflex = 136,
	char_latin_small_letter_e_with_diaeresis = 137,
	char_latin_small_letter_e_with_grave = 138,
	char_latin_small_letter_i_with_diaeresis = 139,
	char_latin_small_letter_i_with_circumflex = 140,
	char_latin_small_letter_i_with_grave = 141,
	char_latin_capital_letter_a_with_diaeresis = 142,
	char_latin_capital_letter_a_with_ring_above = 143,
	char_latin_capital_letter_e_with_acute = 144,
	char_latin_small_ligature_ae = 145,
	char_latin_capital_ligature_ae = 146,
	char_latin_small_letter_o_with_circumflex = 147,
	char_latin_small_letter_o_with_diaeresis = 148,
	char_latin_small_letter_o_with_grave = 149,
	char_latin_small_letter_u_with_circumflex = 150,
	char_latin_small_letter_u_with_grave = 151,
	char_latin_small_letter_y_with_diaeresis = 152,
	char_latin_capital_letter_o_with_diaeresis = 153,
	char_latin_capital_letter_u_with_diaeresis = 154,
	char_cent_sign = 155,
	char_pound_sign = 156,
	char_yen_sign = 157,
	char_peseta_sign = 158,
	char_latin_small_letter_f_with_hook = 159,
	char_latin_small_letter_a_with_acute = 160,
	char_latin_small_letter_i_with_acute = 161,
	char_latin_small_letter_o_with_acute = 162,
	char_latin_small_letter_u_with_acute = 163,
	char_latin_small_letter_n_with_tilde = 164,
	char_latin_capital_letter_n_with_tilde = 165,
	char_feminine_ordinal_indicator = 166,
	char_masculine_ordinal_indicator = 167,
	char_inverted_question_mark = 168,
	char_reversed_not_sign = 169,
	char_not_sign = 170,
	char_vulgar_fraction_one_half = 171,
	char_vulgar_fraction_one_quarter = 172,
	char_inverted_exclamation_mark = 173,
	char_left_pointing_double_angle_quotation_mark = 174,
	char_right_pointing_double_angle_quotation_mark = 175,
	char_light_shade = 176,
	char_medium_shade = 177,
	char_dark_shade = 178,
	char_box_drawings_light_vertical = 179,
	char_box_drawings_light_vertical_and_left = 180,
	char_box_drawings_vertical_single_and_left_double = 181,
	char_box_drawings_vertical_double_and_left_single = 182,
	char_box_drawings_down_double_and_left_single = 183,
	char_box_drawings_down_single_and_left_double = 184,
	char_box_drawings_double_vertical_and_left = 185,
	char_box_drawings_double_vertical = 186,
	char_box_drawings_double_down_and_left = 187,
	char_box_drawings_double_up_and_left = 188,
	char_box_drawings_up_double_and_left_single = 189,
	char_box_drawings_up_single_and_left_double = 190,
	char_box_drawings_light_down_and_left = 191,
	char_box_drawings_light_up_and_right = 192,
	char_box_drawings_light_up_and_horizontal = 193,
	char_box_drawings_light_down_and_horizontal = 194,
	char_box_drawings_light_vertical_and_right = 195,
	char_box_drawings_light_horizontal = 196,
	char_box_drawings_light_vertical_and_horizontal = 197,
	char_box_drawings_vertical_single_and_right_double = 198,
	char_box_drawings_vertical_double_and_right_single = 199,
	char_box_drawings_double_up_and_right = 200,
	char_box_drawings_double_down_and_right = 201,
	char_box_drawings_double_up_and_horizontal = 202,
	char_box_drawings_double_down_and_horizontal = 203,
	char_box_drawings_double_vertical_and_right = 204,
	char_box_drawings_double_horizontal = 205,
	char_box_drawings_double_vertical_and_horizontal = 206,
	char_box_drawings_up_single_and_horizontal_double = 207,
	char_box_drawings_up_double_and_horizontal_single = 208,
	char_box_drawings_down_single_and_horizontal_double = 209,
	char_box_drawings_down_double_and_horizontal_single = 210,
	char_box_drawings_up_double_and_right_single = 211,
	char_box_drawings_up_single_and_right_double = 212,
	char_box_drawings_down_single_and_right_double = 213,
	char_box_drawings_down_double_and_right_single = 214,
	char_box_drawings_vertical_double_and_horizontal_single = 215,
	char_box_drawings_vertical_single_and_horizontal_double = 216,
	char_box_drawings_light_up_and_left = 217,
	char_box_drawings_light_down_and_right = 218,
	char_full_block = 219,
	char_lower_half_block = 220,
	char_left_half_block = 221,
	char_right_half_block = 222,
	char_upper_half_block = 223,
	char_greek_small_letter_alpha = 224,
	char_latin_small_letter_sharp_s = 225,
	char_greek_capital_letter_gamma = 226,
	char_greek_small_letter_pi = 227,
	char_greek_capital_letter_sigma = 228,
	char_greek_small_letter_sigma = 229,
	char_micro_sign = 230,
	char_greek_small_letter_tau = 231,
	char_greek_capital_letter_phi = 232,
	char_greek_capital_letter_theta = 233,
	char_greek_capital_letter_omega = 234,
	char_greek_small_letter_delta = 235,
	char_infinity = 236,
	char_greek_small_letter_phi = 237,
	char_greek_small_letter_epsilon = 238,
	char_intersection = 239,
	char_identical_to = 240,
	char_plus_minus_sign = 241,
	char_greater_than_or_equal_to = 242,
	char_less_than_or_equal_to = 243,
	char_top_half_integral = 244,
	char_bottom_half_integral = 245,
	char_division_sign = 246,
	char_almost_equal_to = 247,
	char_degree_sign = 248,
	char_bullet_operator = 249,
	char_middle_dot = 250,
	char_square_root = 251,
	char_superscript_latin_small_letter_n = 252,
	char_superscript_two = 253,
	char_black_square = 254,
	char_no_break_space = 255
};

//------------------------------------------------------------------------------
// Types
//------------------------------------------------------------------------------

struct tile
{
    SDL_Texture * texture;
    SDL_Rect src; // part of the texture
    SDL_Rect dest; // rendering target, can do scaling
    int w;
    int h;
};

struct char_data
{
    int x;
    int y;  
};

typedef SDL_Event sar_event;
typedef SDL_Color sar_color;

//------------------------------------------------------------------------------
// Initialization and shutdown
//------------------------------------------------------------------------------

bool sar_init(const char * caption, int w, int h);
void sar_close(void);

//------------------------------------------------------------------------------
// Image/file loading
//------------------------------------------------------------------------------

bool sar_load_texture(const char * path);

//------------------------------------------------------------------------------
// Events handling
//------------------------------------------------------------------------------

void sar_get_events(sar_event * ev);

//------------------------------------------------------------------------------
// Rendering
//------------------------------------------------------------------------------

void sar_begin_rendering(void);
void sar_end_rendering(void);
void sar_render_tile_c(char c, int x, int y, SDL_Color bg_color, SDL_Color tile_color);
void sar_render_tile_char(enum ascii_characters c, int x, int y, SDL_Color bg_color, SDL_Color tile_color);
void sar_render_string(const char * str, int x, int y, SDL_Color bg_color, SDL_Color tile_color);

#endif // __SAR_MAIN__
