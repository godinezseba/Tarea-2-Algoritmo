// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

class avion{
    private:
        float x;
        float y;
    public:
        avion();
        avion(float x, float y);
        ~avion();
        float getX();
        float getY();
};

avion::avion(){
    this->x = 0;
    this->y = 0;
}

avion::avion(float x, float y){
    this->x = x;
    this->y = y;
}

avion::~avion(){
}

float avion::getX(){
    return this->x;
}

float avion::getY(){
    return this->y;
}
float distancia(avion a, avion b){
    float A = pow((a.getX() - b.getX()),2);
    float B = pow((a.getY() - b.getY()),2);
    
    return pow(A+B,(1/2)); 
}

void printArreglo(avion *A, int l){
    for(int i = 0; i < l; i++){
        cout << "Valor de x: " << A[i].getX() << " Valor de y: " << A[i].getY() << endl;
    }
}

void mergeSort(avion *A, avion *temp, int izq, int der){
    int i, i1, i2, curr, med = (izq + der)/2;
    if(izq == der) return;

    mergeSort(A, temp, izq, med);
    mergeSort(A, temp, med+1, der);

    for(int i = izq; i <= der; i++) temp[i] = A[i];

    i1 = izq; i2 = med + 1;

    
    for(int i = izq; i <= der; i++){
        if(i1 == med + 1) A[i] = temp[i2++];
        else if(i2 > der) A[i] = temp[i1++];
        else if (temp[i1].getX() >= temp[i2].getX() ) A[i] = temp[i1++];
        else A[i] = temp[i2++];
    }
} 