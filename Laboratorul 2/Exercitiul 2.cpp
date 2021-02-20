#include <iostream>
#include <math.h>

using namespace std;

typedef struct Punct2D
{
    int x, y;
} Punct2D;

Punct2D citirePunct()
{
    Punct2D X;
    cout << "Introduceti x: ";
    cin >> X.x;
    cout << "Introduceti y: ";
    cin >> X.y;
    return X;
}

void distanta(struct Punct2D A, struct Punct2D B)
{
    double distanta;
    distanta = sqrt(pow(abs(B.x - A.x), 2) + pow(abs(B.y - A.y), 2));
    cout << distanta;
}

void centruGreutate(struct Punct2D A, struct Punct2D B, struct Punct2D C)
{
    double x, y;
    x = (double)(A.x + B.x + C.x) / 3;
    y = (double)(A.y + B.y + C.y) / 3;
    cout << "G(" << x << "," << y << ")";
}

void centruGreutatePoligon(struct Punct2D varf[], int nr)
{
    double Gx = 0, Gy = 0;
    double sumaAria = 0;
    for (int i = 0; i < nr; i++)
    {
        sumaAria = sumaAria + ((varf[i].x * varf[i + 1].y) - (varf[i + 1].x * varf[i].y));
    }
    double aria = abs(sumaAria / 2);
    double sumaX = 0, sumaY = 0;
    for (int i = 0; i < nr; i++)
    {
        sumaX = sumaX + ((varf[i].x + varf[i + 1].x) * ((varf[i].x * varf[i + 1].y) - (varf[i + 1].x * varf[i].y)));
        sumaY = sumaY + ((varf[i].y + varf[i + 1].y) * ((varf[i].x * varf[i + 1].y) - (varf[i + 1].x * varf[i].y)));
    }
    Gx = abs(sumaX) / (6 * aria);
    Gy = abs(sumaY) / (6 * aria);
    cout << "Centrul de greutate pentru varfurile introduse este: G(" << Gx << "," << Gy << ").";
}

void sortareVector(struct Punct2D varf[], int nr)
{
    int temp;
    for (int i = 0; i < nr; i++)
    {
        for (int j = i; j < nr; j++)
        {
            if (varf[i].x == varf[j].x)
            {
                if (varf[i].y > varf[j].y)
                {
                    temp = varf[j].y;
                    varf[j].y = varf[i].y;
                    varf[i].y = temp;
                }
            }
            else if (varf[i].x > varf[j].x)
            {
                temp = varf[j].x;
                varf[j].x = varf[i].x;
                varf[i].x = temp;
            }
        }
    }
}

int main()
{
    Punct2D A, B, C;
    cout << "Punctul A\n";
    A = citirePunct();
    cout << "Punctul B\n";
    B = citirePunct();
    cout << "Punctul C\n";
    C = citirePunct();

    cout << "\nDistanta dintre punctele A si B este: ";
    distanta(A, B);
    cout << "\nDistanta dintre punctele A si C este: ";
    distanta(A, C);
    cout << "\nDistanta dintre punctele B si C este: ";
    distanta(B, C);
    cout << "\nCentrul de greutate al punctelor A, B si C este: ";
    centruGreutate(A, B, C);

    int nrVarfuri;
    cout << "\n\nIntroduceti numarul de varfuri dorite: ";
    cin >> nrVarfuri;

    Punct2D varf[1000];
    for (int i = 0; i < nrVarfuri; i++)
    {
        cout << "Coordonatele punctului varf[" << i << "]\n";
        varf[i] = citirePunct();
    }
    varf[nrVarfuri].x = varf[0].x;
    varf[nrVarfuri].y = varf[0].y;
    centruGreutatePoligon(varf, nrVarfuri);
    sortareVector(varf, nrVarfuri);
    for (int i = 0; i < nrVarfuri; i++)
    {
        cout << "\nvarf[" << i << "](" << varf[i].x << "," << varf[i].y << ")";
    }
    system("pause");
}