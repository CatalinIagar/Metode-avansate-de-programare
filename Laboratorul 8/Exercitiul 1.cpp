#include <iostream>
#include <time.h>

void swap(int* a, int* b);
void sorting_algorithms(int nr_elem);
void vector_alloc(int *v, int nr_elem);
void merge_sort(int start, int finish, int *v);
void merge(int start, int middle, int finish, int *v);
void quick_sort(int* v, int low, int high);
int partition(int *v, int low, int high);
int compare(const void* a, const void* b);

int main()
{
    srand(time(NULL));
    sorting_algorithms(100);
    sorting_algorithms(1000);
    sorting_algorithms(10000);
    sorting_algorithms(100000);
    sorting_algorithms(1000000);
    sorting_algorithms(10000000);
    system("pause");
}

void sorting_algorithms(int nr_elem)
{
    clock_t initial_time, final_time;
    int *v = new int[nr_elem];
    std::cout << "\n[Merge Sort][" << nr_elem << " elements]";
    std::cout << "\n[Merge Sort]Allocating array";
    vector_alloc(v, nr_elem);
    std::cout << "\n[Merge sort]Sorting array";
    initial_time = clock();
    merge_sort(0, nr_elem - 1, v);
    final_time = clock();
    std::cout << "\n[Merge sort]Execution time: " << (double)(final_time - initial_time) / CLOCKS_PER_SEC << std::endl;
    std::cout << std::endl;

    std::cout << "\n[Qucik Sort][" << nr_elem << " elements]";
    std::cout << "\n[Qucik Sort]Allocating array";
    vector_alloc(v, nr_elem);
    std::cout << "\n[Qucik sort]Sorting array";
    initial_time = clock();
    quick_sort(v, 0, nr_elem - 1);
    final_time = clock();
    std::cout << "\n[Qucik sort]Execution time: " << (double)(final_time - initial_time) / CLOCKS_PER_SEC << std::endl;
    std::cout << std::endl;

    std::cout << "\n[QSort][" << nr_elem << " elements]";
    std::cout << "\n[QSort]Allocating array";
    vector_alloc(v, nr_elem);
    std::cout << "\n[QSort]Sorting array";
    initial_time = clock();
    qsort(v, nr_elem, sizeof(int), compare);
    final_time = clock();
    std::cout << "\n[QSort]Execution time: " << (double)(final_time - initial_time) / CLOCKS_PER_SEC << std::endl;
    std::cout << std::endl;
    delete[] v;
}

void merge_sort(int start, int finish, int *v)
{
    if (start < finish)
    {
        int middle = (start + finish) / 2;
        merge_sort(start, middle, v);
        merge_sort(middle + 1, finish, v);
        merge(start, middle, finish, v);
    }
}

void merge(int start, int middle, int finish, int *v)
{
    int k = 0;
    int i = start;
    int j = middle + 1;
    int *temp = new int[finish - start + 1];
    while (i <= middle && j <= finish)
    {
        if (v[i] < v[j])
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }
    while (i <= middle)
    {
        temp[k++] = v[i++];
    }
    while (j <= finish)
    {
        temp[k++] = v[j++];
    }
    for (int i = start; i <= finish; ++i)
    {
        v[i] = temp[i - start];
    }
    delete[] temp;
}

void quick_sort(int* v, int low, int high){
    if(low < high){
        int pi = partition(v, low, high);

        quick_sort(v, low, pi - 1);
        quick_sort(v, pi + 1, high);
    }
}

int partition(int* v, int low, int high){
    int pivot = v[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if(v[j] < pivot){
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i+1], &v[high]);
    return (i + 1);
}

void vector_alloc(int *v, int nr_elem)
{
    for (int i = 0; i < nr_elem; i++)
    {
        v[i] = rand() % nr_elem;
    }
}

int compare(const void * a, const void * b) 
{ 
    return ( *(int*)a - *(int*)b ); 
} 

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}