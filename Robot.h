#ifndef PROYECTOFINAL_ROBOT_H
#define PROYECTOFINAL_ROBOT_H

#include "Movimientos.h"
#include "Tipos.h"
#include "Cell.h"

class Robot{
private:
  entero x_home;
  entero y_home;
  entero x_pos;
  entero y_pos;
  vector<Movimientos> Moves;
  entero _id;
  entero correlativo=0;
public:
    Robot(){}
    Robot(entero x_home,entero y_home,entero _id){
        this->x_home=x_home;
        this->y_home=y_home;
        this->x_pos=x_home;
        this->y_pos=y_home;
        this->_id=_id;
    }
    void setXpos( entero x_pos){
        this->x_pos=x_pos;
    }
    void setYpos( entero y_pos){
        this->y_pos=y_pos;
    }
    void setYhome( entero y_home){
        this->y_home=y_home;
    }
    void setXhome( entero x_home){
        this->x_home=x_home;
    }
    void setId( entero _id){
        this->_id=_id;
    }
    void setCorrelativo(entero correlativo){
        this->correlativo=correlativo;
    }
    entero getXpos(){
        return  this->x_pos;
    }
    entero getId(){
        return  this->_id;
    }
    entero getYpos(){
        return  this->y_pos;
    }
    entero getYhome(){
        return  this->y_home;
    }
    entero getXhome(){
        return this->x_home;
    }
    void addMovimiento(Movimientos mov){
        Moves.push_back(mov);
    }
    vector<Movimientos> getMovimientos(){
        return  this->Moves;
    }


    vector<Cell> getShortestPath(Cell ori, Cell dest){

        vector<Cell> res;//este es el camino de celdas a seguir.
        entero mover_x=dest.getx()-ori.getx();// movimientos en x
    
        entero mover_y=dest.gety()-ori.gety();
        //movimientos en y
       
        //agregar al camino una celda, en este caso el origen.
        res.push_back(Cell(ori.getx(),ori.gety()));

        if (mover_x<0){//me voy para la izquierda en x
            while (mover_x!=0){
              //ejemplo mover:-4
              //orgi : 7
                res.push_back(Cell(ori.getx()-1,ori.gety()));
                ori.setx(ori.getx()-1);
                //x:6

                //mover_x=-4+1=-3
                mover_x++;
            }
        }else{
          //me voy para la derecha en x.
            while (mover_x!=0){
                res.push_back(Cell(ori.getx()+1,ori.gety()));
                ori.setx(ori.getx()+1);
                mover_x--;
            }
        }

        if (mover_y<0){
            while (mover_y!=0){
                res.push_back(Cell(ori.getx(),ori.gety()-1));
                ori.sety(ori.gety()-1);
                mover_y++;
            }
        }else{
            while (mover_y!=0){
                res.push_back(Cell(ori.getx(),ori.gety()+1));
                ori.sety(ori.gety()+1);
                mover_y--;
            }
        }

        return res;

    }



