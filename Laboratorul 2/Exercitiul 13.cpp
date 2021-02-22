#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int sumaDivizori1;
    int sumaDivizori2;
    cout << "Introduceti limita din stanga a intervalului: ";
    cin >> a;
    cout << "Introduceti limita din dreapta a intervalului: ";
    cin >> b;

    for (a; a < b; a++)
    {
        sumaDivizori1 = 0;
        sumaDivizori2 = 0;
        for (int i = 1; i <= a / 2; i++)
        {
            if (a % i == 0)
            {
                sumaDivizori1 += i;
            }
        }
        for (int i = 1; i <= sumaDivizori1 / 2; i++)
        {
            if (sumaDivizori1 % i == 0)
            {
                sumaDivizori2 += i;
            }
        }
        if (sumaDivizori2 == a)
        {
            goto FINAL;
        }
    }
    

    FINAL:
        cout << "Perechea gasita este: (" << a << ", " << sumaDivizori1 << ")";
    system("pause");
}