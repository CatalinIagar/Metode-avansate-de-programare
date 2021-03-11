#include <iostream>
#include <time.h>

typedef int (*TIP_PF)(const void*, const void*);

void cautare_secventiala_int(int v[100000], int nr_elemente, int cheie);
void cautare_secventiala(int nr);
int compara_int(const void *a, const void *b);
int compara_float(const void *a, const void *b);
void *cautare_secventiala_generala(const void *adrCheie, const void *adrBaza, size_t nrel, size_t dimElement, TIP_PF functieComparare);

int main()
{
    srand(time(NULL));
    std::cout << "Timpii de executie pentru N=100 elemente.\n";
    cautare_secventiala(100);
    std::cout << "Timpii de executie pentru N=1000 elemente.\n";
    cautare_secventiala(1000);
    std::cout << "Timpii de executie pentru N=10000 elemente.\n";
    cautare_secventiala(10000);
    std::cout << "Timpii de executie pentru N=100000 elemente.\n";
    cautare_secventiala(100000);
    system("pause");
}

void cautare_secventiala(int nr)
{
    clock_t timpInitial, timpFinal;
    int *v = new int[nr];
    for (int i = 0; i < nr; i++)
    {
        v[i] = rand() % nr / 2;
    }
    int cheie;
    std::cout << "\n\nIntroduceti valoare cautata intre 0 si " << nr / 2 << " : ";
    std::cin >> cheie;
    std::cout << "\n[Cautare secventiala tip int]: " << std::endl;
    timpInitial = clock();
    cautare_secventiala_int(v, nr, cheie);
    timpFinal = clock();
    std::cout << "Timpul de executie este " << (double)(timpFinal - timpInitial) / CLOCKS_PER_SEC;
    std::cout << "\n\n[Cautare secventiala generalizata]: " << std::endl;
    timpInitial = clock();
    int *adrElementGasit = (int *)cautare_secventiala_generala(&cheie, v, nr, sizeof(int), compara_int);
    if (adrElementGasit == NULL)
        std::cout << "Elementul nu e in vector\n";
    else
        std::cout << "Pozitia elementului cautat : " << adrElementGasit - v << std::endl;
    timpFinal = clock();
    std::cout << "Timpul de executie este " << (double)(timpFinal - timpInitial) / CLOCKS_PER_SEC;
    delete[] v;
}

void cautare_secventiala_int(int v[100000], int nr_elemente, int cheie)
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

void *cautare_secventiala_generala(const void *adrCheie, const void *adrBaza, size_t nrel, size_t dimElement, TIP_PF functieComparare)
{
    for (unsigned i = 0; i < nrel; ++i)
    {
        char *adrElement = (char *)adrBaza + dimElement * i;
        if (functieComparare(adrCheie, adrElement) == 0)
            return adrElement;
    }
    return NULL;
}

int compara_int(const void *a, const void *b)
{
    //return ( *(int*)a - *(int*)b );
    if (*(int *)a < *(int *)b)
        return -1;
    else if (*(int *)a == *(int *)b)
        return 0;
    else
        return 1;
}
int compara_float(const void *a, const void *b)
{
    float dif = (*(float *)a - *(float *)b);
    if (dif > 0)
        return 1;
    else if (dif == 0)
        return 0;
    else
        return -1;
}