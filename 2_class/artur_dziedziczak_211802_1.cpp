#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
int silnia(int N);
int symbolNewtona(int n, int k);
double sumaZeWzoru(int k);
void zmien1(int w);
void zmien2(int &w);
double fFunkcja(double x);
double fTrojkat(double a, double b, double c);

int main(int argc, char *argv[]){
    cout << "Dziedziczak Artur" << endl;
    // DO 3 listopada

    cout << "Obliczanie silni \n";
    int nSilnia = 0;
    int nNewton = 0;
    int kNewton = 0;
    int kSuma = 0;
    int wZmian1 = 0;
    int wZmian2 = 0;

    double a = 0;
    double h = 0;
    int M = 0;

    double bok1 = 0;
    double bok2 = 0;
    double bok3 = 0;

    // Silnia
    do {
        cout << "Podaj n silni: ";
        cin >> nSilnia;
    } while (nSilnia < 0);
    cout << "Silnia wynosi: " <<silnia(nSilnia) << endl ;

    // Newton
    do {
        cout << "\nPodaj n dla symbolu Newtona: ";
        cin >> nNewton;
    } while (nNewton < 0);
    do {

        cout << "\nPodaj k dla symbolu Newtona: ";
        cin >> kNewton;
    } while (kNewton < 0);

    cout << "\nSymbol newtona wynosi: " <<symbolNewtona(nNewton, kNewton) << endl ;

    // Suma
    do {
        cout << "\nPodaj k dla sumy: ";
        cin >> kSuma;
    } while (kSuma <= 0);
    cout << "\nSuma ze wzoru wynosi: " <<sumaZeWzoru(kSuma) << endl ;

    // Funkcja zmien1
    cout << "\nPodaj parametr dla funkcji zmien1: ";
    cin >> wZmian1;
    zmien1(wZmian1) ;
    cout << "\nParametr w w funkcji main:" << wZmian1 << endl ;

    // Funkcja zmien2
    cout << "\nPodaj parametr dla funkcji zmien2: ";
    cin >> wZmian2;
    zmien2(wZmian2) ;
    cout << "\nParametr w w funkcji main: " << wZmian2 << endl ;
    cout << "\nPodaj a dla funkcji: ";
    cin >> a;
    cout << "\nPodaj h dla funkcji: ";
    cin >> h;

    do{
        cout << "\nPodaj M dla funkcji: ";
        cin >> M;
    } while ( M < 0);
    for ( int i = 0 ; i <= M ; i++ ){
        int x = a + i * h;
        cout << "Wartość funkcji w punkcie " << x << " wynosi: " << fFunkcja(x) << endl;
    }
    do {
        cout << "\nPodaj pierwszy bok dla trojkata: ";
        cin >> bok1;
    } while ( bok1 <= 0);
    do {
        cout << "\nPodaj drugi bok dla trojkata: ";
        cin >> bok2;
    } while ( bok2 <= 0);
    do {
        cout << "\nPodaj trzeci bok dla trojkata: ";
        cin >> bok3;
    } while ( bok3 <= 0);
    fTrojkat(bok1, bok2, bok3);
}

double fTrojkat(double a, double b, double c) {
    // Wzór herona! 
    //a+b>c
    //a+c>b
    //b+c>a
    if ((a > 0 && b > 0 && c > 0 ) && (( a + b )> c && (a + c)>b && (b + c) >a)){
        cout << "Z podanych odcinków można utworzyć trójkąt\n" ; 
        double p = ((1.0)/(2.0))*(a+b+c);
        cout << "Pole trójkąta wynosi: " << sqrt(p*(p-a)*(p-b)*(p-c)) << endl; 
    }
}

double fFunkcja(double x) {
    if (x >= -3.4 && x <= 15) {
        return (1/2.0)*(x+1);
    }
    else if ( x > 15 ){
        return sin(x);
    }
    else return 2.2*x-2.3;
}

int silnia(int N){
    int silnia = 1;
    for ( ; N > 0 ; N-- ){
        silnia = silnia*N; 
    }
    return silnia;
}

int symbolNewtona(int n, int k){
    return silnia(n)/(silnia(k)*(silnia(n-k)));

}
double sumaZeWzoru(int k){
    double suma = 0;
    for ( int i = 1 ; i <= k ; i++ ){
        suma += (2.0*i+3.0)/(3.0*i+2.0);
    }
    return suma;
}
void zmien1(int w) {
    w += rand()%(16-3+1)+16;               
    cout << "Parametr w w funkcji zmien1 wynosi: " << w << endl;
}
void zmien2(int &w) {
    w += rand()%(16-3+1)+16;               
    cout << "Parametr w w funkcji zmien2 wynosi: " << w << endl;
}
