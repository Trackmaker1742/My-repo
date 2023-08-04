#include "game.h"

#include "stage.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"

#include <iostream>
#include <windows.h>
#include <vector>

game::game()
{

}

bool game::gameover;

int game::score;

void game::Setup(stage& stageholder, player& player0)
{
    game::gameover = false;
    game::score = 0;
    player0.setState(true);
    player0.setX(stageholder.getWidth() / 2 - 1);
    player0.setY(stageholder.getHeight() - 2);
    stageholder.assign_enemy(stageholder);
}

void game::Draw(stage& stageholder, player& player0, enemy& enemy0)
{
    // std::cout << "\033[2J\033[1;1H";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});

    // assign player sprite
    extern std::vector<int> player_sprite_x[2];
    extern std::vector<int> player_sprite_y;
    player0.player_sprite_ini(player0);

    extern std::vector<bullet> player_bullet_arr;

    extern std::vector<enemy> enemy_arr;

    enemy0.enemy_sprite_ini(enemy_arr);

    for (int j = 0; j <= stageholder.getWidth(); j++)
    {
        std::cout << stageholder.getTopBorder();
    }
    std::cout << "\n";

    for (int i = 0; i < stageholder.getHeight(); i++)
    {
        for (int j = 0; j < stageholder.getWidth(); j++)
        {
            if (j == 0)
            {
                std::cout << stageholder.getLeftBorder();
            }
            if (j == stageholder.getWidth() - 1)
            {
                std::cout << stageholder.getRightBorder() << "\n";
            }
            else
            {
                bool print = false;
                // player sprite
                for (int k = 0; k < player_sprite_y.size(); k++)
                {
                    if (i == player_sprite_y[k])
                    {
//                        for (int player_coor_x : player_sprite_x[k])
//                        {
//                            if (j == player_coor_x)
//                            {
//                                std::cout << player0.top_sprite;
//                                print = true;
//                                if (print) break;
//                            }
//                        }
                        if (j == player_sprite_x[k][0] && k == 0)
                        {
                            std::cout << player0.top_sprite;
                            print = true;
                            if (print) break;
                        }
                        if (j == player_sprite_x[k][0] && k == 1)
                        {
                            std::cout << player0.bottom_sprite;
                            print = true;
                            if (print) break;
                        }
                    }
                }
                if (print) continue;
                // player bullet sprite
                for (int k = 0; k < player_bullet_arr.size(); k++)
                {
                    if (i == player_bullet_arr[k].getY() && j == player_bullet_arr[k].getX() && !print)
                    {
                        std::cout << player0.bullet_sprite;
                        print = true;
                        if (print) break;
                    }
                }
                if (print) continue;

                // enemy sprite
                for (int k = 0; k < enemy_arr.size(); k++)
                {
                    // enemy object sprite
                    for (int l = 0; l < enemy_arr[k].enemy_sprite_y.size(); l++)
                    {
                        if (i == enemy_arr[k].enemy_sprite_y[l])
                        {
                            for (int enemy_coor_x : enemy_arr[k].enemy_sprite_x[l])
                            {
                                if (j == enemy_coor_x)
                                {
                                    std::cout << enemy0.sprite;
                                    print = true;
                                    if (print) break;
                                }
                            }
                            if (print) break;
                        }
                    }
                    if (print) break;

                    // enemy bullet sprite
                    for (int l = 0; l < enemy_arr[k].enemy_bullet_arr.size(); l++)
                    {
                        if (i == enemy_arr[k].enemy_bullet_arr[l].getY() && j == enemy_arr[k].enemy_bullet_arr[l].getX() && !print)
                        {
                            std::cout << enemy0.bullet_sprite;
                            print = true;
                        }
                        if (print) break;
                    }
                    if (print) break;
                }
                if (print) continue;

                // blank space
                if (!print)
                {
                    std::cout << " ";
                }
            }
        }
    }

    for (int j = 0; j <= stageholder.getWidth(); j++)
    {
        std::cout << stageholder.getBottomBorder();
    }

    std::cout << "\n" << "Health: " << player0.getHealth()
              << "\n" << "Score: " << game::score
              << "\n" << "State: " << player0.getState();
              // << "\n" << enemy_bullet_arr.size()
              // << "\n" << stageholder.getEnemyCount();
}

void game::Logic(stage& stageholder, player& player0, enemy& enemy0)
{
    extern std::vector<enemy> enemy_arr;
    extern std::vector<bullet> player_bullet_arr;

    for (int k = 0; k < stageholder.getEnemyCount(); k++)
    {
        enemy0.enemy_fire(enemy_arr[k].enemy_bullet_arr, enemy_arr, k);
        if (player0.collision(enemy_arr[k]))
        {
            enemy_arr[k].setHealth(enemy_arr[k].getHealth() - 1);

            player0.setHealth(player0.getHealth() - 1);

            // respawn player
            player0.setX(stageholder.getWidth() / 2 - 1);
            player0.setY(stageholder.getHeight() - 2);

            player0.setState(false);
        }
        if (enemy_arr[k].getHealth() == 0)
        {
            enemy_arr.erase(enemy_arr.begin() + k);
        }
        for (int l = 0; l < player_bullet_arr.size(); l++)
        {
            if (player_bullet_arr[l].collision(enemy_arr[k]))
            {
                player_bullet_arr.erase(player_bullet_arr.begin() + l);
                enemy_arr[k].setHealth(enemy_arr[k].getHealth() - 1);
                game::score += 100;
            }
        }

        for (int l = 0; l < enemy_arr[k].enemy_bullet_arr.size(); l++)
        {
            if (enemy_arr[k].enemy_bullet_arr[l].collision(player0))
            {
                enemy_arr[k].enemy_bullet_arr.erase(enemy_arr[k].enemy_bullet_arr.begin() + l);

                player0.setHealth(player0.getHealth() - 1);

                // respawn player
                player0.setX(stageholder.getWidth() / 2 - 1);
                player0.setY(stageholder.getHeight() - 2);

                player0.setState(false);
            }
            if (enemy_arr[k].enemy_bullet_arr[l].getY() == stageholder.getHeight())
            {
                enemy_arr[k].enemy_bullet_arr.erase(enemy_arr[k].enemy_bullet_arr.begin() + l);
            }
        }

        if (enemy_arr[k].getHealth() == 0)
        {
            enemy_arr.erase(enemy_arr.begin() + k);
            stageholder.setEnemyCount(stageholder.getEnemyCount() - 1);
        }
    }

    if (player0.getHealth() == 0 || stageholder.getEnemyCount() == 0)
    {
        game::gameover = true;
    }
}

game::~game()
{

}
