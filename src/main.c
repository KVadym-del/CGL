#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#include "headers/core.h"

int main()
{
    create_window();

    hide_cursor();
    fill_window_field(FULL_BLOCK);
    auto window = get_window();

    char key;
    LOOP(
        if (kbhit()) {
            key = getchar();
            if (key == 'q')
            {
                should_close = true;
            }
        } for (size_t x = 0; x < window->width; x++) {
            for (size_t y = 0; y < window->height; y++)
            {
                window->field[x * window->height + y] = rand() % 2 ? FULL_BLOCK : ' ';
            }
            if (x != window->width - 1)
            {
                window->field[x * window->height + window->height - 1] = '\n';
            }
        }

        write_utf8_fwrite(window->field, window->width * window->height, stdout);)

    show_cursor();
    close_window();

    return 0;
}
