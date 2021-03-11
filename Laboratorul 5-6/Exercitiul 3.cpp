#include <iostream>
#include <time.h>
#include <Windows.h>

void sorting_algorithms(int nr);
int compare(const void *a, const void *b);
void shell_sort(int v[], int nr);
void vector_alloc(int v[], int nr);

int main()
{
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

    std::cout << "\n[QSort][" << nr << " elements]" << std::endl;
    std::cout << "[QSort]Allocating array" << std::endl;
    std::cout << "[QSort]Sorting array" << std::endl;
    vector_alloc(v, nr);
    timp_initial = clock();
    qsort(v, nr, sizeof(int), compare);
    timp_final = clock();
    std::cout << "[QSort]Execution time:  " << (double)(timp_final - timp_initial) / CLOCKS_PER_SEC << std::endl;

    std::cout << "\n[Shell sort][" << nr << " elements]" << std::endl;
    std::cout << "[Shell sort]Allocating array" << std::endl;
    std::cout << "[Shell sort]Sorting array" << std::endl;
    vector_alloc(v, nr);
    timp_initial = clock();
    shell_sort(v, nr);
    timp_final = clock();
    std::cout << "[Shell sort]Execution time:  " << (double)(timp_final - timp_initial) / CLOCKS_PER_SEC << std::endl;
}

void shell_sort(int v[], int nr)
{

    long long temp, i, j;

    for (int gap = nr / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < nr; i++)
        {
            temp = v[i];
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap)
                v[j] = v[j - gap];
            v[j] = temp;
        }
    }
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void vector_alloc(int v[], int nr)
{
    for (long long i = 0; i < nr; i++)
    {
        v[i] = rand() % nr;
    }
}