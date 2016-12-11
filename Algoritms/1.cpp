// Struktury danych
/*
  // struct -- definiuje nowy typ danych
  struct nazwa_typu  {
    typ1 skł1;  //definicja struktury
    typ2 skł2;
    typn skłn;
  };
  Od tego momentu ten typ dołącza do takich typów danych jak: int, char, double, float

  Przykłądowa struktura danych:
    #Adres
      -miasto - char[30]
      -ulica - char[30]
      -nr domu - int
      -kod pocztowy int
    #Dane klienta
      -adres - char[30]
      -imie - char[30]
      -nazwisko - char[30]
      -ne pesel - int
      -telefon - int
      -stan konta - double
*/
  struct sAdres {
    char miasto[30];
    char ulica[30];
    int nr_domu[30];
    int kod_pocztowy[30];
  };

  struct sKlient{
    sAdres adres ;
    char imie[30];
    char nazwisko[30];
    int nr_pesel[30];
    int telefon[30];
    double stan_konta[30];
  };

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <string>
#include <memory.h>

using namespace std;

sKlient klienci[1000];
int N = 0; // liczba klientów

void wyswietl(int k){
  printf("| %s | %s | %d | %d | %s | %s \n", klienci[k].imie, klienci[k].nazwisko, klienci[k].nr_pesel, klienci[k].telefon, klienci[k].adres.miasto, klienci[k].adres.ulica );
}
void wyswietlWszystkich(){
  for(int k = 0 ; k < N ; k++){
    wyswietl(k);
  }
}
void edytuj(int k, sKlient klient){
  memcpy(&klienci[k], &klient, sizeof(sKlient));
}
void dodaj(sKlient klient){
  edytuj(N, klient);
  N++;
}
void wstaw(sKlient klient, int k){
  for (int i = N ; i>=k ; i--){
    memcpy(&klienci[i+1], &klienci[i], sizeof(klienci));
    memcpy(&klienci[i+1], &d, sizeof(klienci));
  }
  N++;
}

/*
  -1 jezli elementu nie znaleziono
  indeks elementu - jeżeli element znaleziono
  k - indeks elementu od którego rozpoczynamy przeszukiwanie
/*

void utworzKlienta(&klient){
}
void usun(int k){
  for (int i = k+1 ; i <= N-1 ; i++){
    memcpy(&klienci[i-1], &klienci[i], sizeof(klienci));
    N--;
  }
}
int main() {
}
