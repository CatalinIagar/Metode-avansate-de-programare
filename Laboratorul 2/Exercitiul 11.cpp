#include <iostream>
#include <fstream>

using namespace std;

int numararePropozitii(ifstream &fintrare)
{
    int prop = 0;
    string cuv;
    while (!fintrare.eof())
    {
        fintrare >> cuv;
        int temp = cuv.length();
        if (cuv[temp - 1] == '.' || cuv[temp - 1] == '!' || cuv[temp - 1] == '?')
        {
            prop++;
            continue;
        }
    }
    return prop;
}

int numarareLitere(ifstream &fintrare)
{
    int suma = 0;
    string cuv;
    while (!fintrare.eof())
    {
        fintrare >> cuv;
        int temp = cuv.length();
        suma += temp;
    }
    return suma;
}

int numarareCuvinte(ifstream &fintrare)
{
    int cuvinte = 0;

    string cuvant;

    while (!fintrare.eof())
    {

        if (fintrare >> cuvant)
        {
            cuvinte++;
            continue;
        }
    }

    return cuvinte;
}

int main()
{
    ifstream fintrare;
    fintrare.open("ex11in.txt");
    string linie[512];

    if (fintrare.is_open())
    {
        int nrCuvinte, nrPropozitii, nrLitere;
        nrCuvinte = numarareCuvinte(fintrare);
        fintrare.close();
        fintrare.open("ex11in.txt");
        nrPropozitii = numararePropozitii(fintrare);
        fintrare.close();
        fintrare.open("ex11in.txt");
        nrLitere = numarareLitere(fintrare);
        cout << "Numar propozitii: " << nrPropozitii;\
        cout << "\nNumar cuvinte: " << nrCuvinte;
        cout << "\nNumar litere: " << nrLitere << "\n";
    }
    system("pause");
}