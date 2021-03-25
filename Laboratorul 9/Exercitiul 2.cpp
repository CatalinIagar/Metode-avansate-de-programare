#include <iostream>

#define N 4

void solve_Nqueen();
bool solve(int board[N][N], int col);
bool isSafe(int board[N][N], int row, int col);
void print(int board[N][N]);

int main()
{
    solve_Nqueen();
    system("pause");
}

void solve_Nqueen()
{
    int board[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }
    if (solve(board, 0) == false)
    {
        std::cout << "Nu exista solutii.";
        return;
    }
    return;
}

bool solve(int board[N][N], int col)
{
    if (col == N)
    {
        print(board);
        return true;
    }

    bool result = false;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            result = solve(board, col + 1) || result;
            board[i][col] = 0;
        }
    }
    return result;
}

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
    //stanga
    for (i = 0; i < col; i++)
        if(board[row][i])
            return false;

    //diagonala sus stanga
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return false;

    //diagonala jos stanga
    for(i = row, j = col; j >= 0 && i < N; i++, j--)
        if(board[i][j])
            return false;
    
    return true;
}

void print(int board[N][N]){
    static int k = 1;
    std::cout << "Solutia " << k << std::endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    k++;
}
