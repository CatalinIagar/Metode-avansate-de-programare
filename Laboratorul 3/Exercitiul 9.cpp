#include <stdio.h>
#include <iostream>
#include <string.h>

void aparitiiCuvinte(int argc, char *argv[], int nr)
{
    int aparitii = 0;
    for (short i = nr + 1; i < argc; i++)
    {
        int count = 0;
        for (short j = 0; j < strlen(argv[i]); j++)
        {
            if (argv[nr][j] == argv[i][j])
            {
                count++;
            }
        }
        if (count == strlen(argv[nr]))
        {
            aparitii++;
        }
    }
    std::cout << "Cuvantul " << argv[nr] << " apare de " << aparitii << " ori" << std::endl;
}

void aparitiiCaractere(int argc, char *argv[], int nr)
{
    int nrCh = 0;
    for (short i = nr; i < argc; i++)
    {
        nrCh += strlen(argv[i]);
    }
    std::cout << "Numar caractere gasite " << nrCh + argc - nr - 1 << std::endl;
}

void aparitiiPropozitii(int argc, char *argv[], int nr)
{
    int nrProp = 0;
    for (short i = nr; i < argc; i++)
    {
        int nrCaracter = strlen(argv[i]) - 1;
        if (argv[i][nrCaracter] == '.' || argv[i][nrCaracter] == '!' || argv[i][nrCaracter] == '?')
        {
            nrProp++;
        }
    }
    std::cout << "Au fost gasite " << nrProp << " propozitii." << std::endl;
}

int main(int argc, char *argv[])
{
    short contor = 0;
    for (short i = 1; i <= 3; i++)
    {
        if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "-p") == 0)
        {
            contor++;
        }
    }
    for (short i = 1; i <= contor; i++)
    {
        short test;
        if (strcmp(argv[i], "-c") == 0)
        {
            test = 1;
        }else if(strcmp(argv[i], "-l") == 0){
            test = 2;
        }else if(strcmp(argv[i], "-p") == 0){
            test = 3;
        }
        switch (test)
        {
        case 1:
            aparitiiCuvinte(argc, argv, contor + 1);
            break;
        case 2:
            aparitiiCaractere(argc, argv, contor + 1);
            break;
        case 3:
            aparitiiPropozitii(argc, argv, contor + 1);
            break;

        default:
            break;
        }
    }
    return 0;
}