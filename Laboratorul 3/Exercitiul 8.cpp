#include <stdio.h>
#include <iostream>
#include <string.h>

void aparitii(int argc, char *argv[])
{
    int nrProp = 0;
    for (short i = 1; i < argc; i++)
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
    aparitii(argc, argv);
    return 0;
}