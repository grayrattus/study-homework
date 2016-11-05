#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

void losuj(int tab[], int ilosc);
void obliczOcene(int tab[], int iT, int ocena[], int iO); 
double srednia(int tab[], int iT);
void sortuj(int tab[], int iT); 
int mediana(int tab[], int iT); 
void wypiszTablice(int tab[], int iT);
void dominanta(int tab[], int iT);
void histogram(int t2[], int iT);

int main(int argc, char *argv[]){

    srand(time(NULL));
    int student[100];
    int ocena[6];
    losuj(student, 100);
    obliczOcene(student,100, ocena,6);
    wypiszTablice(ocena,6);

    mediana(student, 100);

    dominanta(student,100);

    histogram(ocena, 6);

    cout << "Srednia wynosi :" << srednia(student,100) << endl;
}

void histogram(int t2[], int iT){
    int max = 0;
    for (int i = 0 ; i < iT; i++) {
        if (max <= t2[i]) {
            max = t2[i] ;
        }
    }
    for (  ; max > 0 ; max--) {
        for (int j = 0 ; j < iT; j++) {
            if (t2[j] >= max) {
                cout << " # "; 
            } else cout << "   " ;
        }
        cout << endl;
    }
    for (int j = 0 ; j < iT; j++) {
        cout << " " << j << " " ;
    }
    cout << endl;
}

void dominanta(int tab[], int iT){
    int histogram[6];
    int dom = 0;
    for(int i = 0 ; i < 6; i++){
        histogram[i] = 0; 
    }

    obliczOcene(tab, 100, histogram, 6);
    int x = 0;
    for (int i = 0 ; i < 6; i++) {
        if (dom<= histogram[i]) {
            dom = histogram[i] ;
            x = i;
        }
    }
    cout << "\nDominanta : " << x << endl;
}
void wypiszTablice(int tab[], int iT){
    cout << endl;
    for (int i = 0 ; i < iT ; i++) {
        cout << "Film dostal ocene : "<< i << " ilosc: " << tab[i] << endl;
    }
}
int mediana(int tab[], int iT) {
    sortuj(tab, 100);
    return tab[iT/2];
}
void sortuj(int tab[], int iT) {
    bool zmiana = false;
    do {
        zmiana = false;
        for (int i = 0 ; i < iT ; i++) {
            if (tab[i] > tab[i+1]) {
                int temp = tab[i+1];
                tab[i+1] = tab[i];
                tab[i] = temp;
                zmiana = true;
            }
        }
    } while (zmiana == true);
}
double srednia(int tab[], int iT){
    double sred = 0;
    for (int i = 0 ; i < iT ; i++) {
        sred += tab[i];
    }
    return sred = sred/iT;
}
void obliczOcene(int tab[], int iT, int ocena[], int iO) {
    for(int i = 0 ; i < iO ; i++){
        ocena[i] = 0; 
    }
    for(int i = 0 ; i < iT ; i++) ocena[tab[i]]++; 
}
void losuj(int tab[], int iT) {
    for (int i = 0 ; i < iT ; i++) {
        tab[i] = rand() % 6;
    }
}
