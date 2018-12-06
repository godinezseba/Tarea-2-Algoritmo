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
        void printDebug();

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
    this->distancia = l;
}

float cercanos::getDistancia(){
    return this->distancia;
}

void cercanos::printValues(){
    
    if (A.getX() < B.getX()) {
        cout << A.getX() << " " << A.getY() << "\n" << B.getX() << " " << B.getY() << endl;
    }
    else if (A.getX() > B.getX()) {
        cout << B.getX() << " " << B.getY() << "\n" << A.getX() << " " << A.getY() << endl;
    }
    else{
        if (A.getY() < B.getY()) {
            cout << A.getX() << " " << A.getY() << "\n" << B.getX() << " " << B.getY() << endl;
        }
        else{
            cout << B.getX() << " " << B.getY() << "\n" << A.getX() << " " << A.getY() << endl;
        }
    }
}

void cercanos::printDebug(){
    A.printValues();
    B.printValues();
    cout << this->distancia << endl; 
}

cercanos cantidados(avion *Arreglo,cercanos solucion, int izq, int derecho){
    int sol_izquierdo = izq, sol_derecho = derecho;
    avion *temp;

    //si la distancia de la coordenada x a la del punto del medio del arreglo es menor a la minima
    //clasifica como candidato
    for(int i = derecho+1-izq; i >= izq && solucion.getDistancia() < compareX(Arreglo[derecho+1-izq], Arreglo[i]); i--)
        sol_izquierdo = i;

    for(int i = derecho+1-izq; i <= derecho && solucion.getDistancia() < compareX(Arreglo[derecho+1-izq], Arreglo[i]); i++)
        sol_derecho = i;

    temp = new avion[sol_derecho+1-sol_izquierdo];

    for(int i = sol_izquierdo, j = 0; i <= sol_derecho; i++, j++){
        temp[j] = Arreglo[i];
    }

    //ordena los cantidatos respecto a la coodenada y
    mergeSort(temp, sol_derecho+1-sol_izquierdo, antesQueY);

    //calcula la distancia entre todos los cantidatos y se queda con el menor
    for(int i = 0; i <= sol_derecho+1-sol_izquierdo; i++){
        for(int j = i+1; j < sol_derecho+1-sol_izquierdo && compareY(temp[j], temp[i]) < solucion.getDistancia(); j++){
            if(distancia(temp[i], temp[j]) < solucion.getDistancia()){
                solucion.setValores(temp[i], temp[j], distancia(temp[i], temp[j]));
            }
        }
    }

    delete[] temp;
    return solucion;
}

cercanos cercaaux(avion *Arr,int izq, int der){
    int med = (izq + der)/2;
    
    //punto de termino
    if(der - izq == 1) {
        
        cercanos sol = cercanos();
        sol.setValores(Arr[izq],Arr[der],distancia(Arr[izq],Arr[der]));
        return sol;
    }
    
    // recursivamente obtiene la minima distancia entre ambas mitades
    cercanos sol_izq = cercaaux(Arr, izq, med);
    cercanos sol_der = cercaaux(Arr, med, der);

    // busca cantidatos a minimo con un elemento en cada mitad
    if ( sol_izq.getDistancia() > sol_der.getDistancia()){
        return cantidados(Arr, sol_der, izq, der);
    }
    else {
        return cantidados(Arr, sol_izq, izq, der);
    }
}

cercanos cerca(avion *A, int n){
    

    if (n == 1){
        cercanos resp = cercanos();
        resp.setValores(A[0],A[0],0);
        return resp;
    }
    //Los ordena con respecto a la coordenada x
    mergeSort(A, n, antesQueX);
    return cercaaux(A, 0, n-1);
}