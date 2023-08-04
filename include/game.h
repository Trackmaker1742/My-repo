#ifndef GAME_H
#define GAME_H

#include "stage.h"

#include "player.h"
#include "enemy.h"

class game
{
    public:
        game();

        static bool gameover;
        static int score;

        static void Setup(stage& stageholder, player& player0);

        void Draw(stage& stageholder, player& player0, enemy& enemy0);
        void Logic(stage& stageholder, player& player0, enemy& enemy0);

        virtual ~game();
};

#endif
