#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int compare( const void *a, const void *b) {
  return *(char*)a - *(char*)b;
}

int main()
{
    char linie[50][100];
    ifstream fintrare;
    fintrare.open("ex2in.txt");
    if (fintrare.is_open())
    {
        int nrLinii = 0;
        char caracter;
        int nrCh[30] = {0};
        int temp = 0;
        fintrare.get(caracter);
        while (!fintrare.eof())
        {
            if (caracter == '\n')
            {
                ++nrLinii;
                temp = 0;
                fintrare.get(caracter);
            }
            linie[nrLinii][temp] = caracter;
            //cout << caracter;
            nrCh[nrLinii]++;
            temp++;
            fintrare.get(caracter);
        }
        cout << endl;
        cout << "Propozitiile gasite sunt: \n";
        for (short i = 0; i <= nrLinii; i++)
        {
            for (short j = 0; j < nrCh[i]; j++)
            {
                cout << linie[i][j];
            }
            cout << endl;
        }
        qsort(linie, nrLinii, sizeof(char[3]), compare);
        cout << "\nPropozitiile sortate sunt: \n";
        for (short i = 0; i <= nrLinii; i++)
        {
            for (short j = 0; j < nrCh[i]; j++)
            {
                cout << linie[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        cout << "eroare";
    }
    fintrare.close();
    system("pause");
}