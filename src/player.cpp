#include "player.h"

#include "game.h"
#include "ship.h"
#include "bullet.h"

#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>

player::player(int health, int width, int height) : health(health), ship(width, height)
{

}

void player::setHealth(int h)
{
    health = h;
}
int player::getHealth()
{
    return health;
}

void player::setState(int s)
{
    state = s;
}
int player::getState()
{
    return state;
}

std::vector<int> player_sprite_x[2];
std::vector<int> player_sprite_y;

void player::player_sprite_ini(player& player0)
{
    player_sprite_x[0] = {player0.getX()};
    player_sprite_x[1] = {player0.getX()};

    player_sprite_y = {player0.getY(), player0.getY() + 1};
}

char player::invul_sprite = 'v';

std::vector<bullet> player_bullet_arr(1);

void player::player_bullet_ini(std::vector<bullet> &bullet_arr, player &player)
{
    player_bullet_arr[player_bullet_arr.size() - 1].setX(player.getX());
    player_bullet_arr[player_bullet_arr.size() - 1].setY(player.getY() + 1);
}

enum eDirect
{
    SHOOT
};
eDirect action;

void player::Input(stage& stageholder, player& player0)
{
    if ((GetAsyncKeyState(VK_UP) || GetAsyncKeyState(0x57)) && player0.getY() > 0) // w key
    {
        player0.setY(player0.getY() - 1);
    }
    if ((GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(0x53)) && player0.getY() < stageholder.getHeight() - 2) // s key
    {
        player0.setY(player0.getY() + 1);
    }
    if ((GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(0x41)) && player0.getX() > 0) // a key
    {
        player0.setX(player0.getX() - 1);
    }
    if ((GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(0x44)) && player0.getX() < stageholder.getWidth() - 2) // d key
    {
        player0.setX(player0.getX() + 1);
    }
    // if (GetAsyncKeyState(0x45)) // e key
    // {
    //     player.setState(!player.getState());
    // }
    if (GetAsyncKeyState(VK_ESCAPE) || GetAsyncKeyState(0x58)) // x key
    {
        game::gameover = true;
    }
    if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(0x4A)) // j key
    {
        player_bullet_arr.push_back(bullet());
        player0.player_bullet_ini(player_bullet_arr, player0);
        action = SHOOT;
    }
//    if (_kbhit())
//    {
//        switch (_getch())
//        {
//            case 'j':
//            case ' ':
//                bullet::bullet_gen(player_bullet_arr);
//                player::player_bullet_ini(player_bullet_arr, player);
//                action = SHOOT;
//                break;
//        }
//    }

    switch (action)
    {
        case SHOOT:
            for (bullet& bullet : player_bullet_arr)
            {
                bullet.setY(bullet.getY() - 2);
            }
            break;
    }
}

player::~player()
{

}
