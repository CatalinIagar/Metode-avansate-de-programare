#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

typedef struct Disciplina
{
    string denumire;
    int nota;
} Disciplina;

typedef struct Student
{
    string nume;
    string prenume;
    Disciplina d[10];
    double medie;
} Student;

Student citesteStudent(int nrStd, int nrDisc, Student Std)
{
    fflush(stdin);
    Student X;
    cout << "\n[Student " << nrStd + 1 << "]: \n";
    cout << "Introduceti numele studentului: ";
    getline(cin, X.nume);
    cout << "Introduceti prenumele studentului: ";
    getline(cin, X.prenume);
    if (nrStd == 0)
    {
        for (int j = 0; j < nrDisc; j++)
        {
            fflush(stdin);
            cout << "[Materia " << j + 1 << "]Introduceti disciplina dorita: ";
            getline(cin, X.d[j].denumire);
            cout << "Introduceti nota dorita: ";
            cin >> X.d[j].nota;
        }
    }
    else
    {
        for (int k = 0; k < nrDisc; k++)
        {
            X.d[k].denumire = Std.d[k].denumire;
            cout << "Introduceti nota la " << X.d[k].denumire << ": ";
            cin >> X.d[k].nota;
        }
    }
    return X;
}

float medieNote(int nrDisc, Student Std)
{
    float suma = 0;
    for (int j = 0; j < nrDisc; j++)
    {
        suma += Std.d[j].nota;
    }
    suma /= (float)nrDisc;
    return suma;
}

bool comparare(Student s1, Student s2)
{
    return (s1.medie > s2.medie);
}

int main()
{
    int nrStudenti;
    int nrDiscipline;

    cout << "Introduceti  numarul de studenti doriti: ";
    cin >> nrStudenti;

    cout << "Introduceti numarul de discipline dorite: ";
    cin >> nrDiscipline;

    Student studenti[100];

    for (int i = 0; i < nrStudenti; i++)
    {
        studenti[i] = citesteStudent(i, nrDiscipline, studenti[0]);
    }
    for (int i = 0; i < nrStudenti; i++)
    {
        studenti[i].medie = medieNote(nrDiscipline, studenti[i]);
    }
    sort(studenti, studenti + nrDiscipline, comparare);
    cout << "\nStudentii in oridne descrescatoare a medie sunt: \n";
    for (int i = 0; i < nrStudenti; i++)
    {
        cout << "[Studentul " << i + 1 << "]:\n";
        cout << studenti[i].nume << "\n";
        cout << studenti[i].prenume << "\n";
        cout << studenti[i].medie << "\n";
    }
    system("pause");
}