#ifndef CORE_H
#define CORE_H

#include "rendering.h"
#include "utils.h"
#include "window.h"

#define LOOP(X)                                                                                                        \
    bool should_close = false;                                                                                         \
    while (!should_close)                                                                                              \
    {                                                                                                                  \
        X                                                                                                              \
    }

#endif // CORE_H
