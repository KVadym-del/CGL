#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

typedef uint32_t codepoint_t;

struct window
{
    uint16_t width;
    uint16_t height;
    codepoint_t *field;
    uint32_t target_fps;
};

extern struct window *g_window;
#endif // TYPES_H
