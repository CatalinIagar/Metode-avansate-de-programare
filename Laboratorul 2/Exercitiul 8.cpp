#include <iostream>
#include <math.h>

using namespace std;

union numar
{
    short int Nr;
    char v[2][16];
};

long long Convert10To2(int nr)
{
    long long baza2 = 1;
    while (nr != 0)
    {
        if (nr % 2 == 1)
        {
            baza2 = baza2 * 10 + 1;
        }
        else
        {
            baza2 = baza2 * 10 + 0;
        }

        nr = nr / 2;
    }
    long long rasturnat = 0;
    while (baza2 != 0)
    {
        rasturnat = rasturnat * 10 + baza2 % 10;
        baza2 = baza2 / 10;
    }
    return rasturnat / 10;
}

int inversareOcteti(int nr)
{
    numar numar;
    numar.Nr = nr;
    cout << "\nNumarul in baza 10 este: " << numar.Nr;
    long long baza2 = Convert10To2(nr);
    for (int i = 15; i >= 0; i--)
    {
        if (baza2 % 10 == 1)
        {
            numar.v[0][i] = '1';
        }
        else
        {
            numar.v[0][i] = '0';
        }
        baza2 /= 10;
    }
    cout << "\nNumarul in baza 2: "; // << baza2 << endl;
    for (int i = 0; i < 16; i++)
    {
        cout << numar.v[0][i];
    }
    for (int i = 0; i < 16; i++)
    {
        if (i < 8)
        {
            numar.v[1][i] = numar.v[0][8 + i];
        }
        else
        {
            numar.v[1][i] = numar.v[0][i - 8];
        }
    }
    cout << "\nNumarul rasturnat in baza 2 este: ";
    nr = 0;
    for (int i = 0; i < 16; i++)
    {
        cout << numar.v[1][i];
    }
    for (int i = 15; i >= 0; i--)
    {
        if (numar.v[1][i] == '1')
        {
            nr += pow(2, 15 - i);
        }
    }
    cout << "\nNumarul inversat in baza 10: " << nr;

    return nr;
}

int main()
{
    int numar;
    cout << "Introduceti un numar: ";
    cin >> numar;
    system("cls");
    numar = inversareOcteti(numar);
    numar = inversareOcteti(numar);
    system("pause");
}