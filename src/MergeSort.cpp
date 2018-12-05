// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
#include "Avion.h"

void mergeSortauxX(avion *A, avion *temp, int izq, int der){
    int i, i1, i2, curr, med = (izq + der)/2;
    if(izq == der) return;

    mergeSortauxX(A, temp, izq, med);
    mergeSortauxX(A, temp, med+1, der);

    for(int i = izq; i <= der; i++) temp[i] = A[i];

    i1 = izq; i2 = med + 1;

    
    for(int i = izq; i <= der; i++){
        if(i1 == med + 1) A[i] = temp[i2++];
        else if(i2 > der) A[i] = temp[i1++];
        else if (temp[i1].getX() >= temp[i2].getX() ) A[i] = temp[i1++];
        else A[i] = temp[i2++];
    }
}

void mergeSortX(avion *A, int n){
    avion *temp = new avion[n+1];
    mergeSortauxX(A, temp, 0, n);
    delete temp;
}

void mergeSortauxY(avion *A, avion *temp, int izq, int der){
    int i, i1, i2, curr, med = (izq + der)/2;
    if(izq == der) return;

    mergeSortauxY(A, temp, izq, med);
    mergeSortauxY(A, temp, med+1, der);

    for(int i = izq; i <= der; i++) temp[i] = A[i];

    i1 = izq; i2 = med + 1;

    
    for(int i = izq; i <= der; i++){
        if(i1 == med + 1) A[i] = temp[i2++];
        else if(i2 > der) A[i] = temp[i1++];
        else if (temp[i1].getY() >= temp[i2].getY() ) A[i] = temp[i1++];
        else A[i] = temp[i2++];
    }
}

void mergeSortY(avion *A, int n){
    avion *temp = new avion[n+1];
    mergeSortauxY(A, temp, 0, n);
    delete temp;
}

main(int argc, char const *argv[])
{
    avion *A = new avion[10];
    
    for(int i = 0; i < 10; i++)
    {
        A[i] = avion((i*7+13)%4,i+1);
    }
    
    printArreglo(A, 10);

    mergeSortX(A, 9);
    
    printArreglo(A, 10);
    return 0;
}
