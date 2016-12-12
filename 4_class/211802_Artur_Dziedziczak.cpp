#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <cstring>
#include <fstream>

#define N 3
using namespace std;

struct Student {
  char nazwisko[15];
  int nr_albumu;
  float ocena[6];
  float srednia;
};

void fill(Student tab[]) {
  int suma = 0 ;
  for (int i = 0 ; i < N ; i++) {
    suma = 0;
    cin >> tab[i].nazwisko;
    tab[i].nr_albumu = rand() % 210000 + 213000 ;
    for (int j = 0 ; j < 6 ; j++) {
      tab[i].ocena[j] = (rand() %5 + 6)/2.0 ;
      suma = suma + tab[i].ocena[j];
    }
    tab[i].srednia = suma/6;
  }
}
void sortByNazwisko(Student tab[]){
  bool change = false;
  do {
    change = false;
    for(int i = 0 ; i < N-1 ; i++) {
      if (strcmp(tab[i].nazwisko, tab[i+1].nazwisko) > 0){
        Student tmp;
        tmp = tab[i] ;
        tab[i] = tab[i+1];
        tab[i+1] = tmp;
        change = true;
      }
    }
  } while(change == true);
}
void sortBySrednia(Student tab[]){
  bool change = false;
  do {
    change = false;
    for(int i = 0 ; i < N-1 ; i++) {
      if (tab[i].srednia > tab[i+1].srednia){
        Student tmp;
        tmp = tab[i] ;
        tab[i] = tab[i+1];
        tab[i+1] = tmp;

        change = true;
      }
    }
  } while(change == true);
}

void display(Student tab[]) {
  cout << internal<< setw(20);
  cout << internal<< "   nazwisko   " ;
  cout << internal<< setw(20) ;
  cout << internal<< "   nr_albumu   " ;
  cout << internal<< setw(20);
  cout << internal<< "   srednia   " ;
  cout << internal<< setw(30) ;
  cout << internal<< "   ocena   " ;
  cout << endl;
  for (int i = 0 ; i < N ; i++) {
    cout << internal << setw(20);
    cout << internal << tab[i].nazwisko ;
    cout<< internal  << setw(16);
    cout << internal<< tab[i].nr_albumu ;
    cout << internal<< setw(20);
    cout << internal<< tab[i].srednia ;
    cout << right << setw(30);
    for (int j = 0 ; j < 6 ; j++){
      cout << ' ' << tab[i].ocena[j] << ' ' ;
    }
    cout << internal<< endl;
  }
}
void saveSrednia(ofstream & plik_wy, Student tab[]){
  for(int i =0 ;i < N; i++) {
      plik_wy << tab[i].srednia << endl;
  }
}
void displayByName(Student tab[], char nazw[]){
  for (int i = 0 ; i < N ; i++) {
    if (strcmp(tab[i].nazwisko, nazw) == 0){
      cout << "Nazwisko: " << tab[i].nazwisko << endl ;
      cout << "Srednia: " << tab[i].srednia << endl ;
      cout << "Oceny" << endl;
      for (int j = 0 ; j < 6 ; j++) {
        cout << tab[i].ocena[j] << " " ;
      }
    }
  }
  cout << endl;
}
void displayBySrednia(Student tab[], float srednia) {
  cout << endl;
  cout << setw(20);
  cout << "   nazwisko   " ;
  cout << endl;
  for (int i = 0 ; i < N ; i++) {
    if (tab[i].srednia > srednia){
      cout << setw(20);
      cout << tab[i].nazwisko ;
      cout << endl;
    }
  }
}


int main() {
  cout << "Wypełnianie struktury" << endl;
  Student tab[N];
  fill(tab);
  cout << "Wyświetlenie strukury" << endl;
  display(tab);
  cout << "Wyświetlenie po sortowaniu" << endl;
  sortByNazwisko(tab);
  display(tab);
  cout << "Wyświetlenie po sortowaniu po średniej" << endl;
  sortBySrednia(tab);
  display(tab);

  ofstream plik_wy; //definicja obiektu klasy ofstream
  plik_wy.open("srednia.txt", ios_base::out); // Skojarzenie z fizycznym plikiem
  saveSrednia(plik_wy, tab);

  char nazw[50];
  cout << "Podaj nazwisko studenta, ktorego chcesz wyswietlic " << endl;
  cin >> nazw;
  displayByName(tab, nazw);

  float srednia;
  cout << "Podaj srednia powyzej ktorej chcesz wyswietlic " << endl;
  cin >> srednia;
  displayBySrednia(tab, srednia);

  int flag = 0;
  do {
    cout << "MENU" << endl;
    cout << "1) Wypełnienie tablicy" << endl;
    cout << "2) Wypisanie tablicy" << endl;
    cout << "3) Sortowanie wedlug nazwiska" << endl;
    cout << "4) Sortowanie wedlug sredniej" << endl;
    cout << "5) Wypisanie studenta wedlug nazwiska" << endl;
    cout << "6) Zapisanie sortowanej tabllicy do pliku" << endl;
    cout << "7) Wypisanie nazwisk studentów powyżej średniej" << endl;
    cin >> flag;
    switch(flag) {
      case 1 :
      cout << "Wypełnianie struktury" << endl;
      Student tab[N];
      fill(tab);
      break;

      case 2 :
      cout << "Wyświetlenie strukury" << endl;
      display(tab);
      break;

      case 3 :
      sortByNazwisko(tab);
      break;

      case 4 :
      sortBySrednia(tab);
      break;

      case 5 :
      cout << "Podaj nazwisko studenta, ktorego chcesz wyswietlic " << endl;
      cin >> nazw;
      displayByName(tab, nazw);
      break;

      case 6 :
      plik_wy.open("srednia.txt", ios_base::out); // Skojarzenie z fizycznym plikiem
      saveSrednia(plik_wy, tab);
      cout << "Zapisywanie zakonczone sukcesem" << endl;
      break;

      case 7 :
      cout << "Podaj srednia powyzej ktorej chcesz wyswietlic " << endl;
      cin >> srednia;
      displayBySrednia(tab, srednia);
      break;
    }

  } while (flag != 0);
}


/*
tablice 2 wymiarowe
struktury
pliki <3
*/
