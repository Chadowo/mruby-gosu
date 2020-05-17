#include "mruby.h"
#include <Gosu/Gosu.h>
#include "window.h"
#include "text_input.h"
#include "image.h"
#include "font.h"
#include "sample.h"
#include "song.h"
#include "channel.h"

mrb_value
mrb_gosu_fps(mrb_state *mrb) {
  return mrb_fixnum_value(Gosu_fps());
}

mrb_value
mrb_gosu_flush(mrb_state *mrb) {
  Gosu_flush();
}

mrb_value
mrb_gosu_language(mrb_state *mrb) {
  return mrb_str_new_cstr(mrb, Gosu_language());
}

mrb_value
mrb_gosu_milliseconds(mrb_state *mrb) {
  return mrb_fixnum_value(Gosu_milliseconds());
}

mrb_value
mrb_gosu_default_font_name(mrb_state *mrb) {
  return mrb_str_new_cstr(mrb, Gosu_default_font_name());
}

mrb_value
mrb_gosu_button_down(mrb_state *mrb, mrb_value self) {
  mrb_int btn_id;
  mrb_get_args(mrb, "i", &btn_id);

  return mrb_bool_value(Gosu_button_down(btn_id));
}

mrb_value
mrb_gosu_button_id_to_char(mrb_state *mrb, mrb_value self) {
  mrb_int btn_id;
  mrb_get_args(mrb, "i", &btn_id);

  const char *string;
  string = Gosu_button_id_to_char(btn_id);

  return mrb_str_new_cstr(mrb, string);
}

mrb_value
mrb_gosu_char_to_button_id(mrb_state *mrb, mrb_value self) {
  mrb_value string;
  mrb_get_args(mrb, "S", &string);

  const char *str;
  str = mrb_string_cstr(mrb, string);

  return mrb_fixnum_value(Gosu_button_char_to_id(str));
}

mrb_value
mrb_gosu_draw_line(mrb_state *mrb, mrb_value self) {
  mrb_float x1, y1, x2, y2, z;
  mrb_int c1, c2, mode;
  mrb_get_args(mrb, "ffiffifi", &x1, &y1, &c1, &x2, &y2, &c2, &z, &mode);

  Gosu_draw_line(x1, y1, c1, x2, y2, c2, z, mode);

  return self;
}

mrb_value
mrb_gosu_draw_quad(mrb_state *mrb, mrb_value self) {
  mrb_float x1, y1, x2, y2, x3, y3, x4, y4, z;
  mrb_int c1, c2, c3, c4, mode;
  mrb_get_args(mrb, "ffiffiffiffifi", &x1, &y1, &c1, &x2, &y2, &c2, &x3, &y3, &c3, &x4, &y4, &c4, &z, &mode);

  Gosu_draw_quad(x1, y1, c1, x2, y2, c2, x3, y3, c3, x4, y4, c4, z, mode);

  return self;
}

mrb_value
mrb_gosu_draw_triangle(mrb_state *mrb, mrb_value self) {
  mrb_float x1, y1, x2, y2, x3, y3, z;
  mrb_int c1, c2, c3, mode;
  mrb_get_args(mrb, "ffiffiffifi", &x1, &y1, &c1, &x2, &y2, &c2, &x3, &y3, &c3, &z, &mode);

  Gosu_draw_triangle(x1, y1, c1, x2, y2, c2, x3, y3, c3, z, mode);

  return self;
}

mrb_value
mrb_gosu_draw_rect(mrb_state *mrb, mrb_value self) {
  mrb_float x, y, width, height, z;
  mrb_int c, mode;
  mrb_get_args(mrb, "ffffifi", &x, &y, &width , &height, &c, &z, &mode);

  Gosu_draw_rect(x, y, width, height, c, z, mode);

  return self;
}

mrb_value
mrb_gosu_offset_x(mrb_state *mrb, mrb_value self) {
  mrb_float angle, radius;
  mrb_get_args("ff", &angle, &radius);

  return mrb_fixnum_value(Gosu_offset_x(angle, radius));
}

mrb_value
mrb_gosu_offset_y(mrb_state *mrb, mrb_value self) {
  mrb_float angle, radius;
  mrb_get_args("ff", &angle, &radius);

  return mrb_fixnum_value(Gosu_offset_y(angle, radius));
}

mrb_value
mrb_gosu_distance(mrb_state *mrb, mrb_value self) {
  mrb_float x1, y1, x2, y2;
  mrb_get_args("ffff", &x1, &y1, &x2, &y2);

  return mrb_fixnum_value(Gosu_distance(x1, y1, x2, y2));
}

mrb_value
mrb_gosu_angle(mrb_state *mrb, mrb_value self) {
  mrb_float x1, y1, x2, y2;
  mrb_get_args("ffff", &x1, &y1, &x2, &y2);

  return mrb_fixnum_value(Gosu_angle(x1, y1, x2, y2));
}

