#include "MergeSort.h"
#include <iostream>

using namespace std;
class cercanos{
    private:
        avion A;
        avion B;
        float distancia;
    public:
        cercanos();
        ~cercanos();
        void setValores(avion , avion , float);
        float getDistancia();
        void printValues();

};

cercanos::cercanos(){
    A = avion();
    B = avion();
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

cercanos cantidados(avion *Arreglo,cercanos solucion, int izq, int derecho){
    int sol_izquierdo, sol_derecho;
    avion *temp;

    for(int i = derecho+1-izq; i >= izq && solucion.getDistancia() < compareX(Arreglo[derecho+1-izq], Arreglo[i]); i--)
        sol_izquierdo = i;

    for(int i = derecho+1-izq; i <= derecho && solucion.getDistancia() < compareX(Arreglo[derecho+1-izq], Arreglo[i]); i++)
        sol_derecho = i;

    temp = new avion[sol_derecho+1-sol_izquierdo];

    for(int i = sol_izquierdo, j = 0; i <= sol_derecho; i++, j++){
        temp[j] = Arreglo[i];
    }
    mergeSort(temp, derecho+1-izq, antesQueY);

    for(int i = 1; i <= derecho+1-izq; i++){
        int j = i-1;
        while(compareY(temp[j], temp[i]) < solucion.getDistancia()){
            if(distancia(temp[i], temp[j]) < solucion.getDistancia()){
                solucion.setValores(temp[i], temp[j], distancia(temp[i], temp[j]));
            }
        }
    }
    return solucion;
}
void cercanos::printValues(){
    cout << A.getX() << " " << A.getY() << endl << B.getX() << " " << B.getY() << endl; 
}

cercanos cercaaux(avion *Arr,int izq, int der){
    int med = (izq + der)/2;

    if(der - izq == 1) {
        cercanos sol = cercanos();
        sol.setValores(Arr[izq],Arr[der],distancia(Arr[izq],Arr[der]));
        return sol;
    }

    cercanos sol_izq = cercaaux(Arr, izq, med);
    cercanos sol_der = cercaaux(Arr, med+1, der);

    if ( sol_izq.getDistancia() > sol_der.getDistancia()){
        return cantidados(Arr,sol_der,izq,der);
    }
    else {
        return cantidados(Arr,sol_izq,izq,der);
    }
}

cercanos cerca(avion *A, int n){
    mergeSort(A, n, antesQueX);

    return cercaaux(A, 0, n-1);
}