#include <stdio.h>
#include <iostream>
#include <string.h>

void aparitii(int argc, char *argv[])
{
    int aparitii = 0;
    for (short i = 2; i < argc; i++)
    {
        int count = 0;
        for (short j = 0; j < strlen(argv[i]); j++)
        {
            if (argv[1][j] == argv[i][j])
            {
                count++;
            }
        }
        if (count == strlen(argv[1]))
        {
            aparitii++;
        }
    }
    std::cout << "Cuvantul " << argv[1] << " apare de " << aparitii << " ori" << std::endl;
}

int main(int argc, char *argv[])
{
    aparitii(argc, argv);
    return 0;
}