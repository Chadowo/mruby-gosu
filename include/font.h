#pragma once

#include "mruby.h"
#include "mruby/data.h"
#include "mruby/proc.h"
#include "mruby/class.h"
#include "mruby/string.h"
#include "stdbool.h"
#include "string.h"
#include "Gosu.h"
#include "image.h"

static struct RClass *mrb_gosu_font;

void mrb_gosu_font_init(mrb_state *mrb, struct RClass *mrb_gosu);