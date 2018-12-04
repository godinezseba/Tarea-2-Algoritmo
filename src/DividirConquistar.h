#include "Avion.h"
#include "MergeSort.h"
#include <iostream>

using namespace std;
class cercanos{
    private:
        avion *A;
        avion *B;
        float distancia;
    public:
        cercanos();
        ~cercanos();
        void setValores(avion, avion, float);
        float getDistancia();
        void printValues();

};

cercanos::cercanos(){
    A = new avion();
    B = new avion();
    distancia = -1;
}

cercanos::~cercanos(){
    // delete
}

void cercanos::setValores(avion X, avion Y, float l){
    this->A = X;
    this->B = Y;
    distancia = l;
}

float cercanos::getDistancia(){
    return this->distancia;
}

cercanos *cantidados(avion *Arreglo,cercanos *Solucion, int izq,int derecho){
    cantiados *respuesta;
    return respuesta;
}
void cercanos::printValues(){
    cout << A.getX() << " " << A.getY() << endl << B.getX() << " " << B.getY() << endl; 
}

cercanos *cercaaux(avion *Arr,int izq, int der){
    int i, i1, i2, curr, med = (izq + der)/2;
    cernanos *sol;
    


    if(der - izq == 1) {
        cernanos *sol = new cernanos();
        sol.setValores(Arr[izq],Arr[der],distancia(Arr[izq],Arr[der]));
        return sol;
    }

    cercanos *sol_izq = cercaaux(Arr,izq, med, sol);
    cercanos *sol_der = cercaaux(Arr,med+1,der, sol);

    if ( sol_izq.getDistancia() > sol_der.getDistancia()){
        delete sol_izq;
        cercanos *sol_med= cantidados(Arr,sol_der,izq,der);
        if(sol_med.getDistancia() > sol_der.getDistancia()){
            delete sol_med;
            return sol_der;
        }
        else{
            delete sol_der;
            return sol_med;
        }
    }
    else {
        delete sol_der;
        cercanos *sol_med= cantidados(Arr,sol_izq,izq,der);
        if(sol_med.getDistancia() > sol_izq.getDistancia()){
            delete sol_med;
            return sol_izq;
        }
        else{
            delete sol_izq;
            return sol_med;
        }

    }



}

cercanos cerca(avion *A, int n){
    mergeSort(A, n);


    return NULL;
}