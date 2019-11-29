#ifndef PROYECTOFINAL_MOVIMIENTOS_H
#define PROYECTOFINAL_MOVIMIENTOS_H

#include "Tipos.h"

class Movimientos{

private:
    entero secuencia;//correlativo
    entero robot;
    entero pos_x;
    entero pos_y;
    entero condicion; //0 home, 1 transito, 2, destino
public:
    Movimientos(){
    }
    Movimientos(entero secuencia, entero robot , entero pos_x,entero pos_y , entero codicion){
        this->secuencia=secuencia;
        this->robot=robot;
        this->pos_x=pos_x;
        this->pos_y=pos_y;
        this->condicion=codicion;
    }
    entero getSecuencia(){
        return  secuencia;
    }
    entero getRobot(){
        return robot;
    }
    entero  getPos_x(){
        return pos_x;
    }
    entero getPos_y(){
        return  pos_y;
    }
    entero getCondicion(){
        return  condicion;
    }



};

#endif //PROYECTOFINAL_MOVIMIENTOS_H
