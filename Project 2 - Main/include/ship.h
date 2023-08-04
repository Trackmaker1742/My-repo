#ifndef SHIP_H
#define SHIP_H

#include <vector>

class ship
{
    private:
        int coordinate_x;
        int coordinate_y;

        int width;
        int height;

        std::vector<int> vector_coor_x;
        std::vector<int> vector_coor_y;

    public:
        ship(int width = 0, int height = 0);

        bool collision(ship& object);

        // coordinates

        void setX(int x);
        int getX();

        void setY(int y);
        int getY();

        void setVectorCoorX(const std::vector<int> &cx);
        std::vector<int> getVectorCoorX();

        void setVectorCoorY(const std::vector<int> &cy);
        std::vector<int> getVectorCoorY();

        virtual ~ship();
};

#endif
