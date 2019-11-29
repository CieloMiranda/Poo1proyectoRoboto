#include <iostream>
#include "Robot.h"
#include "Almacen.h"
#include "Instruccion.h"

int main() {

  

    Almacen almacen(4,5);
    Robot* robot1= new Robot(0,3,1);// posx, posy,idrobot
    Robot* robot2= new Robot(2,3,2);
    Robot* robot3= new Robot(3,0,3);
    
  

    almacen.adicionarRobot(robot1);
    almacen.adicionarRobot(robot2);
    almacen.adicionarRobot(robot3);
    

    //Operaciones : 1--Aregregar, 2-quitar.
    vector<Instruccion> intrucciones;
    intrucciones.push_back({ Instruccion(1,1,2,0,1)});//robot:1,operacion: 2,destino_x:2,destinoY:0,producto: 1 --disco
    intrucciones.push_back({ Instruccion(2,1,2,0,1)});
    //intrucciones.push_back({ Instruccion(2,1,3,3,2)});
    //intrucciones.push_back({ Instruccion(3,2,2,0,1)});





//realiza las intrucciones y los movimientos
    for (int i=0; i<intrucciones.size();i++){
             Instruccion ins=intrucciones[i];
             almacen.MovimientodeRobot(ins.getNumero_Robot(),ins.getDestino_x(),ins.getDestino_y(),ins.getOperacion(),ins.getProducto());
    }

//imprime los caminos de los robots.
//almacen.getRobots() retorna el vecto de los robots de almacen.

    for(int j=0;j<almacen.getRobots().size();j++){
             cout<<"Robot: "<<almacen.getRobots()[j]->getId()<<endl;
             for (int x=0; x<almacen.getRobots()[j]->getMovimientos().size();x++){
                 Movimientos mov= almacen.getRobots()[j]->getMovimientos()[x];
                 cout<<"Correlativo:"<<mov.getSecuencia()<<endl;
                 cout<<"Posicion:("<<mov.getPos_x()<<","<<mov.getPos_y()<<")"<<endl;
                 cout<<"Condicion: "<< (mov.getCondicion()==0?"Home":(mov.getCondicion()==1?"Transito":"Destino"))<<endl;
             }
             cout<<endl;
    }

//imprime el almacen y la cantidad de elementos en cada celda.
   cout<<"Almacen:"<<endl;
   for( int i=0;i<almacen.getPlano().size();i++){
        for(int j=0; j<almacen.getPlano()[i].size();j++){
            cout<<"Slot:("<<i<<","<<j<<")"<<endl;
            cout<< "Cantidad: "<<almacen.getPlano()[i][j].size()<<endl;
            if(almacen.getPlano()[i][j].size()>0){
                cout<<"Tipo Producto: "<<(almacen.getPlano()[i][j][0]==1?"Discos":"Libros")<<endl;
            }
        }
        cout<<endl;
   }


   
   for( int i=0;i<almacen.getRobots().size();i++){
        delete almacen.getRobots()[0];
   }


    return 0;
}