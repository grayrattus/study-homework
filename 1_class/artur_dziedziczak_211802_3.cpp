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
    char klucz = 't' ;
    float R;
    float H;

    // Główna pętla programu
    do {
        // Wyświetlenie tekstu, który zobaczy użytkownik
        cout << "\n\n";
        cout << "Podaj litere, co chcesz obliczyc" << endl;
        cout << "Litera k lub K -- objetosc kuli" << endl;
        cout << "Litera s lub S -- objetosc stożka " << endl;
        cout << "Jezeli chcesz przerwac dzialanie programu wcisnij n: ";
        cout << "\n" ;

        // Przypisanie do zmienej klucz znaku wprowadzonej przez użytkownika
        cin >> klucz;

        // Pętla switch, która sprawdza czy zmienna klucz jest jednym z wymaganych warunków
        //  Jeżeli, któryś z warunków zostanie przekazany dalej to na sam koniec program
        //      pytam uzytkownika czy chce kontynowac dzialanie programu
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
                    cout << "Podaj promien kuli " ;
                    if(cin >> R && R > 0){
                        break;
                    }
                    cin.clear();
                    cin.ignore(512, '\n');
                    cout << "Promien musi byc >= 0 \n" ;
                }
                cout << "Objetosc kuli wynosi " << (4.0/3.0)*M_PI*R*R*R << endl;
                cout << "Czy chcesz kontynuowac dzialanie programu? (t/n) "; 
                cin >> klucz;
                
                break;

            case 's':
            case 'S':
                // Oblicza objętość stożka
                for (;;){
                    cout << "Podaj promien stozka ";
                    if(cin >> R && R > 0){
                        break;
                    }
                    cin.clear();
                    cin.ignore(512, '\n');
                    cout << "Promien musi byc >= 0 \n" ;
                }
                for (;;){
                    cout << "Podaj wysokosc stozka ";
                    if(cin >> H && H > 0){
                        break;
                    }
                    cin.clear();
                    cin.ignore(512, '\n');
                    cout << "Wysokosc musi byc >= 0 \n" ;
                }
                cout << "Objetosc stozka wynosi " << (1/3.0)*M_PI*R*R*H << endl;
                cout << "Czy chcesz kontynuowac dzialanie programu? (t/n) "; 
                cin >> klucz;
                break;
        }
    // Warunek dla, którego program działa aż do wprowadzenia przez użytkownika znaku '0'
    } while ( klucz != 'n');
}
