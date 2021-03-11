#include <iostream>
#include <time.h>
#include <Windows.h>

void sorting_algorithms(int nr);
void vector_alloc(int v[], int nr);
void insertion_sort(int v[], int nr);
void shell_sort(int v[], int nr);
void selection_sort(int v[], int nr);
void counting_sort(int v[], int nr);
void bubble_sort(int v[], int nr);
void cocktail_sort(int v[], int nr);

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

    std::cout << "\n[Insertion sort][" << nr << " elements]" << std::endl;
    std::cout << "[Insertion sort]Allocating array" << std::endl;
    std::cout << "[Insertion sort]Sorting array" << std::endl;
    vector_alloc(v, nr);
    timp_initial = clock();
    insertion_sort(v, nr);
    timp_final = clock();
    std::cout << "[Insertion sort]Execution time:  " << (double)(timp_final - timp_initial) / CLOCKS_PER_SEC << std::endl;

    std::cout << "\n[Shell sort][" << nr << " elements]" << std::endl;
    std::cout << "[Shell sort]Allocating array" << std::endl;
    std::cout << "[Shell sort]Sorting array" << std::endl;
    vector_alloc(v, nr);
    timp_initial = clock();
    shell_sort(v, nr);
    timp_final = clock();
    std::cout << "[Shell sort]Execution time:  " << (double)(timp_final - timp_initial) / CLOCKS_PER_SEC << std::endl;

    std::cout << "\n[Selection sort][" << nr << " elements]" << std::endl;
    std::cout << "[Selection sort]Allocating array" << std::endl;
    std::cout << "[Selection sort]Sorting array" << std::endl;
    vector_alloc(v, nr);
    timp_initial = clock();
    selection_sort(v, nr);
    timp_final = clock();
    std::cout << "[Selection sort]Execution time:  " << (double)(timp_final - timp_initial) / CLOCKS_PER_SEC << std::endl;

    std::cout << "\n[Bubble sort][" << nr << " elements]" << std::endl;
    std::cout << "[Bubble sort]Allocating array" << std::endl;
    std::cout << "[Bubble sort]Sorting array" << std::endl;
    vector_alloc(v, nr);
    timp_initial = clock();
    bubble_sort(v, nr);
    timp_final = clock();
    std::cout << "[Bubble sort]Execution time:  " << (double)(timp_final - timp_initial) / CLOCKS_PER_SEC << std::endl;

    std::cout << "\n[Cocktail sort][" << nr << " elements]" << std::endl;
    std::cout << "[Cocktail sort]Allocating array" << std::endl;
    std::cout << "[Cocktail sort]Sorting array" << std::endl;
    vector_alloc(v, nr);
    timp_initial = clock();
    cocktail_sort(v, nr);
    timp_final = clock();
    std::cout << "[Cocktail sort]Execution time:  " << (double)(timp_final - timp_initial) / CLOCKS_PER_SEC << std::endl;

    std::cout << "\n[Counting sort][" << nr << " elements]" << std::endl;
    std::cout << "[Counting sort]Allocating array" << std::endl;
    std::cout << "[Counting sort]Sorting array" << std::endl;
    vector_alloc(v, nr);
    timp_initial = clock();
    counting_sort(v, nr);
    timp_final = clock();
    std::cout << "[Counting sort]Execution time:  " << (double)(timp_final - timp_initial) / CLOCKS_PER_SEC << std::endl;
}

void insertion_sort(int v[], int nr)
{
    long long i, j, temp;
    for (i = 0; i < nr; i++)
    {
        temp = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > temp)
        {
            v[j + 1] = v[j];
            j -= 1;
        }
        v[j + 1] = temp;
    }
}

void shell_sort(int v[], int nr)
{

    long long temp, i, j;

    for (int gap = nr/2; gap > 0; gap /= 2)
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

void selection_sort(int v[], int nr)
{
    for (long long i = 0; i < nr - 2; i++)
    {
        for (long long j = i + 1; j < nr - 1; j++)
        {
            if (v[i] > v[j])
            {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

void counting_sort(int v[], int nr)
{
    long long i, j, temp;
    long long contor[100001] = {0};
    long long dest[100001] = {0};
    for (i = 0; i < nr - 1; ++i)
        for (j = i + 1; j < nr; ++j)
            if (v[i] > v[j])
                contor[i]++;
            else
                contor[j]++;
    for (i = 0; i < nr; i++)
    {
        dest[contor[i]] = v[i];
    }
}

void bubble_sort(int v[], int nr)
{
    bool sorted;
    do
    {
        sorted = true;
        for (long long i = 0; i < nr - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                sorted = false;
            }
        }

    } while (sorted == false);
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