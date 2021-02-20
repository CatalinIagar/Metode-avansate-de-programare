#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

typedef struct persoana
{
    char CNP[14];
    string nume;
    string prenume;
    char locnastere[100];
    char domiciliu[100];
    int varsta;
} persoana;

persoana citire()
{
    fflush(stdin);
    persoana X;
    cout << "Introduceti numele: ";
    getline(cin, X.nume);
    cout << "Introduceti Prenumele: ";
    getline(cin, X.prenume);
    cout << "Introduceti CNP-ul(14 cifre): ";
    cin >> X.CNP;
    cout << "Introduceti locul nasterii: ";
    cin >> X.locnastere;
    cout << "Introduceti domiciliul: ";
    cin >> X.domiciliu;
    return X;
}

bool comparare(persoana p1, persoana p2)
{
    if (p1.nume == p2.nume)
    {
        return (p1.prenume < p2.prenume);
    }
    else
    {
        return (p1.nume < p2.nume);
    }
}

bool comparare2(persoana p1, persoana p2)
{
    return p1.varsta > p2.varsta;
}

int main()
{
    persoana persoane[100];
    int nrpers = 2;
    cout << "Introduceti numarul de persoane: ";
    cin >> nrpers;
    for (int i = 0; i < nrpers; i++)
    {
        cout << "\nPersoana nr " << i + 1 << ":\n";
        persoane[i] = citire();
    }
    sort(persoane, persoane + nrpers, comparare);
    cout << "Persoanele sortate dupa nume/prenume: \n";
    for (int i = 0; i < nrpers; i++)
    {
        cout << "\nPersoana " << i << ":\n";
        cout << persoane[i].nume << "\n";
        cout << persoane[i].prenume << "\n";
        cout << persoane[i].CNP << "\n";
        cout << persoane[i].locnastere << "\n";
        cout << persoane[i].domiciliu << "\n";
    }

    for (int i = 0; i < nrpers; i++)
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
    sort(persoane, persoane + nrpers, comparare2);
    cout << "Persoanele sortate dupa nume/prenume: \n";
    for (int i = 0; i < nrpers; i++)
    {
        cout << "\nPersoana " << i << ":\n";
        cout << persoane[i].nume << "\n";
        cout << persoane[i].prenume << "\n";
        cout << persoane[i].CNP << "\n";
        cout << persoane[i].locnastere << "\n";
        cout << persoane[i].domiciliu << "\n";
        cout << persoane[i].varsta << "\n";
    }
    system("pause");
}