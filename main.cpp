// Wyszukiwanie cyklu Eulera
// Data: 19.03.2014
// (C)2014 mgr Jerzy Wa³aszek
//---------------------------

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// Zmienne globalne

int n,m,sptr;
int ** A;                       // Macierz s¹siedztwa
int * S;                        // Stos w tablicy

// Procedura wyszukuje cykl Eulera
// We:
// v - wierzcho³ek startowy
//--------------------------------
void DFSEuler(int v)
{
  int i;

  for(i = 0; i < n; i++)          // Przegl¹damy s¹siadów
    while(A[v][i])
    {
      A[v][i]--;                  // Usuwamy krawêdŸ
      A[i][v]--;
      DFSEuler(i);                // Rekurencja
    }
  S[sptr++] = v;                  // Wierzcho³ek v umieszczamy na stosie
}

// **********************
// *** Program g³ówny ***
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

  data >> n >> m;                // Czytamy liczbê wierzcho³ków i krawêdzi

  A = new int * [n];            // Tworzymy tablicê wskaŸników
  S = new int [m + 1];          // Tworzymy stos
  sptr = 0;

  for(i = 0; i < n; i++)
    A[i] = new int [n];         // Tworzymy wiersze macierzy s¹siedztwa

  // Macierz wype³niamy zerami

  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++) A[i][j] = 0;

  // Odczytujemy kolejne definicje krawêdzi

  for(i = 0; i < m; i++)
  {
    data >> v1 >> v2;    // wierzcho³ki koñcowe krawêdzi
    A[v1][v2]++;        // KrawêdŸ v1->v2 obecna
    A[v2][v1]++;        // KrawêdŸ v2->v1 obecna
  }

  cout << endl;

  // Wyznaczamy cykl Eulera

  DFSEuler(0);

  // Wypisujemy zawartoœæ stosu

  cout << "EULERIAN CYCLE : ";

  for(i = 0; i < sptr; i++) cout << S[i] << " ";
  cout << endl;

  // Usuwamy tablice dynamiczne

  for(i = 0; i < n; i++) delete [] A[i];

  delete [] A;
  delete [] S;

  return 0;
}