mrb_value
mrb_gosu_angle_diff(mrb_state *mrb, mrb_value self) {
  mrb_float angle1, angle2;
  mrb_get_args("ff", &angle1, &angle2);

  return mrb_fixnum_value(Gosu_angle_diff(angle1, angle2));
}

mrb_value
mrb_gosu_random(mrb_state *mrb, mrb_value self) {
  mrb_float min, max;
  mrb_get_args("ff", &min, &max);

  return mrb_fixnum_value(Gosu_random(min, max));
}

mrb_value
mrb_gosu_screen_width(mrb_state *mrb, mrb_value self) {
  // mrb_value window_pointer;
  // mrb_get_args("ff", &window_pointer);

  return mrb_fixnum_value(Gosu_screen_width(NULL));
}

mrb_value
mrb_gosu_screen_height(mrb_state *mrb, mrb_value self) {
  // mrb_value window_pointer;
  // mrb_get_args("ff", &window_pointer);

  return mrb_fixnum_value(Gosu_screen_height(NULL));
}

mrb_value
mrb_gosu_available_width(mrb_state *mrb, mrb_value self) {
  // mrb_value window_pointer;
  // mrb_get_args("ff", &window_pointer);

  return mrb_fixnum_value(Gosu_available_width(NULL));
}

mrb_value
mrb_gosu_available_height(mrb_state *mrb, mrb_value self) {
  // mrb_value window_pointer;
  // mrb_get_args("ff", &window_pointer);

  return mrb_fixnum_value(Gosu_available_height(NULL));
}

void mrb_gosu_init(mrb_state *mrb, struct RClass *mrb_gosu) {
  mrb_define_module_function(mrb, mrb_gosu, "fps", mrb_gosu_fps, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, mrb_gosu, "flush", mrb_gosu_flush, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, mrb_gosu, "language", mrb_gosu_language, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, mrb_gosu, "milliseconds", mrb_gosu_milliseconds, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, mrb_gosu, "default_font_name", mrb_gosu_default_font_name, MRB_ARGS_NONE());

  mrb_define_module_function(mrb, mrb_gosu, "button_down?", mrb_gosu_button_down, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_gosu, "button_id_to_char", mrb_gosu_button_id_to_char, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_gosu, "char_to_button_id", mrb_gosu_char_to_button_id, MRB_ARGS_REQ(1));

  mrb_define_module_function(mrb, mrb_gosu, "draw_line", mrb_gosu_draw_line, MRB_ARGS_REQ(8));
  mrb_define_module_function(mrb, mrb_gosu, "draw_quad", mrb_gosu_draw_quad, MRB_ARGS_REQ(14));
  mrb_define_module_function(mrb, mrb_gosu, "draw_triangle", mrb_gosu_draw_triangle, MRB_ARGS_REQ(11));
  mrb_define_module_function(mrb, mrb_gosu, "draw_rect", mrb_gosu_draw_rect, MRB_ARGS_REQ(7));

  mrb_define_module_function(mrb, mrb_gosu, "offset_x", mrb_gosu_offset_x, MRB_ARGS_REQ(2));
  mrb_define_module_function(mrb, mrb_gosu, "offset_y", mrb_gosu_offset_y, MRB_ARGS_REQ(2));
  mrb_define_module_function(mrb, mrb_gosu, "distance", mrb_gosu_distance, MRB_ARGS_REQ(4));
  mrb_define_module_function(mrb, mrb_gosu, "angle", mrb_gosu_angle, MRB_ARGS_REQ(2));
  mrb_define_module_function(mrb, mrb_gosu, "angle_diff", mrb_gosu_angle_diff, MRB_ARGS_REQ(2));
  mrb_define_module_function(mrb, mrb_gosu, "random", mrb_gosu_random, MRB_ARGS_REQ(2));

  mrb_define_module_function(mrb, mrb_gosu, "screen_width", mrb_gosu_screen_width, MRB_ARGS_OPT(1));
  mrb_define_module_function(mrb, mrb_gosu, "screen_height", mrb_gosu_screen_height, MRB_ARGS_OPT(1));
  mrb_define_module_function(mrb, mrb_gosu, "available_width", mrb_gosu_available_width, MRB_ARGS_OPT(1));
  mrb_define_module_function(mrb, mrb_gosu, "available_height", mrb_gosu_available_height, MRB_ARGS_OPT(1));
}



void mrb_mruby_gosu_gem_init(mrb_state *mrb) {
struct RClass *mrb_gosu;
mrb_gosu = mrb_define_module(mrb, "Gosu");

  mrb_gosu_init(mrb, mrb_gosu);
  mrb_gosu_window_init(mrb, mrb_gosu);
  mrb_gosu_text_input_init(mrb, mrb_gosu);
  mrb_gosu_image_init(mrb, mrb_gosu);
  mrb_gosu_font_init(mrb, mrb_gosu);
  mrb_gosu_sample_init(mrb, mrb_gosu);
  mrb_gosu_song_init(mrb, mrb_gosu);
  mrb_gosu_channel_init(mrb, mrb_gosu);
}

void mrb_mruby_gosu_gem_final(mrb_state *mrb) {
}