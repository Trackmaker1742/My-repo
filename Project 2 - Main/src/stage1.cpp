#include "stage1.h"

#include "enemy.h"

#include <iostream>
#include <vector>

stage1::stage1(int w, int h, char l, char r, char t, char b, int ec) : stage(w, h, l, r, t, b, ec)
{

}

std::vector<enemy> enemy_arr;

void stage1::assign_enemy(stage& stageholder)
{
    stage::assign_enemy(stageholder);
    for (int i = 0; i < stageholder.getEnemyCount() / 2 + 1; i++)
    {
        // enemy pawn(1);
        enemy_arr.push_back(enemy());
        enemy_arr[i].setY(0);
        enemy_arr[i].setX(i * 6 + 5);
    }
    for (int i = stageholder.getEnemyCount() / 2; i < stageholder.getEnemyCount(); i++)
    {
        // enemy pawn(1);
        enemy_arr.push_back(enemy());
        enemy_arr[i].setY(3);
        enemy_arr[i].setX(i * 6 + 2 - 7 * 6);
    }
}

stage1::~stage1()
{

}
