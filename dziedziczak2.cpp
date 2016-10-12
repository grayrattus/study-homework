#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

class abc {
    double a;
    double b;
    double c;

    public:
    void seta(int i) { a = i; } 
    void setb(int i) { b = i; } 
    void setc(int i) { c = i; } 

    int geta() {return a;  } 
    int getb() {return b;  } 
    int getc() {return c;  } 

};

double *rozwiaz(double a, double b, double c, double *x) {
    double delta;

    delta = b*b-(4*a*c);

    if ( delta > 0 ) {
       x[0] = ((-b)+delta)/(-2*a); 
       x[1] = ((-b)-delta)/(-2*a); 

       return x;
    } else if ( delta == 0 ) {
       x[0] =  
    } else {
    }

}

int main(int argc, char *argv[]){
    cout << "Dziedziczak Artur" << endl;

    double x[2] = {0,0};


    abc zmienne[6];

    zmienne[0].seta(3);
    zmienne[0].setb(6);
    zmienne[0].setc(3);
    
    zmienne[1].seta(2.5);
    zmienne[1].setb(6.6);
    zmienne[1].setc(1.5);
    
    zmienne[2].seta(0.5);
    zmienne[2].setb(0.1);
    zmienne[2].setc(1.5);
    
    zmienne[3].seta(0);
    zmienne[3].setb(2.5);
    zmienne[3].setc(7.5);
    
    zmienne[4].seta(0);
    zmienne[4].setb(0);
    zmienne[4].setc(5.5);
    
    zmienne[5].seta(0);
    zmienne[5].setb(0);
    zmienne[5].setc(0);

    rozwiaz(1,2,3, x);
    
    return 0;
}
