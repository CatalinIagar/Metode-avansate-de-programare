#include <iostream>
#include <fstream>

struct Punct
{
    int x;
    int y;
} gaura[100];

int nr_gauri, latime, inaltime;
int l0 = 0, h0 = 0, x0 = 0, inaltime0 = 0;

void taieturi(int x, int y, int latime, int inaltime);

int main()
{

    std::fstream fintrare;
    fintrare.open("Taieturi2.txt");
    if (fintrare.is_open())
    {
        fintrare >> latime >> inaltime >> nr_gauri;
        for (int i = 0; i < nr_gauri; i++)
        {
            fintrare >> gaura[i].x >> gaura[i].y;
        }
        taieturi(0, 0, latime, inaltime);
        std::cout << "Aria maxima gasita este: " << l0 * h0 << std::endl;
        std::cout << "Coordonatele dreptunghiului sunt: A(" << x0 << ", " << inaltime0 << "), B(" << l0 << ", " << inaltime0 << "), C(" << l0 << ", " << h0 << "), D(" << x0 << ", " << h0 << ") " << std::endl;
    }
    else
    {
        std::cout << "Fisierul nu a fost gasit.";
    }

    system("pause");
}

void taieturi(int x, int y, int latime, int inaltime)
{
    bool gaura_gasita = false;
    int i = 1;
    while (i <= nr_gauri && !gaura_gasita)
    {
        if ((gaura[i].x > x) && (gaura[i].x < (x + latime)) && (gaura[i].y > y) && (gaura[i].y < (y + inaltime)))
            gaura_gasita = true;
        else
            i++;
    }
    if (gaura_gasita)
    {
        taieturi(x, y, gaura[i].x - x, inaltime);
        taieturi(gaura[i].x, y, x + latime - gaura[i].x, inaltime);
        taieturi(x, y, latime, gaura[i].y - y);
        taieturi(x, gaura[i].y, latime, y + inaltime - gaura[i].y);
    }
    else if (latime * inaltime > l0 * h0)
    {
        x0 = x;
        inaltime0 = y;
        l0 = latime;
        h0 = inaltime;
    }
}