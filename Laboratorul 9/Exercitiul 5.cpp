#include <iostream>

int nr_elem, solutii[64];
static int nr_solutii = 0;

void backtrack_sumbultimi(int k, int nr);
bool OK(int k);
bool solutie(int k, int nr);
void print(int nr);
int aranjamente(int nr, int nr_elem);

int main()
{
    int nr;
    std::cout << "n= : ";
    std::cin >> nr_elem;
    std::cout << "k =: ";
    std::cin >> nr;
    std::cout << "Elementele sunt: ";
    for (int i = 1; i <= nr_elem; i++)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
        backtrack_sumbultimi(1, nr);
    system("pause");
}



void backtrack_sumbultimi(int k, int nr)
{
        if (nr_solutii < aranjamente(nr, nr_elem))
        {
            for (int i = 1; i <= nr_elem; i++)
            {
                solutii[k] = i;
                if (OK(k))
                    if (solutie(k, nr))
                    {
                        print(nr);
                        nr_solutii++;
                    }
                    else
                        backtrack_sumbultimi(k + 1, nr);
            }
        }
        nr_solutii = 0;
}

int aranjamente(int nr, int nr_elem){
    int n = 1;
    for (int i = 1; i < nr_elem; i++)
    {
        n = n * i;
    }
    int k = 1;
    for (int i = 1; i < nr; i++)
    {
        k = k * i;
    }
    int aranjamente = n/k;
    return aranjamente;
}


bool solutie(int k, int nr)
{
    if (k == nr)
        return true;
    return false;
}

bool OK(int k)
{
    for (int i = 1; i < k; i++)
        if (solutii[i] == solutii[k])
            return false;
    return true;
}

void print(int nr)
{
    for (int i = 1; i <= nr; i++)
    {
        std::cout << solutii[i] << " ";
    }
    std::cout << std::endl;
}