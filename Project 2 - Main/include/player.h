#ifndef PLAYER_H
#define PLAYER_H

#include "ship.h"
#include "bullet.h"

#include <vector>

class stage;
class bullet;

class player: public ship
{
    private:
        int health;
        int state;

    public:
        player(int health = 3, int width = 1, int height = 2);

        void setHealth(int h);
        int getHealth();

        void setState(int s);
        int getState();

        void player_sprite_ini(player& player0);

        char top_sprite = 'A';
        char bottom_sprite = 'V';

        void player_bullet_ini(std::vector<bullet>& bullet_arr, player& player0);

        static char invul_sprite;
        char bullet_sprite = '.';

        void Input(stage& stageholder, player& player);

        int frame_counter = 0;

        virtual ~player();
};

#endif