    void moverse (vector<vector<vector<entero>>> &plano,entero destino_x, entero destino_y,entero operacion, entero elemento,map<int,int>  obtaculos){


        switch (operacion){
            case 1:
                //cout<<"Elemento:"<<elemento<<endl;
                //es para insertar, tengo que validar que el array este libre o tenga el mismo tipo.
                if( (plano[destino_x][destino_y].size()>0 && plano[destino_x][destino_y][0]==elemento) or plano[destino_x][destino_y].size()==0  ){

                    if(this->getXhome()==this->getXpos() && this->getYhome()==this->getYpos()){
                        //moverte defrente a destino
                        vector<Cell> camino1= getShortestPath(Cell(this->getXpos(),this->getYpos()),Cell(destino_x,destino_y));

                        //recorremos el camino.
                        for(entero i=0;i<camino1.size();i++){
                            setCorrelativo(this->correlativo+1);//primera intancia correlativo 1.
                            if(camino1[i].getx()==this->getXhome() && camino1[i].gety()==this->getYhome()){
                                Movimientos mov(this->correlativo,this->_id,camino1[i].getx(),camino1[i].gety(),0);
                               //0 home, 1 transito, 2, destino
                                addMovimiento(mov);
                            }
                            else if(camino1[i].getx()==destino_x && camino1[i].gety()==destino_y){
                                Movimientos mov(this->correlativo,this->_id,camino1[i].getx(),camino1[i].gety(),2);
                                addMovimiento(mov);
                            }
                            else{
                                Movimientos mov(this->correlativo,this->_id,camino1[i].getx(),camino1[i].gety(),1);
                                addMovimiento(mov);
                            }
                        }
                        //[0,1,2,3,4]
                        //5 
                        //[{0,1},{0,2},{0,3},{0.4}]
                        //4
                        //size()--4 -1=3
                        //seteo la posicion final del camino size()-1
                        setXpos(camino1[camino1.size()-1].getx());
                        setYpos(camino1[camino1.size()-1].gety());
                        //inserto el elemento una vez llegado al destino.
                        plano[destino_x][destino_y].push_back(elemento);
                    } else{
                        //desde posicion moverse a home
                        vector<Cell> camino= getShortestPath(Cell(this->getXpos(),this->getYpos()),Cell(this->getXhome(),this->getYhome()));
                        for(entero i=0;i<camino.size();i++){
                            setCorrelativo(this->correlativo+1);
                            if(i==0){
                                Movimientos mov(this->correlativo,this->_id,camino[i].getx(),camino[i].gety(),2);
                                addMovimiento(mov);
                            }else if(camino[i].getx()==this->getXhome() && camino[i].gety()==this->getYhome()){
                                Movimientos mov(this->correlativo,this->_id,camino[i].getx(),camino[i].gety(),0);
                                addMovimiento(mov);
                            }else{
                                Movimientos mov(this->correlativo,this->_id,camino[i].getx(),camino[i].gety(),1);
                                addMovimiento(mov);
                            }
                        }
                        //seteando a home
                        setXpos(camino[camino.size()-1].getx());
                        setYpos(camino[camino.size()-1].gety());

                        //y luego a destino
                        vector<Cell> camino1= getShortestPath(Cell(this->getXpos(),this->getYpos()),Cell(destino_x,destino_y));
                        for(entero i=0;i<camino1.size();i++){
                            setCorrelativo(this->correlativo+1);
                            if(camino1[i].getx()==this->getXhome() && camino1[i].gety()==this->getYhome()){
                                Movimientos mov(this->correlativo,this->_id,camino1[i].getx(),camino1[i].gety(),0);
                                addMovimiento(mov);
                            }
                            else if(camino1[i].getx()==destino_x && camino1[i].gety()==destino_y){
                                Movimientos mov(this->correlativo,this->_id,camino1[i].getx(),camino1[i].gety(),2);
                                addMovimiento(mov);
                            }
                            else{
                                Movimientos mov(this->correlativo,this->_id,camino1[i].getx(),camino1[i].gety(),1);
                                addMovimiento(mov);
                            }
                        }
                        setXpos(camino1[camino1.size()-1].getx());
                        setYpos(camino1[camino1.size()-1].gety());
                        plano[destino_x][destino_y].push_back(elemento);
                        
                    }
                }

                //tiene que ir a home y luego destino
                break;
            case 2:
                //tengo que validar que tenga el mismo tipo y que tenga valores.
                //tiene que ir a destino y luego a home.
                //es para quitar, tengo que validar que el array tiene elementos y que sean los mismos.
                //para que quitar algo que no hay nada.
                //elemento=1
                //plano[destino_x][destino_y] celda
                //plano[destino_x][destino_y]{1,1,1,1,1} celda

                //plano[destino_x][destino_y].size()>0 el tamaño del arreglo de la celda debe ser mayor a cero. (La pila de elementos de la celda debe tener elementos.)
                //plano[destino_x][destino_y][0] elemento CERO de la celda es igual al element que trato de borrar.

  
                if(plano[destino_x][destino_y].size()>0 and plano[destino_x][destino_y][0]==elemento ){
                        //mover defrente a destino
                        vector<Cell> camino1= getShortestPath(Cell(this->getXpos(),this->getYpos()),Cell(destino_x,destino_y));
                        for(entero i=0;i<camino1.size();i++){
                            setCorrelativo(this->correlativo+1);
                            if(camino1[i].getx()==this->getXhome() && camino1[i].gety()==this->getYhome()){
                                Movimientos mov(this->correlativo,this->_id,camino1[i].getx(),camino1[i].gety(),0);
                                addMovimiento(mov);
                            }
                            else if(camino1[i].getx()==destino_x && camino1[i].gety()==destino_y){
                                Movimientos mov(this->correlativo,this->_id,camino1[i].getx(),camino1[i].gety(),2);
                                addMovimiento(mov);
                            }
                            else{
                                Movimientos mov(this->correlativo,this->_id,camino1[i].getx(),camino1[i].gety(),1);
                                addMovimiento(mov);
                            }
                        }

                        setXpos(camino1[camino1.size()-1].getx());
                        setYpos(camino1[camino1.size()-1].gety());
                        plano[destino_x][destino_y].pop_back();
                        //desde posicion moverse a home

                        vector<Cell> camino= getShortestPath(Cell(this->getXpos(),this->getYpos()),Cell(this->getXhome(),this->getYhome()));
                        for(entero i=0;i<camino.size();i++){
                            setCorrelativo(this->correlativo+1);
                            if(i==0){
                                Movimientos mov(this->correlativo,this->_id,camino[i].getx(),camino[i].gety(),2);
                                addMovimiento(mov);
                            }else if(camino[i].getx()==this->getXhome() && camino[i].gety()==this->getYhome()){
                                Movimientos mov(this->correlativo,this->_id,camino[i].getx(),camino[i].gety(),0);
                                addMovimiento(mov);
                            }else{
                                Movimientos mov(this->correlativo,this->_id,camino[i].getx(),camino[i].gety(),1);
                                addMovimiento(mov);
                            }
                        }
                        //seteando a home
                        setXpos(camino[camino.size()-1].getx());
                        setYpos(camino[camino.size()-1].gety());
                    }
                break;
        }


        /*for(int i=0;i<camino.size();i++){
            cout<<"("<<camino[i].getx()<<", "<<camino[i].gety()<<")"<<endl;
        }*/
    }

};



#endif //PROYECTOFINAL_ROBOT_H
