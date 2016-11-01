#include <iostream>
#include <math.h>
using namespace std;

//float potega()
//float silnia()
//float dwumian_newtona()
//float pole()
//float obwod()
//zamiana()
//

// &a, &b są to parametry referencyjne
//
// czy referencja != od adresu pamięci?
void zamiana( int &a, int &b);

//Function declaration
float potega(float liczba, int n);

// Funkcja oblicza coś na referencji i zwraca lokalne j
//  W ten sposób można zwrócić 2 wartości
float suma(int &i, int j);

// Funkcja zamiana ze wskaźnikami
//      do *wx adres &wx
//      do *wy adres &wy
void zamianaDwa(int *wx, int *wy);

int main() {
    int x =4, y = 100;
    cout << "x ="<< x << "y="<<y;

    // WSKAŹNIKI -- wrzucić do oddzielnej funkcji
    //      Poprzez operator * odwołujemy się do wartości, na którą wskazuje
    //          wskaźnik
    int k, m =2;
    int *wsk = &m;          // int * wsk; wsk =&m;
    k = *wsk + 1;       // k = m+1
    k = sqrt(*wsk);     // k = sqrt(m)

    zamianaDwa(&x, &y);

    *wsk = 0;           //m = 0;


    return 0;
}

float suma(int &i, int j){
    i+=20;
    return j;
}

float potega(float liczba, int n){
    float wynik = 1;
    for(int i =0; i<=n; i++)
        wynik = wynik*liczba;
    return wynik;
}

void zamiana( int &a, int &b){
    int c;
    c=a;
    a=b;
    b=c;
}
void zamianaDwa(int *wx, int *wy){
    int c;
    c = *wx;
    *wx = *wy;
    *wy = c;
}

//Function function definition
