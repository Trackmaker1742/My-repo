#include "stage.h"

#include <vector>

stage::stage(int w, int h, char l, char r, char t, char b, int ec) : width(w), height(h), left_border(l), right_border(r), top_border(t), bottom_border(b), enemy_count(ec)
{

}

void stage::setWidth(int w)
{
    width = w;
}
int stage::getWidth()
{
    return width;
}

void stage::setHeight(int h)
{
    height = h;
}
int stage::getHeight()
{
    return height;
}

void stage::setLeftBorder(char l)
{
    left_border = l;
}
char stage::getLeftBorder()
{
    return left_border;
}

void stage::setRightBorder(char r)
{
    right_border = r;
}
char stage::getRightBorder()
{
    return right_border;
}

void stage::setTopBorder(char t)
{
    top_border = t;
}
char stage::getTopBorder()
{
    return top_border;
}

void stage::setBottomBorder(char b)
{
    bottom_border = b;
}
char stage::getBottomBorder()
{
    return bottom_border;
}

void stage::setEnemyCount(int ec)
{
    enemy_count = ec;
}
int stage::getEnemyCount()
{
    return enemy_count;
}

void stage::assign_enemy(stage& stageholder)
{

}

stage::~stage()
{

}
