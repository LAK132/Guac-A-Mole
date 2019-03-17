
#include <atomic>
#include <thread>

#include "lak.h"

#ifndef MAIN_H
#define MAIN_H

struct game_t
{
    std::atomic<bool> running = true;

    lak::glWindow_t window;

    uint16_t targetFrameFreq = 60;
    uint64_t perfFreq;
    uint64_t perfCount;
    float frameTime = 0.000001f;
};

extern game_t Game;

void HandleEvent(
    SDL_Event &event
);

void FinishFrame();

#endif // MAIN_H