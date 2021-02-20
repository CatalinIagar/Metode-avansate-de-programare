#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fintrare;
    ofstream fiesire;
    fintrare.open("ex7in.txt");
    fiesire.open("ex7out.txt");
    string linie[512];
    int count = 0;
    if (fintrare.is_open())
    {
        while (!fintrare.eof())
        {
            getline(fintrare, linie[count]);
            count++;
        }
    }
    int numere[100];
    int nrcount = 0;
    for (int j = 0; j < count; j++)
    {
        string prop = linie[j];
        int lungime = prop.length();
        for (int j = 0; j < lungime; j++)
        {
            if (prop[j] >= '0' && prop[j] <= '9')
            {
                int nr = 0;
                while (prop[j] >= '0' && prop[j] <= '9')
                {
                    nr = nr * 10 + (prop[j] - 48);
                    j++;
                }
                numere[nrcount] = nr;
                nrcount++;
            }
        }
    }
    long long int suma = 0, produs = 1;
    for (int i = 0; i < nrcount; i++)
    {
        suma = suma + numere[i];
        produs = produs * numere[i];
    }
    sort(numere, numere + nrcount);
    fiesire << "Numerele gasite in ordine crescatoare sunt: ";
    for (int i = 0; i < nrcount; i++)
    {
        fiesire << numere[i] << " ";
    }
    fiesire << "\nSuma numerelor gasite este: " << suma << "\n";
    fiesire << "Produsul numerelor gasite este: " << produs << "\n";
    fiesire.close();
    fintrare.close();
    system("pause");
    return 0;
}