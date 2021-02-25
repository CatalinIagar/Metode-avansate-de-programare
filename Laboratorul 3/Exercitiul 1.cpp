#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

typedef struct Persoana
{
    char CNP[14];
    char nume[50];
    char prenume[50];
    char locnastere[50];
    char domiciliu[50];
    int varsta;
} Persoana;

int compare(const void *a, const void *b)
{
    Persoana *persoanaA = (Persoana *)a;
    Persoana *persoanaB = (Persoana *)b;

    return strcmp(persoanaA->prenume, persoanaB->prenume);
}

int compare2(const void *a, const void *b)
{
    Persoana *persoanaA = (Persoana *)a;
    Persoana *persoanaB = (Persoana *)b;

    return (persoanaA->varsta < persoanaB->varsta);
}

int main()
{
    Persoana persoane[100];
    ifstream fintrare;
    fintrare.open("ex1in.txt");
    if (fintrare.is_open())
    {
        int nrPers;
        fintrare >> nrPers;
        for (short i = 0; i < nrPers; i++)
        {
            fintrare >> persoane[i].prenume;
            fintrare >> persoane[i].nume;
            fintrare >> persoane[i].CNP;
            fintrare >> persoane[i].locnastere;
            fintrare >> persoane[i].domiciliu;
        }
        for (short i = 0; i < nrPers; i++)
        {
            cout << persoane[i].prenume << " " << persoane[i].nume << " " << persoane[i].CNP << " " << persoane[i].locnastere << " " << persoane[i].domiciliu << endl;
        }

        cout << "\nPersoanele in ordine alfabetica sunt: \n";
        qsort(persoane, nrPers, sizeof(Persoana), compare);
        for (short i = 0; i < nrPers; i++)
        {
            cout << persoane[i].prenume << " " << persoane[i].nume << " " << persoane[i].CNP << " " << persoane[i].locnastere << " " << persoane[i].domiciliu << endl;
        }
        for (int i = 0; i < nrPers; i++)
        {
            if ((persoane[i].CNP[0] - 48) == 1 || (persoane[i].CNP[0] - 48 == 2))
            {
                persoane[i].varsta = 2021 - 1900 - ((persoane[i].CNP[1] - 48) * 10 + (persoane[i].CNP[2] - 48));
            }
            else
            {
                persoane[i].varsta = 2021 - 2000 - ((persoane[i].CNP[1] - 48) * 10 + (persoane[i].CNP[2] - 48));
            }
        }
        qsort(persoane, nrPers, sizeof(Persoana), compare2);
        cout << "\nPersoanele in ordine descrescatoare a varstei: \n";
        for (short i = 0; i < nrPers; i++)
        {
            cout << persoane[i].prenume << " " << persoane[i].nume << " " << persoane[i].CNP << " " << persoane[i].locnastere << " " << persoane[i].domiciliu << " " << persoane[i].varsta << " ani" << endl;
        }
    }
    else
    {
        cout << "eroare";
    }
    fintrare.close();
    system("pause");
}