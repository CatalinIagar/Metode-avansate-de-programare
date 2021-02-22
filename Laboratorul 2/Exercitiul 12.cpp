#include <iostream>
#include <algorithm>
#include <time.h>
#include <string>

using namespace std;

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    srand(time(NULL));
    int nr[100000];
    int contorNr = 0;
    while (true)
    {
        int temp = rand() % 10000 - 5000;
        cout << temp << "\n";
        if (temp == 0)
        {
            break;
        }
        else 
        {
            nr[contorNr] = temp;
            contorNr++;
        }
    }
    //sort(nr, nr + contorNr);
    qsort(nr, contorNr, sizeof(int), compare);
    for (int i = 0; i < contorNr; i++)
    {
        cout << nr[i] << " ";
    }
    system("pause");
}