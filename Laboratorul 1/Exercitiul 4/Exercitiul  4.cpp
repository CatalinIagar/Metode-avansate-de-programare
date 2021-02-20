#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fiesire;
    char ch;
    fiesire.open("ex4out.txt");
    while ((ch = getchar()) != EOF)
    {
        if (ch == ' ')
        {
            fiesire << ' ';
        }
        else if (ch == '\n')
        {
            fiesire << '\n';
        }
        else if (ch == 26)
        {
            break;
        }
        else
        {
            fiesire << ch;
        }
    }
    fiesire.close();
    return 0;
}