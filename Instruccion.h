#ifndef PROYECTOFINAL_INSTRUCCION_H
#define PROYECTOFINAL_INSTRUCCION_H

#include "Tipos.h"

class Instruccion{
private:
    entero numero_robot;
    entero operacion;//1 ingresar, 2 quitar
    entero destino_x;
    entero destino_y;
    entero producto;//1 disco,2 libro.
public:
    Instruccion(){
    }
    Instruccion(entero numero_robot,
                entero operacion,
                entero destino_x,
                entero destino_y,
                entero producto
    ){
        this->numero_robot=numero_robot;
        this->operacion=operacion;
        this->destino_x=destino_x;
        this->destino_y=destino_y;
        this->producto=producto;
    }

    entero  getNumero_Robot(){
        return this->numero_robot;
    }
    entero  getOperacion(){
        return  this->operacion;
    }
    entero getDestino_x(){
        return  this->destino_x;
    }
    entero getDestino_y(){
        return this->destino_y;
    }
    entero getProducto(){
        return  this->producto;
    }
};

#endif //PROYECTOFINAL_INSTRUCCION_H
