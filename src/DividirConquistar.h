#include "Avion.h"
#include "MergeSort.h"

avion *cercanos(avion *A, int n){
    mergeSort(A, new avion[n], 0, n);
}