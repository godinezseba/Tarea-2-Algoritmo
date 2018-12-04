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

    printArreglo(A, 9);

    mergeSort(A, temp, 0, 9);
    cout << "DESPUES" << endl;
    printArreglo(A, 9);
    return 0;
}
