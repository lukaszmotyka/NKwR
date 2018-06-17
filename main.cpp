#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

const int MAX_N = 100; // maksymalna iloœæ wierzcho³ków w grafie
int GraphArray[MAX_N][MAX_N]; // macierz s¹siedztwa

int ReadData(int A[][MAX_N]); //funkcja wczytuj¹ca graf z pliku

int main(){
    ReadData(GraphArray);
    system("PAUSE");
    return 1;
}

int ReadData(int A[][MAX_N]){
    int i,j,k,wmax,n,x,y;
    fstream plik;
    plik.open("data.txt", ios::in);
    string linia, val1, val2;

    for(i = 0; i < MAX_N; i++)
    for(j = 0; j < MAX_N; j++) A[i][j] = 0;
    wmax = 0;
    getline(plik,linia);
    n = atoi(linia.c_str());//cin >> n; // odczytujemy iloœæ krawêdzi
    for(i = 0; i < n; i++){
        //cin >> x >> y; // odczytujemy krawêdŸ
        getline(plik,linia);
        k=0;
        while(linia[k] != ' '){
            val1[k] = linia[k];
            k++;
        }
        x = atoi(val1.c_str());
        val1=' ';

        j=0;
        k++;
        while(linia[k] != '\0'){
            val2[j] = linia[k];
            k++;
            j++;
        }
        y = atoi(val2.c_str());
        val2=' ';

        wmax = (x > wmax) ? x : wmax;
        wmax = (y > wmax) ? y : wmax;
        A[x-1][y-1] = 1;
        A[y-1][x-1] = 1;
    }
    cout << endl;
    for(i = 0; i < wmax; i++) {
        for(j = 0; j < wmax; j++) {
            cout << (int)A[i][j] << " ";
        }
    cout << endl;
    }
}
