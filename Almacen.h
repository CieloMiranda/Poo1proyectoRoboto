#ifndef PROYECTOFINAL_ALMACEN_H
#define PROYECTOFINAL_ALMACEN_H

#include "Tipos.h"
#include "Robot.h"

class  Almacen{
private:
    entero  m_Altura;
    entero  m_Ancho;
    vector<vector<vector<entero>>> m_plano;
    vector<Robot*> m_Robots;
    void resizePlano(entero m_Altura,entero m_Ancho){
        for(int i = 0; i<m_Altura; i++)
           {
               vector<vector<int>> myvector;
               for(int j = 0; j<m_Ancho; j++)
               {
                   vector<int> elementos;
                   myvector.push_back(elementos);
               }
               m_plano.push_back(myvector);
           }
   }
public:
   Almacen(){}
   Almacen( entero m_Altura, entero m_Ancho){
       resizePlano(m_Altura,m_Ancho);
   }
   void adicionarRobot(Robot* pRobot) {
        m_Robots.push_back(pRobot);
    }
    vector<vector<vector<entero>>> getPlano(){
        return m_plano;
    }
    vector<Robot *> getRobots(){
        return  m_Robots;
    }

    map<int,int> Obtaculos(entero robot_origen){
        map<int,int> obtaculos;
            for(int i=0; i<this->m_Robots.size();i++){
                    if(i!=robot_origen-1){
                        obtaculos.emplace(m_Robots[i]->getXpos(),m_Robots[i]->getYpos());
                    }
            }
        return  obtaculos;
    }

    void MovimientodeRobot(entero robot,entero x_destino,entero y_destino, entero operacion,entero elemento){
      //entero robot=id robot.

         m_Robots[robot-1]->moverse(m_plano,x_destino,y_destino,operacion,elemento,Obtaculos(robot));

    }

};


#endif //PROYECTOFINAL_ALMACEN_H
