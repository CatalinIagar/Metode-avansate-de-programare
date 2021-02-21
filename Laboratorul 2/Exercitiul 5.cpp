#include <iostream>
#include <string>
#include <string.h>

using namespace std;

typedef struct dataExpirare
{
    int zi, luna, an;
} dataExpirare;

typedef struct produs
{
    int cod;
    string denumire;
    string unitate;
    int cantitate;
    int pret;
    dataExpirare data;
    int valStoc;
} produs;

produs citireProduse(int nrPr)
{
    produs X;
    cout << "\n[Produs " << nrPr + 1 << "]\n";
    cout << "Introduceti codul(unic) al produsului(intre 1 - 999): ";
    cin >> X.cod;
    fflush(stdin);
    cout << "Introduceti denumirea produsului: ";
    getline(cin, X.denumire);
    cout << "Introduceti unitatea de masura al produsului: ";
    getline(cin, X.unitate);
    cout << "Introduceti cantitatea produsului: ";
    cin >> X.cantitate;
    cout << "Introduceti pretul produsului (in ruble rusesti): ";
    cin >> X.pret;
    char dataTemp[8];
    cout << "Introduceti data de expirare al produsului (sub forma ZZLLAAAA): ";
    cin >> dataTemp;
    X.data.zi = (dataTemp[0] - 48) * 10 + (dataTemp[1] - 48);
    X.data.luna = (dataTemp[2] - 48) * 10 + (dataTemp[3] - 48);
    X.data.an = ((dataTemp[4] - 48) * 1000) + ((dataTemp[5] - 48) * 100) + ((dataTemp[6] - 48) * 10) + (dataTemp[7] - 48);
    return X;
}

void afisareProdus(produs prod, int nr)
{
    cout << "\n\n[Produs " << nr + 1 << "]";
    cout << "\nCod produs: " << prod.cod;
    cout << "\nDenumire: " << prod.denumire;
    cout << "\nValoare stoc: " << prod.valStoc;
}

void afisareProdusExpirat(produs prod, int nr)
{
    bool expirat;
    int anCurent = 2021, lunaCurent = 2, ziCurent = 21;
    if (prod.data.an < anCurent)
    {
        expirat = true;
    }
    else if (prod.data.luna < lunaCurent)
    {
        expirat = true;
    }
    else if (prod.data.zi < ziCurent)
    {
        expirat = true;
    }
    else
    {
        expirat = false;
    }

    if (expirat)
    {
        cout << "[Produs " << nr + 1 << "]";
        cout << "\nCod produs: " << prod.cod;
        cout << "\nDenumire: " << prod.denumire;
        cout << "\nCantitate: " << prod.cantitate << prod.unitate;
        cout << "\nPret: " << prod.pret << " Ruble rusesti/" << prod.unitate;
        cout << "\nData expirarii: " << prod.data.zi << "-" << prod.data.luna << "-" << prod.data.an;
    }
}

int main()
{
    produs produse[50];
    int nrProduse;
    cout << "Introduceti numarul de produse dorite: ";
    cin >> nrProduse;
    for (int i = 0; i < nrProduse; i++)
    {
        produse[i] = citireProduse(i);
    }
    for (int i = 0; i < nrProduse; i++)
    {
        produse[i].valStoc = produse[i].cantitate * produse[i].pret;
    }
    cout << "Produsele din stoc sunt:";
    for (int i = 0; i < nrProduse; i++)
    {
        afisareProdus(produse[i], i);
    }

    cout << "\n\nProdusele din stoc expirate sunt: \n";
    for (int i = 0; i < nrProduse; i++)
    {
        afisareProdusExpirat(produse[i], i);
    }
    system("pause");
}