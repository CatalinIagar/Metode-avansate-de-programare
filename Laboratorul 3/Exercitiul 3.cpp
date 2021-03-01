#include <iostream>
#include <fstream>

using namespace std;

int compare (const void * elem1, const void * elem2) {
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int main()
{
    int n, m, a[512][512];
    ifstream fintrare;
    fintrare.open("ex3in.txt");
    if (fintrare.is_open())
    {
        fintrare >> n;
        fintrare >> m;
        for (short i = 0; i < n; i++)
        {
            for (short j = 0; j < m; j++)
            {
                fintrare >> a[i][j];
            }
        }
        cout << "Matricea gasita:\n";
        for (short i = 0; i < n; i++)
        {
            for (short j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\n Matricea sortata dupa prima coloana:\n";
        qsort(a, n, sizeof(a[0]), compare);
        for (short i = 0; i < n; i++)
        {
            for (short j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "eroare";
    }
    fintrare.close();
    system("pause");
}