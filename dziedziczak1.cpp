#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char *argv[]){
    cout << "Dziedziczak Artur" << endl;

    //a,h - typ rzeczywisty
    //n - typ całkowity
    // pętla for x, y wyświetlić na ekran
    double a, h, x, y;
    int n;

    for (;;){
        cout << "Podaj liczbe a: \n";
        if(cin >> a){
            break;
        }
        cin.clear();
        cin.ignore(512, '\n');
    }
    for (;;){
        cout << "Podaj krok h: \n";
        if(cin >> h){
            break;
        }
        cin.clear();
        cin.ignore(512, '\n');
    }
    for (;;){
        cout << "Podaj ilość powtórzeń n: \n";
        if(cin >> a){
            break;
        }
        cin.clear();
        cin.ignore(512, '\n');
    }
        
    for( int i=0 ; i<=n ; i++) {
        //   result = sin (param*PI/180);
        //   Tworze argumenty dla funkcji zgodnie ze wzorem: x=a, a+h, ..., a+n*h
        x = a+h*i;
        //  Obliczam wartośc funkcji ze wzoru: f = 1/3*sin( pi * x ) + 1/7 +log(x);
        y = (1/3)*sin(M_PI*x)+(1/7)+log10(x);
        //  Wypisuję wynik
        cout << "Dla n = " << i << " x wynosi : " << x << " wartość funkcji wynosi = " << y << "\n" ;
    }

    return 0;
}


// Tutaj trzeba jeszcze dodać sprawdzanie dla n =! liczb naturalnych
