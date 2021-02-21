#include <iostream>
#include <time.h>

using namespace std;

typedef struct element
{
    int i, j, val;
} element;

typedef struct mRara
{
    int nrlini, nrcol, nrElementeNenule;
    element e[512];
} mRara;

mRara citireMatrice()
{
    mRara X;
    cout << "Introduceti numarul de linii dorite: ";
    cin >> X.nrlini;
    cout << "Introduceti numarul de coloane dorite: ";
    cin >> X.nrcol;
    int nrElemente;
    nrElemente = X.nrlini * X.nrcol;
    cout << "Introduceti numarul de lemente neunule dorite(intre 1 - " << nrElemente << "): ";
    cin >> X.nrElementeNenule;
    int nrElementeAlocate = 0;
    int count = 0;
    for (int i = 0; i < X.nrlini; i++)
    {
        for (int j = 0; j < X.nrcol; j++)
        {
            X.e[count].i = i;
            X.e[count].j = j;
            X.e[count].val = 0;
            count++;
        }
    }
    int valoriAlocate[512];
    int counter = 0;
    while (nrElementeAlocate != X.nrElementeNenule)
    {
        bool test = true;
        int random = rand() % nrElemente;
        valoriAlocate[counter] = random;
        for (int i = 0; i < counter; i++)
        {
            if (random == valoriAlocate[i])
            {
                test = false;
            }
        }
        if (test == true)
        {
            X.e[random].val = rand() % 9 + 1;
            nrElementeAlocate++;
        }
    }
    return X;
}

void afisareMatrice(mRara matrix)
{
    for (int i = 0; i < matrix.nrlini; i++)
    {
        for (int j = 0; j < matrix.nrcol; j++)
        {
            cout << matrix.e[(matrix.nrlini-1) * i + j].val << " ";
        }
        cout << "\n";
    }
}

void matriceSuma(mRara matrice1, mRara matrice2)
{
    mRara suma;
    suma.nrlini = matrice1.nrlini;
    suma.nrcol = matrice1.nrcol;
    int count = 0;
    for (int i = 0; i < matrice1.nrlini; i++)
    {
        for (int j = 0; j < matrice1.nrcol; j++)
        {
            suma.e[count].val = matrice1.e[count].val + matrice2.e[count].val;
            count++;
        }
    }
    afisareMatrice(suma);
}

void matriceProdus(mRara matrice1, mRara matrice2)
{
    mRara produs;
    produs.nrlini = matrice1.nrlini;
    produs.nrcol = matrice1.nrlini;
    int count = 0;
    for (int i = 0; i < matrice1.nrlini; i++)
    {
        for (int j = 0; j < matrice1.nrcol; j++)
        {
            produs.e[count].val = 0;
            count++;
        }
    }
    count = 0;
    for (int i = 0; i < matrice1.nrlini; i++)
    {
        for (int j = 0; j < matrice1.nrlini; j++)
        {
            for (int k = 0; k < matrice1.nrcol; k++)
            {
                produs.e[i * (matrice1.nrlini-1) + j].val += matrice1.e[i * (matrice1.nrlini-1) + k].val * matrice2.e[k * (matrice1.nrlini-1) + j].val;
            }
        }
    }
    afisareMatrice(produs);
}

int main()
{
    srand(time(NULL));
    mRara matrice;
    matrice = citireMatrice();
    afisareMatrice(matrice);
    cout << "\n[Matrice 1]\n";
    mRara matrice1 = citireMatrice();
    afisareMatrice(matrice1);
    cout << "\n[Matrice 2]\n";
    mRara matrice2 = citireMatrice();
    afisareMatrice(matrice2);

    if (matrice1.nrlini == matrice2.nrlini && matrice1.nrcol == matrice2.nrcol)
    {
        cout << "\n[Suma matricelor]:\n";
        matriceSuma(matrice1, matrice2);
    }
    else
    {
        cout << "\nMatricele nu au dimensiuni egale, nu se poate calcula suma lor.\n";
    }

    if (matrice1.nrlini == matrice2.nrcol && matrice2.nrlini == matrice1.nrcol)
    {
        cout << "\n[Produsul matricelor]:\n";
        matriceProdus(matrice1, matrice2);
    }
    else
    {
        cout << "Produsul matricelor nu este posibil.";
    }
    system("pause");
}