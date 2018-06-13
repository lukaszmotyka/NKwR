// Wyszukiwanie cyklu Eulera
// Data: 19.03.2014
// (C)2014 mgr Jerzy Wa�aszek
//---------------------------

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// Zmienne globalne

int n,m,sptr;
int ** A;                       // Macierz s�siedztwa
int * S;                        // Stos w tablicy

// Procedura wyszukuje cykl Eulera
// We:
// v - wierzcho�ek startowy
//--------------------------------
void DFSEuler(int v)
{
  int i;

  for(i = 0; i < n; i++)          // Przegl�damy s�siad�w
    while(A[v][i])
    {
      A[v][i]--;                  // Usuwamy kraw�d�
      A[i][v]--;
      DFSEuler(i);                // Rekurencja
    }
  S[sptr++] = v;                  // Wierzcho�ek v umieszczamy na stosie
}

// **********************
// *** Program g��wny ***
// **********************

int main()
{
  int i,j,v1,v2;

  fstream data;
  data.open("data.txt",ios::in);

  if(data.good()==false)
  {
      cout<<"Nie znaleziono pliku data";
      exit(0);
  }

  data >> n >> m;                // Czytamy liczb� wierzcho�k�w i kraw�dzi

  A = new int * [n];            // Tworzymy tablic� wska�nik�w
  S = new int [m + 1];          // Tworzymy stos
  sptr = 0;

  for(i = 0; i < n; i++)
    A[i] = new int [n];         // Tworzymy wiersze macierzy s�siedztwa

  // Macierz wype�niamy zerami

  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++) A[i][j] = 0;

  // Odczytujemy kolejne definicje kraw�dzi

  for(i = 0; i < m; i++)
  {
    data >> v1 >> v2;    // wierzcho�ki ko�cowe kraw�dzi
    A[v1][v2]++;        // Kraw�d� v1->v2 obecna
    A[v2][v1]++;        // Kraw�d� v2->v1 obecna
  }

  cout << endl;

  // Wyznaczamy cykl Eulera

  DFSEuler(0);

  // Wypisujemy zawarto�� stosu

  cout << "EULERIAN CYCLE : ";

  for(i = 0; i < sptr; i++) cout << S[i] << " ";
  cout << endl;

  // Usuwamy tablice dynamiczne

  for(i = 0; i < n; i++) delete [] A[i];

  delete [] A;
  delete [] S;

  return 0;
}
