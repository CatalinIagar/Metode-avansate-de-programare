#include <iostream>

using namespace std;

void myfunction(int n);

int main()
{
    int n;
    for (int i = 1; i <= 3; i++) {
        cout << "n= ";
        cin >> n;
        myfunction(n);
        cout << endl;
    }
    system("pause");
}

void myfunction(int n) {
    int rasturnat = 0;
    while(n != 0){
        rasturnat = (rasturnat*10) + (n % 10);
        n = n / 10; 
    }
    cout << rasturnat;
}