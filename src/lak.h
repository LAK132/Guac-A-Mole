
#include <assert.h>

#include "vec.h"
#include "math.h"
#include "file.h"

#define SDL_MAIN_HANDLED
#include <SDL.h>

extern "C" {
#include <GL/gl3w.h>
}

#ifndef LAK_H
#define LAK_H

namespace lak
{
    struct glWindow_t
    {
        SDL_DisplayMode mode;
        SDL_Window *window;
        SDL_GLContext context;
        vec2u32_t size;
    };

    glWindow_t CreateWindow(
        const char *title,
        vec2i_t size,
        bool doubleBuffered = false,
        uint8_t colourSize = 8,
        uint8_t depthSize = 24,
        uint8_t stencilSize = 8,
        int display = 0
    );

    void CloseWindow(
        glWindow_t &window
    );
}

#endif // LAK_H