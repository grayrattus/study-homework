#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;
int main(int argc, char *argv[]){
    cout << "Dziedziczak Artur" << endl;

    // Deklaracja i inicjacja zmiennych 
    //  Tutaj inicjije klucz po to by program cały czas chodził w pętli aż użytkownik nie poda poprawnych 
    //  wartości k || K || s | S
    char klucz = '1' ;
    float R;
    float H;

    // Główna pętla programu
    do {
        // Wyświetlenie tekstu, który zobaczy użytkownik
        cout << "Podaj litere, co chcesz obliczyć" << endl;
        cout << "Litera k lub K -- objętość kuli" << endl;
        cout << "Litera s lub S -- objętość stożka " << endl;
        cout << "Jeżeli chcesz przerwać działanie programu wciśnij 0" << endl;
        cout << "\n\n" ;

        // Przypisanie do zmienej klucz znaku wprowadzonej przez użytkownika
        cin >> klucz;

        // Pętla switch, która sprawdza czy zmienna klucz jest jednym z wymaganych warunków
        //  Jeżeli, któryś z warunków zostanie przekazany dalej to na sam koniec program
        //      ustawia zmienną klucz na '0' tak by program wyszedł z pętli
        switch(klucz) {
            case 'k':
            case 'K':
                // Oblicza objętość kuli
                //  Tutaj znajduje się pętla, która działa do momentu aż wprowadzona przez
                //   użytkownika dana przejdzie walidacje w if-ie tzn będzie true
                //
                //   cin.clear(); -- usuwa flagi błędów tak żeby można było kolejny raz użyć cin
                //   cin.ignore(512, '\n'); -- tutaj funkcja na obiekcie cin ponieważ zostaje po nim
                //      znak entera, który bez wyczyszczenia lini będzie powodował, że pętla
                //      działa w nieskończoność.
                for (;;){
                    cout << "Podaj promień kuli " << endl ;
                    if(cin >> R){
                        break;
                    }
                    cin.clear();
                    cin.ignore(512, '\n');
                }
                cout << "Objętość kuli wynosi " << (4.0/3.0)*M_PI*R*R*R << endl;
                klucz = '0';
                break;

            case 's':
            case 'S':
                // Oblicza objętość stożka
                for (;;){
                    cout << "Podaj promień stożka " << endl;
                    if(cin >> R){
                        break;
                    }
                    cin.clear();
                    cin.ignore(512, '\n');
                }
                for (;;){
                    cout << "Podaj wysokość stożka " << endl;
                    if(cin >> H){
                        break;
                    }
                    cin.clear();
                    cin.ignore(512, '\n');
                }
                cout << "Objętość stożka wynosi " << (1/3.0)*M_PI*R*R*H << endl;
                cout << "H" << H << endl;
                cout << "R" << R << endl;
                klucz = '0';
                break;
        }
    // Warunek dla, którego program działa aż do wprowadzenia przez użytkownika znaku '0'
    } while ( klucz != '0');
}
