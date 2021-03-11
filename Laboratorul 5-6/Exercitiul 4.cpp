#include <iostream>
#include <time.h>

void sorting_algorithms(int nr);
void vector_alloc(int v[], int nr);
void cocktail_sort(int v[], int nr);
int compare(const void *a, const void *b);
int compareinv(const void* a, const void* b);

int main(){
    sorting_algorithms(100);
    sorting_algorithms(1000);
    sorting_algorithms(10000);
    sorting_algorithms(100000);

    system("pause");
}

void sorting_algorithms(int nr)
{
    clock_t timp_initial, timp_final;
    int v[100001];

    std::cout << "\n[Cocktail sort][" << nr << " elements][General case]" << std::endl;
    std::cout << "[Cocktail sort]Allocating array" << std::endl;
    std::cout << "[Cocktail sort]Sorting array" << std::endl;
    vector_alloc(v, nr);
    timp_initial = clock();
    cocktail_sort(v, nr);
    timp_final = clock();
    std::cout << "[Cocktail sort]Execution time:  " << (double)(timp_final - timp_initial) / CLOCKS_PER_SEC << std::endl;

    qsort(v, nr, sizeof(int), compare);
    std::cout << "\n[Cocktail sort][" << nr << " elements][Sorted array]" << std::endl;
    std::cout << "[Cocktail sort]Allocating array" << std::endl;
    std::cout << "[Cocktail sort]Sorting array" << std::endl;
    timp_initial = clock();
    cocktail_sort(v, nr);
    timp_final = clock();
    std::cout << "[Cocktail sort]Execution time:  " << (double)(timp_final - timp_initial) / CLOCKS_PER_SEC << std::endl;

    qsort(v, nr, sizeof(int), compareinv);
    std::cout << "\n[Cocktail sort][" << nr << " elements][Desceding order]" << std::endl;
    std::cout << "[Cocktail sort]Allocating array" << std::endl;
    std::cout << "[Cocktail sort]Sorting array" << std::endl;
    timp_initial = clock();
    cocktail_sort(v, nr);
    timp_final = clock();
    std::cout << "[Cocktail sort]Execution time:  " << (double)(timp_final - timp_initial) / CLOCKS_PER_SEC << std::endl;
}

void cocktail_sort(int v[], int nr)
{
    int temp;
    bool swapped;
    long long i, j;
    do
    {
        swapped = false;
        for (i = 0; i <= nr - 2; ++i)
            if (v[i] > v[i + 1])
            {
                temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                swapped = true;
            }

        if (swapped == false)
            break;

        swapped = false;
        for (i = nr - 2; i >= 0; --i)
            if (v[i] > v[i + 1])
            {
                temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                swapped = true;
            }
    } while (swapped);
}

void vector_alloc(int v[], int nr)
{
    for (long long i = 0; i < nr; i++)
    {
        v[i] = rand() % nr;
    }
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int compareinv(const void* a, const void* b)
{ 
   return (*(int *)b - *(int *)a);
 }