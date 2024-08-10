#include "headers/rendering.h"
#include "headers/types.h"

void fill_window_field(codepoint_t codepoint)
{
    if (g_window == NULL)
    {
        perror("Window is not initialized");
        exit(1);
    }
    for (size_t i = 0; i < g_window->width * g_window->height; i++)
    {
        g_window->field[i] = codepoint;
    }
}
