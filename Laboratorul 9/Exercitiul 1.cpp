#include <iostream>

int solutions[64], nr;

void backtrack_perm(int k);
bool OK(int k);
bool solution(int k);
void print();

int main()
{
    std::cout << "Introduceti numarul de elemente: ";
    std::cin >> nr;
    backtrack_perm(1);
    system("pause");
}

void backtrack_perm(int k){
    for (int i = 1; i <= nr; i++)
    {
        solutions[k] = i;
        if(OK(k)){
            if(solution(k))
                print();
            else
                backtrack_perm(k + 1);
        } 
    }
}

bool OK(int k){
    for (int i = 1; i < k; ++i)
    {
        if(solutions[i] == solutions[k])
            return false;
    }
    return true;
}

bool solution(int k){
    if(k == nr)
        return true;
    return false;
}

void print(){
    for (int i = 1; i <= nr; i++)
    {
        std::cout << solutions[i] << " "; 
    }
    std::cout << std::endl;
}