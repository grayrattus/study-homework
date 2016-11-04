#include <iostream>
#include <time.h>


using namespace std;

int main() {
    // Deklaracja potrzebnych tablic
    int t1[100];
    int t2[10];

    srand(time(0));

    // Losuję liczby dla tablicy o rozmiarze 100
    for (int i = 0 ; i < sizeof(t1)/sizeof(int) ; i++) {
        t1[i] = rand() % 10 + 1;
    }
    // Przypisuję 0 dla każdego elementu tablicy tak by nie było śmieci w pamięci
    for (int i = 0 ; i < sizeof(t2)/sizeof(int) ; i++) {
        t2[i] = 0;
    }

    // Pętlą switch dla każdej wartości elementu tablicy t1 sprawdzam czy jest to szukany element tablicy t2
    //  Jeżeli tak jest to do danego elementu tablicy t2 dodaję 1
    for (int i = 0 ; i < sizeof(t1)/sizeof(int) ; i++) {
        switch (t1[i]) {
            case 1:
                t2[0]++;
                break;
            case 2:
                t2[1]++;
                break;
            case 3:
                t2[2]++;
                break;
            case 4:
                t2[3]++;
                break;
            case 5:
                t2[4]++;
                break;
            case 6:
                t2[5]++;
                break;
            case 7:
                t2[6]++;
                break;
            case 8:
                t2[7]++;
                break;
            case 9:
                t2[8]++;
                break;
            case 10:
                t2[9]++;
                break;
        }
    }

    // Wypisuję ilośc elementów dla indeksów tablicy od 1 do 10
    for (int i = 0 ; i < sizeof(t2)/sizeof(int) ; i++) {
        cout << "Ilosc " << i+1 << ": " << t2[i] << endl;
    }

    // Dla ilości elementów rysuję w ASCII tak długo elementy aż i będzie równe wartości danej tablicy
    //  To jest łatwe, problem zaczyna się gdy trzeba to rysować w pionie
    for (int i = 0 ; i < sizeof(t2)/sizeof(int) ; i++) {
        cout << "[" << i+1 << "]:";
        for (int j = 0 ; j < t2[i] ; j++) {
            cout << "#" ;
        }
        cout << "\n";
    }
        cout << "\n";
        cout << "\n";

    // Tutaj wyszukuje największą wartość w całej tablicy t2 i przypisuję ją do wartości zmiennej max
    int max = 0;
    for (int i = 0 ; i < sizeof(t2)/sizeof(int) ; i++) {
        if (max <= t2[i]) {
            max = t2[i] ;
        }
    }

    // Deklaruję pomocniczą tablice tTemp[10] i wypełniam ją zerami
    int tTemp[10];
    for (int j = 0 ; j < sizeof(tTemp)/sizeof(int) ; j++) {
        tTemp[j] = 0;

    }

    // Wypisuje ilosc numery poszczegolnych przedziałów od 1 do 10
    for (int j = 0 ; j < sizeof(t2)/sizeof(int) ; j++) {
        cout << " " << j+1 << " " ;
    }
    cout << endl;

    // Tutaj zaczyna się jazda!
    //  Dla każdego i dopóki i jest mniejsze od max -- wersy
    //      Dla każdego j < ilości elementów taliby t2 
    //          sprawdzam czy wartość tablicy tTemp[j] < wartości t2[j]
    //          Jeżeli jest mniejsza to rysuję # i dodaję do wartości tTemp[j] 1
    //
    //          Czyli jeżeli:
    //              t2[0] = 3;
    //              t2[1] = 1;
    //              t2[2] = 2;
    //          To zgodnie z tym wzorem:
    //              i = 1 | tTemp[0][1][2] = 1 
    //              # # #
    //              i = 2 | tTemp[0][2] = 2 
    //              # # #
    //              #   #
    //              i = 3 | tTemp[0] = 3 
    //              # # #
    //              #   #
    //              #
    for (int i = 1 ; i < max ; i++) {
        for (int j = 0 ; j < sizeof(t2)/sizeof(int) ; j++) {
            if (tTemp[j] < t2[j]) {
                cout << " # "; 
                tTemp[j]++;
            } else cout << "   " ;
        }
        cout << endl;
    }
        cout << "\n";
        cout << "\n";
    for (int j = 0 ; j < sizeof(tTemp)/sizeof(int) ; j++) {
        tTemp[j] = t2[j];
    }
    //  Tutaj jest jeszcze trudniej ponieważ nie można wrócić na górę konsoli i trzeba rysować od góry do dołu
    //  Dopóki max jest większe od 0 odejmuję od max 1
    //      Dla każdego j < ilości elementów taliby t2 
    //          sprawdzam czy wartość tablicy t2[j] >= od wartości zmiennej max
    //          Jeżeli jest mniejsza to rysuję # 
    //
    //          Czyli jeżeli:
    //              t2[0] = 3;
    //              t2[1] = 1;
    //              t2[2] = 2;
    //
    //              To max = 3;
    //          To zgodnie z tym wzorem:
    //              max = 3 | t2[0]= 3 
    //              # 
    //              max = 2 | t2[0][2] = 2 
    //              #  
    //              #   #
    //              max = 1 | tTemp[0][1][2] = 1 
    //              #  
    //              #   #
    //              # # #
    for (  ; max > 0 ; max--) {
        for (int j = 0 ; j < sizeof(t2)/sizeof(int) ; j++) {
            if (t2[j] >= max) {
                cout << " # "; 
            } else cout << "   " ;
        }
        cout << endl;
    }
    for (int j = 0 ; j < sizeof(t2)/sizeof(int) ; j++) {
        cout << " " << j+1 << " " ;
    }
    cout << endl;

}
