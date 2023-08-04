#ifndef BULLET_H
#define BULLET_H

#include "player.h"
#include "enemy.h"

#include <vector>

class bullet : public ship
{
    public:
        bullet(int width = 1, int height = 1);

        virtual ~bullet();
};

#endif
