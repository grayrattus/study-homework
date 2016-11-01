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
        cout << "Podaj liczbe a: ";
        if(cin >> a && a > 0){
            break;
        }
        cin.clear();
        cin.ignore(512, '\n');
        cout << "a - musi byc > 0\n" ;
    }
    for (;;){
        cout << "Podaj krok h: ";
        if(cin >> h && h >= 0){
            break;
        }
        cin.clear();
        cin.ignore(512, '\n');
        cout << "h - musi byc >= 0\n" ;
    }
    if (h == 0) {
        cout << "Nie musisz podawa n poniewaz dla a + 0 * n zawsze wynosi a \n";
        y = (1/3)*sin(M_PI*a)+(1/7)+log10(a);
        cout << "x wynosi = " << a << " wartosc funkcji wynosi = " << y << "\n" ;
    } else {
        for (;;){
            cout << "Podaj ilosc powtorzen n: ";
            if(cin >> n && n > 0){
                break;
            }
            cin.clear();
            cin.ignore(512, '\n');
            cout << "n - musi byc > 0\n" ;
        }

        for( int i=0 ; i<=n ; i++) {
            //   result = sin (param*PI/180);
            //   Tworze argumenty dla funkcji zgodnie ze wzorem: x=a, a+h, ..., a+n*h
            x = a+h*i;
            //  Obliczam wartośc funkcji ze wzoru: f = 1/3*sin( pi * x ) + 1/7 +log(x);
            y = (1/3)*sin(M_PI*x)+(1/7)+log10(x);
            //  Wypisuję wynik
            cout << "Dla n = " << i << " x wynosi = " << x << " wartosc funkcji wynosi = " << y << "\n" ;
        }
    }

    return 0;
}
