#include <iostream>
#include <time.h>

// ZŁOŻONOŚCI ALGORYTMÓW 
// PISANIE NA KARTACH GRAFICZNYCH

using namespace std;

int main() {
}

void hist(int tab[], int N, int h[]) {
    for (int i = 0 ; i < N ; i++) h[tab[i]]++;
}

// Sortowanie za pomocą histogramu:
//      Ten histogram nie operuje na elementach przy sortowaniu tylko nadpisuje te tablice
//          tyle razy jakie są wartości histogramu
void sort(int tab[], int h[], int n) {
    int j = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int k = 0 ; i < h[i] ; k++) {
            tab[j] = i;
            j++;
        }
    }
}
void babelkoweSort(int tab[], int N){
    int x ;
    bool zamiana;
    do{
        zamiana = false;
        for (int j = 0 ; j < N-1 ; j++) { // tataj -i żeby za kazdym razem nie przechodzić po całej tablicy
            if(tab[j] > tab[j+1]){
                x = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = x;
                zamiana = true;
            }
        }
        N--;
    } while (zamiana == true);
}
