#include "Avion.h"
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
        void setValores(avion, avion, float);
        float getDistancia();
        void printValues();

};

cercanos::cercanos(){
    A = avion();
    B = avion();
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

void cercanos::printValues(){
    cout << A.getX() << " " << A.getY() << endl << B.getX() << " " << B.getY() << endl; 
}

cercanos *cercaaux(){
    return NULL;
}

cercanos *cerca(avion *A, int n){
    mergeSort(A, n);
    return NULL;
}