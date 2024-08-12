#ifndef UTILS_H
#define UTILS_H

#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#include "types.h"
#include "values.h"
#include "window.h"

size_t write_utf8_fwrite(const codepoint_t *codepoints, size_t count, FILE *stream);

void hide_cursor(void);
void show_cursor(void);

int kbhit(void);

#endif // UTILS_H
