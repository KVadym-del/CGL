#ifndef RENDERING_H
#define RENDERING_H

#include "types.h"
#include "utils.h"
#include "window.h"

void fill_window_field(codepoint_t field_size);

void make_rectangle(codepoint_t codepoint, uint16_t x, uint16_t y, uint16_t width, uint16_t height);

#endif // RENDERING_H
