#ifndef ENEMY_H
#define ENEMY_H

#include "ship.h"
#include "bullet.h"

class bullet;

class enemy: public ship
{
    private:
        int health;

    public:
        enemy(int health = 20, int width = 3, int height = 2);

        int enemy_difficulty = 5;

        void setHealth(int h);
        int getHealth();

        std::vector<int> enemy_sprite_x[2];
        std::vector<int> enemy_sprite_y;

        void enemy_sprite_ini(std::vector<enemy>& enemy_arr);

        char sprite = '#';
        char bullet_sprite = 'o';

        std::vector<bullet> enemy_bullet_arr;

        void enemy_fire(std::vector<bullet>& bullet_arr, std::vector<enemy>& enemy_arr, int enemy_num);
        void enemy_movement(enemy& enemy0);

        virtual ~enemy();
};

#endif
