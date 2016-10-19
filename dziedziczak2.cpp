#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

// Użyłem tutaj klasy ponieważ chciałem spróbować czegoś nowego a już wczesniej programowałem więc
//  stwierdziłem, że wykonam program na klasach c++.

// Deklaracja klasy abc, która przechowuje zmienne a,b,c potrzebne do rozwiązania równania.
// set* -- przypisuje zmienne do klasy
// get* -- zwraca zmienne klasy

class Abc {
    float a;
    float b;
    float c;

    public:
    void setA(float i) { a = i; } 
    void setB(float i) { b = i; } 
    void setC(float i) { c = i; } 
    void setABC(float tempA, float tempB, float tempC) { 
        a = tempA;
        b = tempB;
        c = tempC;
    } 

    float getA() {return a;  } 
    float getB() {return b;  } 
    float getC() {return c;  } 

};

int main(int argc, char *argv[]){
    cout << "Dziedziczak Artur" << endl;

    // Deklaracja i inicjalizacja tablicy zmiennych typu klasy abc
    Abc zmienne[6];

    zmienne[0].setABC(3,6,3);
    zmienne[1].setABC(2.5,6.6,1.5);
    zmienne[2].setABC(0.5,0.1,1.5);
    zmienne[3].setABC(0,2.5,7.5);
    zmienne[4].setABC(0,0,5.5);
    zmienne[5].setABC(0,0,0);

    // Deklaracja zmiennnych potrzebnych do rozwiązania równania
    float delta = 0;
    float x1, x2 = 0;

    // Zbadanie ilości elementów tablicy poprzez
    //  zizeof(zmienne) -- zwróci ilość bajtów, które zajmuje cała tablica
    //  sizeof(abc) -- zwróci ilość bajtów jednego elemetu tablicy
    //      zmienneSiz -- tutaj przypisuję ilośc elementów bajtyTablicy/bajtyJednegoElementu = iloscElementówWTablicy
    int zmienneSiz = sizeof(zmienne)/sizeof(Abc);

    // Pętla iterująca po elementach tablicy
    for ( int i = 0 ; i < zmienneSiz ; i++ ) {
        cout << "\n\n";

        // Wypisuje na ekranie wartości a,b,c 
        cout << "a: " << zmienne[i].getA() << 
            "b: " << zmienne[i].getB() << 
            "c: " << zmienne[i].getC() << endl;


        // Sprawdza czy równanie posiada x.
        //  Jeżeli a = 0 i b = 0 to nie jest to równanie, które można rozwiązać
        if ( zmienne[i].getA() == 0 && zmienne[i].getB() == 0 ){
            cout << "Wspolczynnik a = 0 i b = 0 wiec nie jest to rownanie" << endl;
        }

        // Sprawdza czy równanie jest równaniem kwadratowym
        //  Jeżeli nie jest bo a = 0 to oblicza równanie liniowe ze wzoru y=ax+b
        else if ( zmienne[i].getA() == 0 ){
            x1 = (-zmienne[i].getC())/zmienne[i].getB();
            cout << "Wspolczynnik a = 0 wiec jest to rownanie liniowe z rozwiazaniem x = " << x1 << endl;
        }
        else if (zmienne[i].getA() == 0 && zmienne[i].getB() == 0 && zmienne[i].getC() == 0 ){
            cout << "0 = 0, rownanie tozsamosciowe. Ma nieskonczenie wiele rozwiazan" << endl;
        }
        // W przeciwnych wypadkach algorytm rozwiązuje równanie kwadratowe
        else {
            // Oblicza delte
            delta = (zmienne[i].getB()*zmienne[i].getB())-(4*zmienne[i].getA()*zmienne[i].getC());

            // Jezeli delta jest większa > 0 to równanie ma 2 pierwiastki, które program wypisze na ekranie
            if ( delta > i ) {
                x1 = ((-zmienne[i].getB())+delta)/(2*zmienne[i].getA()); 
                x2 = ((-zmienne[i].getB())-delta)/(2*zmienne[i].getA()); 

                cout << "Delta " << delta << " > 0 Rownanie ma 2 rozwiazania x1:" << x1 << " x2: " << x2 << endl;

            } 
            // Jeżeli delta jest == 0 to równanie ma 1 pierwiastek
            else if ( delta == 0 ) {
                x1 = (-zmienne[i].getB())/(2*zmienne[i].getA()); 

                cout << "Delta " << delta << " = 0 Rownanie ma 1 rozwizanie x:" << x1 << endl;
            }
            // W przeciwnym wypadku wszystkie możliwości zostały wykorzystane i delta musi być < 0
            //  wtedy równanie nie ma rozwiązania 
            else {
                cout << "Delta " << delta << " < 0 Brak rozwiazan " << endl;
            }

        }
    }

    return 0;
}
