#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "types.h"

void create_window();
void close_window();

void target_fps(int fps);

struct window *get_window();

#endif // WINDOW_H
