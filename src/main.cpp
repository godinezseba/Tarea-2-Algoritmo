#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "DividirConquistar.h"

using namespace std;

main(int argc, char const *argv[]){
    
    
    int s;
    int u;
    float i;
    float j; 
    avion *A;
    avion *resp;
	while(cin >> s){
        A = new avion[s];

        for(u = 0; u< s; u++){
            cin >> i >> j;
            A[u].set(i,j);
            
        }
        //resp =cercanos(A,s);

        delete[] A; 
	}

    return 0;
}
