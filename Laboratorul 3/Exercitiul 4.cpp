#include <iostream>
#include <stdarg.h>
using namespace std;

void afisare_numere(int n, ...);

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

int main()
{
    afisare_numere(5, 3, 4, 8, 1, 9);

    system("pause");
    return 0;
}

void afisare_numere(int n, ...)
{
    va_list argumente;
    va_start(argumente, n);
    int vector[50];
    for (int i = 0; i < n; i++)
    {
        vector[i] = va_arg(argumente, int);
    }
    for (int i = 0; i < n; i++)
    {
        cout << vector[i] << " ";
    }
    qsort(vector, n, sizeof(int), compare);

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << vector[i] << " ";
    }

    va_end(argumente);
}