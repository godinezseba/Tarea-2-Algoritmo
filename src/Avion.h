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
        void set(float x, float y);
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

void avion::set(float x, float y){
    this->x = x;
    this->y = y;
    return;
}

float avion::getX(){
    return this->x;
}

float avion::getY(){
    return this->y;
}

void printArreglo(avion *A, int l){
    for(int i = 0; i < l; i++){
        cout << "Valor de x: " << A[i].getX() << " Valor de y: " << A[i].getY() << endl;
    }
}

float distancia(avion a, avion b){
    float A = pow((a.getX() - b.getX()),2);
    float B = pow((a.getY() - b.getY()),2);
    
    return pow(A+B,(1/2)); 
}

float compareX(avion A, avion B){
    return A.getX()- B.getX();
}

float compareY(avion A, avion B){
    return A.getY()- B.getY();
}

bool antesQueX(avion A, avion B){
    return A.getX() >= B.getX();
}
bool antesQueY(avion A, avion B){
    return A.getY() >= B.getY();
}