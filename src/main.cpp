#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MergeSort.h"
#include <iostream>

using namespace std;

main(int argc, char const *argv[]){
    avion *A = new avion[10];
    avion *temp = new avion[10];
    for(int i = 0; i < 10; i++)
    {
        A[i] = avion((i*7+13)%4,i+1);
    }
    for(int i = 0; i < 10; i++)
    {
        cout << "Valor de x: " << A[i].getX() << " Valor de y: " << A[i].getY() << endl;
    }
    cout << "TEMPORAL" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << "Valor de x: " << temp[i].getX() << " Valor de y: " << temp[i].getY() << endl;
    }
    for(int i = 0; i < 10; i++) temp[i] = A[i];
        cout << "CAMBIO TEMPORAL" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << "Valor de x: " << temp[i].getX() << " Valor de y: " << temp[i].getY() << endl;
    }
    mergeSort(A, temp, 0, 9);
    cout << "DESPUES" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << "Valor de x: " << A[i].getX() << " Valor de y: " << A[i].getY() << endl;
    }
    return 0;
}
