#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include "DividirConquistar.h"

using namespace std;

int main(int argc, char const *argv[]){    
    int s;
    int u;
    float i;
    float j; 
    avion *A;
    cercanos resp;
    cout << fixed << setprecision(1);
	while(cin >> s){
        A = new avion[s];

        for(u = 0; u< s; u++){
            cin >> i >> j;
            A[u].set(i,j);
            
        }
        resp = cerca(A,s);
        resp.printValues();
        cout << endl;
        delete[] A; 
	}

    return 0;
}
