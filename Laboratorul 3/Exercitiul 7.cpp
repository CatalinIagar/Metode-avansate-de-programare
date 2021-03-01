#include <stdio.h>
#include <iostream>
#include <string.h>

void aparitii(int argc, char *argv[])
{
    int nrcuvinte = 0;
    for (short i = 1; i < argc; i++)
    {
        nrcuvinte += strlen(argv[i]);
    }
    std::cout << "Numar caractere gasite " << nrcuvinte + argc - 2 << std::endl;
}

int main(int argc, char *argv[])
{
    aparitii(argc, argv);
    return 0;
}