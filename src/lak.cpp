#include "lak.h"

namespace lak
{
    glWindow_t CreateWindow(const char *title, vec2i_t size, bool doubleBuffered,
        uint8_t colourSize, uint8_t depthSize, uint8_t stencilSize, int display)
    {
        glWindow_t result;

        assert(SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG) == 0);
        assert(SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE) == 0);
        assert(SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, doubleBuffered) == 0);
        assert(SDL_GL_SetAttribute(SDL_GL_RED_SIZE, colourSize) == 0);
        assert(SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, colourSize) == 0);
        assert(SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, colourSize) == 0);
        assert(SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, depthSize) == 0);
        assert(SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, stencilSize) == 0);
        assert(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3) == 0);
        assert(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2) == 0);

        result.size = size;

        SDL_GetCurrentDisplayMode(display, &result.mode);

        result.window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            size.x, size.y, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

        result.context = SDL_GL_CreateContext(result.window);

        assert(gl3wInit() == GL3W_OK);

        SDL_GL_MakeCurrent(result.window, result.context);

        if (SDL_GL_SetSwapInterval(-1) == -1)
            assert(SDL_GL_SetSwapInterval(1) == 0);

        return result;
    }

    void CloseWindow(glWindow_t &window)
    {
        SDL_GL_DeleteContext(window.context);
        SDL_DestroyWindow(window.window);
    }
}

#include "math.cpp"
#include "file.cpp"

extern "C" {
#include <GL/gl3w.c>
}
