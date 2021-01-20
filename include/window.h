#pragma once

#include "mruby.h"
#include "mruby/data.h"
#include "mruby/proc.h"
#include "mruby/class.h"
#include "mruby/string.h"
#include "stdbool.h"
#include "string.h"
#include "Gosu_Window.h"

void mrb_gosu_window_init(mrb_state *mrb, struct RClass *mrb_gosu);