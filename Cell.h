#ifndef PROYECTOFINAL_CELL_H
#define PROYECTOFINAL_CELL_H

#include "Tipos.h"
class Cell{
    int x;
    int y;
public:
    int getx(){return x;}
    int gety(){return y;}
    void setx(int x){this->x=x;}
    void sety(int y){this->y=y;}

    bool operator==(Cell o)
    {
        return x==o.x && y==o.y;
    }
    Cell operator=(Cell o)
    {x=o.x;
        y=o.y;
        return *this;
    }

    Cell(int x,int y):x(x),y(y){}
    Cell():x(0),y(0){}
};


#endif //PROYECTOFINAL_CELL_H
