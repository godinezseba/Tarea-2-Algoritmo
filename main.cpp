#include <stdio.h>
#include <math.h>

class avion{
private:
    float x;
    float y;
public:
    avion(float x, float y);
    ~avion();
    float getX();
    float getY();
};

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

main(int argc, char const *argv[]){
    avion a = avion(1,2);
    return 0;
}
