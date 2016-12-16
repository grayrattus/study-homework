#include <cstdlib>
#include <iostream>
#include <iomanip>      // std::setw
#include <ctime>



using namespace std;

/*
Tutaj nie trzeba podawaæ pierwszego wymiaru ale dlaczego?
Jak inaczej przekazaæ iloœæ elementów?
*/
void losuj(int A[5][8], int w, int p, int k){
    srand(time(NULL));
    for (int i = 0; i < w; i++) {
        for (int j = 0 ; j < 8 ; j++){
            A[i][j] = rand()%(k-p+1)+p;
        }
    }
}

void displayA(int A[][8]){
    for (int i = 0; i < 5; i++) {
        for (int j = 0 ; j < 8 ; j++){
            cout << setw(10) <<  A[i][j] << " ";
        }
        cout << endl ;
    }
}

void sum(int A[][8], int B[5]){
    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 8 ; j++) {
            B[i] = B[i]+A[i][j];
        }
    }
}

void displayB(int B[5]){
    for (int i = 0 ; i < 5 ; i++) {
        cout << "Suma dla indeksu tablicy:" << i << " wynosi:" << B[i] << endl;
    }
}

void maxB(int B[5]){
    int m = 0;
    int index = 0;
    for(int i = 0 ; i < 5 ; i++) {
        if(B[i] > m) {
            m = B[i];
            index = i ;
        }
    }
    cout << "Najwiekszy element tablicy B to: " << m << " i posiada indeks " <<index << endl;

}

void zamienKolumny(int A[][8], int doZamiany, int zamiana){
    int tmp;
    for (int i = 0 ; i < 5 ; i++){
        tmp = A[i][doZamiany];
        A[i][doZamiany] = A[i][zamiana];
        A[i][zamiana] = tmp;
    }
}

int main() {
    int A[5][8];
    int B[5] = {0};
    int p;
    int k;

    cout << "Podaj przedzial poczatkowy: " ;
    cin >> p ;
    cout << "\nPodaj przedzial koncowy: ";
    cin >> k;

    cout << endl;
    losuj(A,5, p, k);
    displayA(A);
    sum(A,B);

    displayB(B);
    maxB(B);

    displayA(A);
    cout << "\n\n\n";
    zamienKolumny(A, 1, 2);
    displayA(A);
}
