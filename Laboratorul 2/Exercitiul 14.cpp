#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //Initializare timp
    srand(time(NULL));
    int rasp;
    string raspuns;

    cout << "Introdu ce parte vrei: 1 sau 2: ";
    cin >> rasp;
    if (rasp == 1)
        goto part1;
    if (rasp == 2)
        goto part2;
    else
        return -1;

part1:

    cout << "Incepe generarea de numere. (Apasa enter)" << endl;
    system("pause");

    while (true)
    {
        int numar_random = rand() % RAND_MAX + -RAND_MAX;
        cout << "Numar generat: " << numar_random << ". Continui? (introdu da/nu)" << endl;
        cin >> raspuns;

        if (raspuns == "nu")
        {
            cout << "Generarea s-a oprit." << endl;
            break;
        }
    }

    system("pause");
    system("cls");

part2:

    cout << "Partea a 2-a" << endl;

    ifstream fintrare;
    fintrare.open("ex14in.txt");

    if (!fintrare.is_open())
    {
        cout << "Eroare deschidere fisier.";
        return -2;
    }

    while (!fintrare.eof())
    {
        int lim_stanga, lim_dreapta;

        fintrare >> lim_stanga;
        fintrare >> lim_dreapta;

        cout << "Interval gasit: [" << lim_stanga << ", " << lim_dreapta << "]" << ". Numere in interval: " << lim_dreapta - lim_stanga + 1 << endl;
    }
    system("pause");
    return 0;
}