#include <iostream>
#include <string>

struct Obiecte
{
    std::string nume;
    int greutate;
    int pret;
} obiect[64];

void backtrack_rucsac(int k);
void rezolvare();
bool verificare(int k);
void afisare();

int nrElemente, greutate, greutateMax, solutii[64], vec[64], nrSolutii, sumaMax;

int main()
{
    std::cout << "Introduceti numarul de obiecte: ";
    std::cin >> nrElemente;
    std::cout << "Introduceti greutatea maxima: ";
    std::cin >> greutateMax;
    for (int i = 1; i <= nrElemente; i++)
    {
        std::cout << "[Obiectul " << i << "]Introduceti numele: ";
        std::cin >> obiect[i].nume;
        std::cout << "[Obiectul " << i << "]Introduceti greutatea: ";
        std::cin >> obiect[i].greutate;
        std::cout << "[Obiectul " << i << "]Introduceti pretul: ";
        std::cin >> obiect[i].pret;
    }
    backtrack_rucsac(1);
    afisare();
    system("pause");
}

void afisare(){
    nrSolutii++;
    std::cout << "Castigul maxim este: " << sumaMax << std::endl;
    for (int i = 1; i <= nrElemente; i++)
        if(solutii[i])
            std::cout << obiect[i].nume << " " << obiect[i].greutate << " " << obiect[i].pret << std::endl;
    
}

void rezolvare()
{
    int suma = 0;
    nrSolutii++;
    for (int i = 1; i <= nrElemente; i++)
        suma += vec[i] * obiect[i].pret;
    if (nrSolutii == 0 || (suma >= sumaMax))
    {
        sumaMax = suma;
        for (int i = 1; i <= nrElemente; i++)
            solutii[i] = vec[i];
    }
}

bool verificare(int k)
{
    greutate = 0;
    for (int i = 1; i <= k; i++)
        greutate += vec[i] * obiect[i].greutate;
    if (greutate <= greutateMax)
        return true;
    return false;
}

void backtrack_rucsac(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        vec[k] = i;
        if (verificare(k))
            if (k == nrElemente)
                rezolvare();
            else
                backtrack_rucsac(k + 1);
    }
}