#ifndef STAGE1_H
#define STAGE1_H

#include "stage.h"

class stage1 : public stage
{
    public:
        stage1(int w = 50, int h = 25, char l = '/', char r = '\\', char t = 'W', char b = 'M', int ec = 15);

        void assign_enemy(stage& stageholder) override;

        virtual ~stage1();
};

#endif
