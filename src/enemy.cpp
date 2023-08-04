#include "enemy.h"

#include "ship.h"
#include "bullet.h"

#include <cstdlib>

enemy::enemy(int health, int width, int height) : health(health), ship(width, height)
{

}

void enemy::setHealth(int h)
{
    health = h;
}
int enemy::getHealth()
{
    return health;
}

extern std::vector<enemy> enemy_arr;

void enemy::enemy_sprite_ini(std::vector<enemy>& enemy_arr)
{
    for (int i = 0; i < enemy_arr.size(); i++)
    {
        enemy_arr[i].enemy_sprite_x[0] = {enemy_arr[i].getX(), enemy_arr[i].getX() + 1, enemy_arr[i].getX() + 2};
        enemy_arr[i].enemy_sprite_x[1] = {enemy_arr[i].getX(), enemy_arr[i].getX() + 1, enemy_arr[i].getX() + 2};

        enemy_arr[i].enemy_sprite_y = {enemy_arr[i].getY(), enemy_arr[i].getY() + 1};
    }
}

enum eDirect
{
    SHOOT
};
eDirect enemy_action;

void enemy::enemy_fire(std::vector<bullet> &bullet_arr, std::vector<enemy> &enemy_arr, int enemy_num)
{
    int random = std::rand() % 100;

    if (random < enemy_arr[enemy_num].enemy_difficulty)
    {
        bullet_arr.push_back(bullet());
        bullet_arr[bullet_arr.size() - 1].setX(enemy_arr[enemy_num].getX() + 1);
        bullet_arr[bullet_arr.size() - 1].setY(enemy_arr[enemy_num].getY());
        enemy_action = SHOOT;
    }

    switch (enemy_action)
    {
    case SHOOT:
        for (bullet& bullet : bullet_arr)
        {
            bullet.setY(bullet.getY() + 1);
        }
        break;
    }
}

//void enemy::ememy_movement()
//{
//
//}

enemy::~enemy()
{

}
