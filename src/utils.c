#include "headers/utils.h"

size_t write_utf8_fwrite(const codepoint_t *codepoints, size_t count, FILE *stream)
{
    unsigned char buffer[BUFFER_SIZE];
    size_t total_bytes = 0;
    size_t buffer_index = 0;

    for (size_t i = 0; i < count; i++)
    {
        codepoint_t c = codepoints[i];

        if (buffer_index >= BUFFER_SIZE - 4)
        {
            fwrite(buffer, 1, buffer_index, stream);
            total_bytes += buffer_index;
            buffer_index = 0;
        }

        if (c < 0x80)
        {
            buffer[buffer_index++] = c;
        }
        else if (c < 0x800)
        {
            buffer[buffer_index++] = 0xC0 | (c >> 6);
            buffer[buffer_index++] = 0x80 | (c & 0x3F);
        }
        else if (c < 0x10000)
        {
            buffer[buffer_index++] = 0xE0 | (c >> 12);
            buffer[buffer_index++] = 0x80 | ((c >> 6) & 0x3F);
            buffer[buffer_index++] = 0x80 | (c & 0x3F);
        }
    }

    if (buffer_index > 0)
    {
        fwrite(buffer, 1, buffer_index, stream);
        total_bytes += buffer_index;
    }

    return total_bytes;
}

void hide_cursor(void)
{
    fputs("\x1b[?25l", stdout);
}

void show_cursor(void)
{
    fputs("\x1b[?25h", stdout);
}

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}
