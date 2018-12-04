// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
#include "Avion.h"

void mergeSort(avion *A, avion *temp, int izq, int der){
    int i, i1, i2, curr, med = (izq + der)/2;
    if(izq == der) return;

    mergeSort(A, temp, izq, med);
    mergeSort(A, temp, med+1, der);

    for(int i = izq; i < der; i++) temp[i] = A[i];

    i1 = izq; i2 = med + 1;

    
    for(int i = izq; i < der; i++){
        if(i1 == med + 1) A[i] = temp[i2++];
        else if(i2 > der) A[i] = temp[i1++];
        else if (temp[i1].getX() >= temp[i2].getX() ) A[i] = temp[i1++];
        else A[i] = temp[i2++];
    }
} 