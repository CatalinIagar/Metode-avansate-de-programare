#include <iostream>
#include <time.h>

void binary_search(int nr);
int binary_search_iterative(int vector[], int left, int right, int key);
int binary_search_recursive(int vector[], int left, int right, int key);
void vector_alloc(int vector[], int nr);
int compare(const void *a, const void *b);

int main()
{
    srand(time(NULL));
    binary_search(100);
    binary_search(1000);
    binary_search(10000);
    binary_search(100000);
    system("pause");
}

void binary_search(int nr)
{
    clock_t initalTime, finalTime;
    int vector[nr];
    int key;

    vector_alloc(vector, nr);
    qsort(vector, nr, sizeof(int), compare);

    std::cout << "\n[Iterative]Introduceti elementul cautat(1, " << nr << "): ";
    std::cin >> key;

    initalTime = clock();
    int result = binary_search_iterative(vector, 0, nr, key);
    finalTime = clock();
    if (result == -1)
        std::cout << "[Iterative]Elemntul nu a fost gasit.";
    else
        std::cout << "[Iterative]Elementul a fost gasit.";
    std::cout << "\n[Iterative]Execution time:  " << (double)(finalTime - initalTime) / CLOCKS_PER_SEC << std::endl;

    initalTime = clock();
    result = binary_search_recursive(vector, 0, nr, key);
    finalTime = clock();
    if (result == -1)
        std::cout << "[Recursive]Elemntul nu a fost gasit.";
    else
        std::cout << "[Recursive]Elementul a fost gasit.";
    std::cout << "\n[Recursive]Execution time:  " << (double)(finalTime - initalTime) / CLOCKS_PER_SEC << std::endl;

    initalTime = clock();
    int* resultBsearch = (int*)bsearch(&key,vector,nr, sizeof(int), compare);
    finalTime = clock();
    if (resultBsearch == NULL)
        std::cout << "[Bsearch]Elemntul nu a fost gasit.";
    else
        std::cout << "[Bsearch]Elementul a fost gasit.";
    std::cout << "\n[Bsearch]Execution time:  " << (double)(finalTime - initalTime) / CLOCKS_PER_SEC << std::endl;
}

int binary_search_recursive(int vector[], int left, int right, int key)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;
        if (vector[mid] == key)
            return mid;

        if (vector[mid] < key)
            return binary_search_recursive(vector, left, mid - 1, key);
        else
            return binary_search_recursive(vector, mid + 1, right, key);
    }
    return -1;
}

int binary_search_iterative(int vector[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (vector[mid] == key)
            return mid;

        if (vector[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void vector_alloc(int vector[], int nr)
{
    for (long long i = 0; i < nr; i++)
    {
        vector[i] = rand() % nr;
    }
}

int compare(const void *a, const void *b)
{
    return ((int *)a - (int *)b);
}