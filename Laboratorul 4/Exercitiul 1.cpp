#include <iostream>
#include <time.h>
#include <iomanip>

void cautare_secventiala_binara(int nr);
void alocare_elemente(int v[], int nr);
void cautare_secventiala(int v[], int nr_elemente, int cheie);
void cautare_binara(int v[], int inf, int sup, int cheie);
int compare(const void *a, const void *b);

int main()
{
    srand(time(NULL));
    std::cout << "Timpii de executie pentru N=100 elemente.\n";
    cautare_secventiala_binara(100);
    std::cout << "\n\nTimpii de executie pentru N=1000 elemente.\n";
    cautare_secventiala_binara(1000);
    std::cout << "\n\nTimpii de executie pentru N=10000 elemente.\n";
    cautare_secventiala_binara(10000);
    std::cout << "\n\nTimpii de executie pentru N=100000 elemente.\n";
    cautare_secventiala_binara(100000);
    system("pause");
}

void cautare_secventiala_binara(int nr)
{
    clock_t timpInitial, timpFinal;
    int v[100000];
    alocare_elemente(v, nr);
    int cautat = rand() % 100;
    std::cout << "Elementul cautat este " << cautat << "\n\n";
    std::cout << "[Cautare secventiala]: " << std::endl;
    timpInitial = clock();
    cautare_secventiala(v, nr, cautat);
    timpFinal = clock();
    std::cout << "Timpul de executie este " << (double)(timpFinal - timpInitial) / CLOCKS_PER_SEC;
    std::cout << "\n\n[Cautare binara]: " << std::endl;
    qsort(v, nr, sizeof(int), compare);
    timpInitial = clock();
    cautare_binara(v, 0, nr, cautat);
    timpFinal = clock();
    std::cout << std::setprecision(10) << "Timpul de executie este " << (double)(timpFinal - timpInitial) / CLOCKS_PER_SEC;
}

void alocare_elemente(int v[], int nr)
{
    for (short i = 0; i < 100; i++)
    {
        v[i] = rand() % 100;
    }
}

void cautare_secventiala(int v[100000], int nr_elemente, int cheie)
{
    bool gasit = false;
    for (int i = 0; i < nr_elemente; i++)
    {
        if (v[i] == cheie)
        {
            std::cout << "Elementul a fost gasit pe pozitia " << i << std::endl;
            gasit = true;
            break;
        }
    }
    if (!gasit)
    {
        std::cout << "Elementul nu a fost gasit" << std::endl;
    }
}

void cautare_binara(int v[], int inf, int sup, int cheie)
{
    int mij;
    bool gasit = false;
    while (inf <= sup)
    {
        mij = (inf + sup) / 2;
        if (v[mij] == cheie)
        {
            std::cout << "Elementul a fost gasit pe pozitia " << mij << std::endl;
            gasit = true;
            inf = sup + 1;
        }
        else if (v[mij] < cheie)
        {
            inf = mij + 1;
        }
        else
        {
            sup = mij - 1;
        }
    }
    if (!gasit)
    {
        std::cout << "Elementul nu a fost gasit" << std::endl;
    }
}

int compare(const void *a, const void *b)
{
    const int *x = (int *)a;
    const int *y = (int *)b;

    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;

    return 0;
}