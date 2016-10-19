#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char *argv[]){
    cout << "Dziedziczak Artur" << endl;
    // Deklaracja i inicjalizacja zmiennych
    int k = 0;
    float sum = 0;

    // Pętla, która powoduje, że użytkownik będzie proszony o wprowadzanie K do moementu aż
    //  znak/znaki te będa liczbą
    for (;;){
        cout << "Podaj liczbe powtorzen: " ;
        if(cin >> k && k > 0){
            break;
        }
        cin.clear();
        cin.ignore(512, '\n');
        cout << "Liczba powtorzen musi byc > 0 \n" ;
    }

    // Tutaj pętla licząca sigme
    for ( int j = 1 ; j <= k ; j++ ){
        sum = sum + (( j * j + 1.0 )/(2.0*j));
    }

    cout << "SUMA = " << sum << endl;
}
