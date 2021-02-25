#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int comparare(const void* a, const void* b)
{
    return (*(char*)a - *(char*)b);
}

int main()
{
    char litere[50];
    int contor = 0;
    bool test = true;
    while (test)
    {
        fflush(stdin);
        cout << "Introduceti o litera mica: ";
        litere[contor] = getchar();
        cout << "Ati introdus: " << litere[contor] << "\n";
        for (int i = 0; i < contor; i++)
        {
            if (litere[i] == litere[contor])
            {
                test = false;
                cout << "Ati introdus o litera deja introdusa.\n";
            }
        }
        contor++;
    }
    qsort(litere, contor, sizeof(char), comparare);
    cout << "Literele introduse in ordine invers alfabetica sunt: ";
    for (int i = 0; i < contor - 1; i++)
    {
        cout << litere[i] << " ";
    }
    system("pause");
}