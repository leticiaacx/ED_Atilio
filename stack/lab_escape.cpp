#include <iostream>
#include <vector>
#include <stack>
#include <time.h>

using namespace std;
using matrix = vector<string>;

struct Pos
{
    int l;
    int c;
};

void show(matrix labirinto)
{
    for (auto line : labirinto)
    {
        cout << line << '\n';
    }
}

vector<Pos> get_vizinhos(Pos p)
{
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

Pos inicio_fim(matrix &labirinto, char procurado)
{
    int nl = labirinto.size();
    int nc = labirinto[0].size();

    for (int l = 0; l < nl; l++)
    {
        for (int c = 0; c < nc; c++)
        {
            if (labirinto[l][c] == procurado)
            {
                labirinto[l][c] = ' ';
                return Pos{l, c};
            }
        }
    }

    return {-1, -1};
}

bool valido(matrix labirinto, Pos p)
{
    if (labirinto[p.l][p.c] != ' ')
    {
        return false;
    }

    return true;
}

vector<Pos> nao_percorridos(vector<Pos> viz, matrix labirinto)
{
    vector<Pos> validos;
    for (auto vizi : viz)
    {
        if (valido(labirinto, vizi))
        {
            validos.push_back(vizi);
        }
    }
    return validos;
}

void remove_(matrix &labirinto)
{
    int nl = labirinto.size();
    int nc = labirinto[0].size();

    for (int l = 0; l < nl; l++)
    {
        for (int c = 0; c < nc; c++)
        {
            if (labirinto[l][c] == '_')
            {
                labirinto[l][c] = ' ';
            }
        }
    }
}

void achar_caminho(matrix &labirinto, Pos inicio, Pos fim)
{
    srand(time(NULL));
    labirinto[inicio.l][inicio.c] = '.';
    stack<Pos> pilha;
    pilha.push(inicio);
    while (!pilha.empty())
    {
        if (pilha.top().l == fim.l && pilha.top().c == fim.c)
        {
            return;
        }

        vector<Pos> vizinhos = nao_percorridos(get_vizinhos(pilha.top()), labirinto);

        if (vizinhos.empty())
        {
            labirinto[pilha.top().l][pilha.top().c] = '_';
            pilha.pop();
        }
        else
        {
            int vq = rand() % vizinhos.size();
            labirinto[vizinhos[vq].l][vizinhos[vq].c] = '.';
            pilha.push(vizinhos[vq]);
        }
    }
}

int main()
{
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    matrix labirinto(nl, "");
    getchar();
    Pos inicio, fim;

    for (int i = 0; i < nl; i++)
    {
        getline(cin, labirinto[i]);
    }

    inicio = inicio_fim(labirinto, 'I');
    fim = inicio_fim(labirinto, 'F');
    achar_caminho(labirinto, inicio, fim);
    remove_(labirinto);
    show(labirinto);

    return 0;
}