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

    cout << "Podaj liczbe a: \n";
    cin >> a;
        
    cout << "Podaj krok h: \n";
    cin >> h;

    cout << "Podaj ilość powtórzeń n: \n";
    cin >> n;

    for( int i=0 ; i<=n ; i++) {
        //   result = sin (param*PI/180);
        //   Tworze argumenty dla funkcji zgodnie ze wzorem: x=a, a+h, ..., a+n*h
        x = a+h*i;
        //  Obliczam wartośc funkcji ze wzoru: f = 1/3*sin( pi * x ) + 1/7 +log(x);
        y = (1/3)*sin(M_PI*x)+(1/7)+log10(x);
        //  Wypisuję wynik
        cout << "Dla n = " << i << " x wynosi : " << x << " wartość funkcji wynosi = " << y << "\n" ;
    }

    system("pause");
    return 0;
}
