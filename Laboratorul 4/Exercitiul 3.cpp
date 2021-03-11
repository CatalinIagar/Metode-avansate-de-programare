#include <iostream>
#include <time.h>

typedef int (*TIP_PF)(const void*, const void*);

void cautare_binara_generalizata(int nr);
int compara_int(const void *a, const void *b);
int compara_float(const void *a, const void *b);
void* cautare_binara_generala(const void* adrCheie,const void* adrBaza,size_t nrel,size_t dimElement, TIP_PF functieComparare);

int main()
{
    srand(time(NULL));
    std::cout << "Timpii de executie pentru N=100 elemente.\n";
    cautare_binara_generalizata(100);
    std::cout << "Timpii de executie pentru N=1000 elemente.\n";
    cautare_binara_generalizata(1000);
    std::cout << "Timpii de executie pentru N=10000 elemente.\n";
    cautare_binara_generalizata(10000);
    std::cout << "Timpii de executie pentru N=100000 elemente.\n";
    cautare_binara_generalizata(100000);
    system("pause");
}

void cautare_binara_generalizata(int nr)
{
    clock_t timpInitial, timpFinal;

    int *v = new int[nr];
    for (int i = 0; i < nr; i++)
    {
        v[i] = rand() % nr / 2;
    }
    int cheie;
    std::cout << "\nIntroduceti valoare cautata intre 0 si " << nr / 2 << " : ";
    std::cin >> cheie;

    qsort(v, nr, sizeof(int), compara_int);
    timpInitial = clock();
    int *adrElementGasit = (int *)cautare_binara_generala(&cheie, v, nr, sizeof(int), compara_int);
    if (adrElementGasit == NULL)
        std::cout << "Elementul nu e in vector\n";
    else
        std::cout << "Pozitia elementului cautat : " << adrElementGasit - v << std::endl;
    timpFinal = clock();
    std::cout << "Timpul de executie este " << (double)(timpFinal - timpInitial) / CLOCKS_PER_SEC << std::endl <<std::endl;

    delete[] v;
}

void* cautare_binara_generala(const void* adrCheie,const void* adrBaza,size_t nrel,size_t dimElement, TIP_PF functieComparare){
	char* adrInc=(char*)adrBaza;
	char* adrSf=(char*)adrBaza+dimElement*nrel;
	char* adrMij;
	while(adrInc<=adrSf)
	{
		int dif=(adrSf-adrInc)/dimElement;
		adrMij=adrInc+dif/2*dimElement;

		if(functieComparare(adrCheie,adrMij)==0) 
			return adrMij; 
		else
			if(functieComparare(adrCheie,adrMij)<0) 
				adrSf=adrMij-(1*dimElement);
			else 
				  adrInc=adrMij+(1*dimElement);
	}
	return NULL;	
}

int compara_int(const void *a, const void *b)
{
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