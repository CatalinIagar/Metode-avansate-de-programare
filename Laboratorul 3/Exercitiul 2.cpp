#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

/* int compare ( const void *pa, const void *pb ) {
    const int (*a)[4] = pa;
    const int (*b)[4] = pb;
    if ( (*a)[3] < (*b)[3] ) return -1;
    if ( (*a)[3] > (*b)[3] ) return +1;
    return 0;
} */

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
        //qsort(linie, nrLinii, sizeof(linie[0]), compare);
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