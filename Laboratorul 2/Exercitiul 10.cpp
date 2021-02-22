#include <iostream>
#include <string.h>
#include <iostream>
#include <iterator>

using namespace std;

enum zile
{
    Luni = 1,
    Marti,
    Miercuri,
    Joi,
    Vineri
};

void afisareZi(int nr)
{
    switch (nr)
    {
    case 1:
        cout << "luni\n";
        break;
    case 2:
        cout << "marti\n";
        break;
    case 3:
        cout << "miercuri\n";
        break;
    case 4:
        cout << "joi\n";
        break;
    case 5:
        cout << "vineri\n";
        break;
    default:
        break;
    }
}

void afisareFerestre(int nr, int ferestre)
{
    switch (nr)
    {
    case 1:
        cout << "Numar ferestre luni:" << ferestre;
        break;
    case 2:
        cout << "Numar ferestre marti:" << ferestre;
        break;
    case 3:
        cout << "Numar ferestre miercuri:" << ferestre;
        break;
    case 4:
        cout << "Numar ferestre joi:" << ferestre;
        break;
    case 5:
        cout << "Numar ferestre vineri:" << ferestre;
        break;
    default:
        break;
    }
}

int main()
{

    char disciplina[5][100];
    strncpy(disciplina[0], "MAP curs", 100);
    strncpy(disciplina[1], "MAP lab", 100);
    strncpy(disciplina[2], "BD curs", 100);
    strncpy(disciplina[3], "BD lab", 100);
    strncpy(disciplina[4], "Engleza", 100);

    unsigned short orar[5][12] = {
        {1, 1, 1, 0, 0, 2, 2, 2},
        {3, 3, 2, 2, 2},
        {0, 0, 5, 5, 0, 0, 4, 4},
        {0, 0, 5, 5, 0, 0, 4, 4},
        {1, 1, 0, 1, 3, 3},
    };

    short usor = 12, greu = 0, ziusor, zigreu, ziferestre, nrFerestre, nrFerestreMax = 0;
    int contor[5];
    for (int i = 0; i < 5; i++)
    {
        int ii = 0;
        for (int j = 0; j < 12; j++)
        {
            int temp1 = orar[i][j];
            if (temp1 != 0)
            {
                ii = j;
            }
        }
        contor[i] = ii;
    }

    for (int i = 0; i < 5; i++)
    {
        int contor2 = 0;
        nrFerestre = 0;
        for (int j = 0; j < contor[i]; j++)
        {
            if (orar[i][j] != 0)
            {
                contor2++;
            }
            if (orar[i][j] == 0)
            {
                nrFerestre++;
            }
        }
        afisareFerestre(Luni + i, nrFerestre);
        cout << "\n";
        if (usor > contor2)
        {
            usor = contor2;
            ziusor = i;
        }
        if (greu < contor2)
        {
            greu = contor2;
            zigreu = i;
        }
        if (nrFerestreMax < nrFerestre)
        {
            nrFerestreMax = nrFerestre;
            ziferestre = i;
        }
    }
    cout << "Cea mai usoara zi din saptamana este: ";
    afisareZi(Luni + ziusor);
    cout << "Cea mai grea zi din saptamana este: ";
    afisareZi(Luni + zigreu);
    cout << "Ziua cu cele mai multe ferestre este: ";
    afisareZi(Luni + ziferestre);
    system("pause");
}