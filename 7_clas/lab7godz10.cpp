#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <fstream>

#define N 3

using namespace std;

struct Uczen {
  char nazwisko[15];
  int klasa;
  float ocena[6];
  float srednia;
};

void fill_uczen(Uczen u[N]) {
  for (int i = 0 ; i < N ; i++) {
    int suma = 0;
    cout << "Podaj nazwisko ucznia [" << i+1 << "]" << endl;
    cin >> u[i].nazwisko;

    u[i].klasa = rand()%(3-1+1)+1;
    for (int j = 0 ; j < 6 ; j++) {
      u[i].ocena[j] = (rand()%(6-12+1)+6)/2.0;
    }
    for (int j = 0 ; j < 6 ; j++) {
      suma += u[i].ocena[j];
    }
    u[i].srednia = suma/6;
  }
}

void sort_uczen_by_nazwisko(Uczen u[N]) {
  bool change = false ;
  do {
    change = false;
    for (int i = 0 ; i < N-1 ; i++) {
      if (strcmp(u[i].nazwisko, u[i+1].nazwisko) > 0) {
        Uczen tempU ;
        tempU = u[i];
        u[i] = u[i+1];
        u[i+1] = tempU;
        change = true;
      }
    }
  } while (change == true);
}
void display_uczen(Uczen u) {
  cout << setw(15) << u.nazwisko ;
  cout << setw(10) << u.klasa ;
  cout << setw(10) << u.srednia ;
  for (int j = 0 ; j < 6 ; j++) {
    cout << setw(5) << u.ocena[j] << ',' ;
  }
  cout << endl;
}
void display_uczen_table_header() {
  cout << setw(15) << "Nazwisko";
  cout << setw(10) << "Klasa";
  cout << setw(10) << "Srednia";
  cout << setw(10) << "Ocena";
  cout << endl;
}

void display_uczen_table(Uczen u[N]) {
  display_uczen_table_header();

  for (int i = 0 ; i < N ; i++) {
    display_uczen(u[i]);
  }
}


void sort_by_klasa(Uczen u[N]) {
  bool change = false;
  do {
    change = false;
    for (int i = 0 ; i < N-1 ; i++) {
      if (u[i].klasa > u[i+1].klasa ) {
        Uczen tempU;
        tempU = u[i];
        u[i] = u[i+1];
        u[i+1] = tempU;
        change = true;
      }
    }
  } while (change == true);
}

void save_uczen_to_file(Uczen u[N]) {
  ofstream myFile ("uczniowie.txt");
  if (myFile.is_open()) {
    myFile << setw(15) << "Nazwisko";
    myFile << setw(10) << "Klasa";
    myFile << setw(10) << "Srednia";
    myFile << setw(10) << "Ocena";
    myFile << "\n";

    for (int i = 0 ; i < N ; i++) {
      myFile << setw(15) << u[i].nazwisko ;
      myFile << setw(10) << u[i].klasa ;
      myFile << setw(10) << u[i].srednia ;
      for (int j = 0 ; j < 6 ; j++) {
        myFile << setw(5) << u[i].ocena[j] << ',' ;
      }
      myFile << "\n";
    }
    myFile.close();
  }
}

void display_selected_uczen(Uczen u[N]) {
  char tempUczenName[15];
  cout << "Podaj nazwisko ucznia, którego chcesz wyświetlić" << endl;
  cin >> tempUczenName;

  for (int i = 0 ; i < N ; i++) {
    if (strcmp(u[i].nazwisko,tempUczenName) == 0) {
      display_uczen_table_header();
      display_uczen(u[i]);
    }
  }
}

void display_uczen_by_selected_avg(Uczen u[N]) {
  float tempUczenAvg;
  cout << "Podaj średnią powyżej, której chcesz wyświetlić uczniów" << endl;
  cin >> tempUczenAvg;
  display_uczen_table_header();
  for (int i = 0 ; i < N ; i++) {
    if (u[i].srednia > tempUczenAvg) {
      display_uczen(u[i]);
    }
  }
}
void display_menu(Uczen uczen[N]) {
    int key = 0;
    cout << "MENU" << endl ;
    cout << "1) Wypełnij tablicę uczniów" << endl ;
    cout << "2) Wypisz tablicę uczniów" << endl ;
    cout << "3) Sortuj elementy po nazwisku" << endl ;
    cout << "4) Sortuj elementy po polu klasa" << endl ;
    cout << "5) Zapisz uczniów do pliku" << endl ;
    cout << "6) Wypisz ucznów powyżej średniej" << endl ;
    cout << "-1) Kończy działanie programu" << endl ;

    do {
      cin >> key;
      switch(key) {
        case 1:
          fill_uczen(uczen);
          break;
        case 2:
          display_uczen_table(uczen);
          break;
        case 3:
          sort_uczen_by_nazwisko(uczen);
          break;
        case 4:
          sort_by_klasa(uczen);
          break;
        case 5:
          save_uczen_to_file(uczen);
          break;
        case 6:
          display_uczen_by_selected_avg(uczen);
          break;
      }
    } while (key > 0);
}

int main() {
  Uczen uczen[N];
  fill_uczen(uczen);
  display_uczen_table(uczen);
  sort_uczen_by_nazwisko(uczen);
  display_uczen_table(uczen);

  sort_by_klasa(uczen);
  display_uczen_table(uczen);
  save_uczen_to_file(uczen);

  display_selected_uczen(uczen);
  display_uczen_by_selected_avg(uczen);

  display_menu(uczen);
}
