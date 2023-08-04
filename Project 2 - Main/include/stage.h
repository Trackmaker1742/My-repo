#ifndef STAGE_H
#define STAGE_H

class stage
{
    private:
        int width;
        int height;

        char left_border;
        char right_border;
        char top_border;
        char bottom_border;

        int enemy_count;

    public:
        stage(int w = 0, int h = 0, char l = ' ', char r = ' ', char t = ' ', char b = ' ', int ec = 0);

        void setWidth(int w);
        int getWidth();

        void setHeight(int h);
        int getHeight();

        void setLeftBorder(char l);
        char getLeftBorder();

        void setRightBorder(char r);
        char getRightBorder();

        void setTopBorder(char t);
        char getTopBorder();

        void setBottomBorder(char b);
        char getBottomBorder();

        void setEnemyCount(int ec);
        int getEnemyCount();

        virtual void assign_enemy(stage &stageholder);

        virtual ~stage();
};

#endif
