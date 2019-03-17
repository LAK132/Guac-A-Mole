#include "main.h"

game_t Game;

int main()
{
    SDL_SetMainReady();
    assert(SDL_Init(SDL_INIT_EVERYTHING) == 0);

    Game.window = lak::CreateWindow("Guac-A-Mole", {1280,720}, true);

    Game.perfFreq = SDL_GetPerformanceFrequency();
    Game.perfCount = SDL_GetPerformanceCounter();

    while (Game.running)
    {
        for (SDL_Event event; SDL_PollEvent(&event); HandleEvent(event));



        FinishFrame();
    }

    lak::CloseWindow(Game.window);

    SDL_Quit();

    return 0;
}

void HandleEvent(SDL_Event &event)
{
    switch (event.type)
    {
        case SDL_QUIT: Game.running = false; break;

        case SDL_WINDOWEVENT: switch (event.window.event) {
            case SDL_WINDOWEVENT_RESIZED:
            case SDL_WINDOWEVENT_SIZE_CHANGED: {
                Game.window.size.x = (uint32_t)event.window.data1;
                Game.window.size.y = (uint32_t)event.window.data2;
            } break;
            default: break;
        } break;

        default: break;
    }
}

void FinishFrame()
{
    const float targetFrameTime = 1.0f / (float) Game.targetFrameFreq;

    float frameTimeError = Game.frameTime - targetFrameTime;
    if (frameTimeError < 0.0f)
        frameTimeError = 0.0f;
    else if (frameTimeError > 0.0f)
        frameTimeError = lak::mod(frameTimeError, targetFrameTime);

    const uint64_t prevPerfCount = Game.perfCount;
    do {
        Game.perfCount = SDL_GetPerformanceCounter();
        Game.frameTime = (float)(frameTimeError + ((double)(Game.perfCount - prevPerfCount) / (double)Game.perfFreq));
        std::this_thread::yield();
    } while (Game.frameTime < targetFrameTime);
}

#include "lak.cpp"