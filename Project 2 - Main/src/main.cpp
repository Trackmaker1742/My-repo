#include "game.h"

#include "stage1.h"

#include "player.h"
#include "enemy.h"

#include <iostream>
#include <windows.h>
#include <vector>
#include <chrono>
#include <thread>

int main()
{
    game game;
    stage1 stage;
    player hound;
    enemy enemy1;
    game::Setup(stage, hound);

    using namespace std::chrono;
    using frame_duration = duration<int, std::ratio<1,60>>;

    auto next_frame = steady_clock::now() + frame_duration{1};

    while (!game::gameover)
    {
        if (!hound.getState())
        {
            hound.setHealth(hound.getHealth());
            hound.frame_counter++;
        }
        if (hound.frame_counter == 120)
        {
            hound.setHealth(1);
            hound.frame_counter = 0;
            hound.setState(true);
        }
        // Sleep(30);
        hound.Input(stage, hound);
        game.Draw(stage, hound, enemy1);
        game.Logic(stage, hound, enemy1);

        std::this_thread::sleep_until(next_frame);
        next_frame += frame_duration{1};
    }

    std::cout << "\033[2J\033[1;1H";

    std::cout << "Score: " << game::score;

    return 0;
}
