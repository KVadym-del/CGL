#include "headers/window.h"
#include "headers/types.h"

void create_window()
{
    g_window = (struct window *)malloc(sizeof(struct window));
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    g_window->width = w.ws_row;
    g_window->height = w.ws_col;

    codepoint_t *matrix = (codepoint_t *)malloc(w.ws_row * w.ws_col * sizeof(codepoint_t));
    if (matrix == NULL)
    {
        perror("Failed to allocate memory");
        free(matrix);
        exit(1);
    }
    g_window->field = matrix;
    g_window->target_fps = UINT32_MAX;
    printf("Window generated successfully\n");
}

void close_window()
{
    free(g_window->field);
    free(g_window);
    printf("Window closed successfully\n");
}

struct window *get_window()
{
    return g_window;
}
