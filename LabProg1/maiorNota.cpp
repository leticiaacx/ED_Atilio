#include <iostream>
#include <iomanip>

using namespace std;

struct Alunos
{
    int matricula;
    char nome[100];
    double nota;
    char disciplina[120];
};

void compara(Alunos a, Alunos b)
{

    if (a.nota > b.nota)
    {
        cout << a.nome << "," << setprecision(1) << fixed << a.nota << endl;
    }
    else if (b.nota > a.nota)
    {
        cout << b.nome << "," << setprecision(1) << fixed << b.nota << endl;
    }
    else if (a.nota == b.nota)
    {
        cout << a.nome << " e " << b.nome << "," << setprecision(1) << fixed << a.nota << endl;
    }
}

int main()
{

    Alunos a;
    Alunos b;

    cin >> a.nome;
    cin >> a.matricula;
    cin >> a.disciplina;
    cin >> a.nota;

    cin >> b.nome;
    cin >> b.matricula;
    cin >> b.disciplina;
    cin >> b.nota;

    compara(a, b);
}