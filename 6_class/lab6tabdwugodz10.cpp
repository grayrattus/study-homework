#include <iostream>
#include <cstdlib>
#include <iomanip>

#define N 8

using namespace std;

void display_dimensional_tables(int tab[][N]){
  for (int i = 0 ; i < N ; i++) {
    for (int j = 0 ; j < N ; j++) {
      cout << setw(5) << tab[i][j] ;
    }
    cout << endl ;
  }
}
void fill_dimensional_tables(int tab[][N], int p, int k){
  for (int i = 0 ; i < N ; i++) {
    for (int j = 0 ; j < N ; j++) {
      tab[i][j] = rand()%(k-p+1)+p;
    }
  }
}
int sum_upper_main_diagonal (int tab[][N]) {
  int sum = 0;
  for (int i = 0 ; i < N ; i++) {
    for (int j = 0 ; j < N ; j++) {
      if (j + i < N ) sum+=tab[i][j+i];
    }
  }
  return sum;
}
void max_row_value (int tab[][N], float oneDim[N]) {
  for (int i = 0 ; i < N ; i++) {
    oneDim[i] = 0;
    for (int j = 0 ; j < N ; j++) {
      if (tab[i][j] > oneDim[i])  oneDim[i] = tab[i][j];
    }
  }
}
void display_one_dimension_table(float oneDim[N]) {
  for (int i = 0 ; i < N ; i++) {
    cout << setw(4) << oneDim[i];
  }
}

void column_avg (int tab[][N], float oneDim[N]) {
  for (int i = 0 ; i < N ; i++) {
    for (int j = 0 ; j < N ; j++) {
      oneDim[j] += tab[i][j];
    }
  }
  for (int j = 0 ; j < N ; j++) {
      cout << "SUMA DLA ROW: " << oneDim[j];
      oneDim[j] = oneDim[j]/N ;
  }
}

void sort_diagonal (int tab[][N]) {
  bool change = false ;
  do {
    change = false;
    for (int i = 0 ; i < N-1 ; i++) {
      for (int j = 0 ; j < N-1 ; j++) {
        if (tab[i][j+i] > tab[i+1][j+i+1]) {
          int temp = tab[i][j+i] ;
          tab[i][j+i] = tab[i+1][j+i+1];
          tab[i+1][j+i+1] = temp;
          change = true;
        }
      }
    }
  }while (change == true);
}

int main() {
  int A[N][N] ;
  int B[N][N] ;

  float C[N];
  float D[N] = {0};

  int p = 0;
  int k = 0;

  cout << "Podaj pczątkowy zakres dla losowania tablicy:" << endl;
  cin >> p;
  cout << "Podaj końcowy zakres dla losowania tablicy:" << endl;
  cin >> k;

  fill_dimensional_tables(A, p, k);
  fill_dimensional_tables(B, p, k);

  cout << endl;
  display_dimensional_tables(A);
  cout << endl;
  display_dimensional_tables(B);

  cout << endl;
  cout << "Suma elementów nad główną przekątną A: " << sum_upper_main_diagonal(A);

  max_row_value(A, C);
  display_one_dimension_table(C);
  cout << endl;

  column_avg(A, D);
  cout << endl;
  display_one_dimension_table(D);

  cout << endl;
  sort_diagonal(A);
  display_dimensional_tables(A);
}
