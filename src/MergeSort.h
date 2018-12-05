#include "Avion.h"

void mergeSortaux(avion *A, avion *temp, int izq, int der, bool (*func)(avion, avion)){
    int i1, i2, med = (izq + der)/2;
    if(izq == der) return;

    mergeSortaux(A, temp, izq, med, func);
    mergeSortaux(A, temp, med+1, der, func);

    for(int i = izq; i <= der; i++) temp[i] = A[i];

    i1 = izq; i2 = med + 1;

    
    for(int i = izq; i <= der; i++){
        if(i1 == med + 1) A[i] = temp[i2++];
        else if(i2 > der) A[i] = temp[i1++];
        else if (func(A[i1], A[i2])) A[i] = temp[i1++];
        else A[i] = temp[i2++];
    }
}

void mergeSort(avion *A, int n, bool (*func)(avion, avion)){
    avion *temp = new avion[n];
    mergeSortaux(A, temp, 0, n-1, func);
    delete[] temp;
}

