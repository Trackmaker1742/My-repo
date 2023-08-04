#include "ship.h"

#include <vector>

ship::ship(int width, int height) : width(width), height(height)
{
    
}

bool ship::collision(ship& object)
{
    if (coordinate_x < object.coordinate_x + object.width &&
        coordinate_x + width > object.coordinate_x &&
        coordinate_y < object.coordinate_y + object.height &&
        coordinate_y + height > object.coordinate_y)
    {
        return true;
    }
    return false;
}

// coordinates

void ship::setX(int x)
{
    coordinate_x = x;
}
int ship::getX()
{
    return coordinate_x;
}

void ship::setY(int y)
{
    coordinate_y = y;
}
int ship::getY()
{
    return coordinate_y;
}

void ship::setVectorCoorX(const std::vector<int> &cx)
{
    vector_coor_x = cx;
}
std::vector<int> ship::getVectorCoorX()
{
    return vector_coor_x;
}

void ship::setVectorCoorY(const std::vector<int> &cy)
{
    vector_coor_y = cy;
}
std::vector<int> ship::getVectorCoorY()
{
    return vector_coor_y;
}

ship::~ship()
{

}