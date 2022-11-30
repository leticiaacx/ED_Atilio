#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <time.h>

using namespace std;

using matrix = vector<string>;

void show(vector<string> floresta)
{
    cout << '\n';
    for (auto line : floresta)
    {
        cout << line << '\n';
    }
}

struct Pos
{
    int l;
    int c;
    Pos(int l, int c) : l(l), c(c){};
};

vector<Pos> get_vizinhos(Pos p)
{
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

vector<Pos> podem_queimar(vector<Pos> v, matrix matriz)
{
    vector<Pos> queimam;
    int nl = matriz.size();
    int nc = matriz[0].size();

    for (int i = 0; i < (int)v.size(); i++)
    {
        if (v[i].l < 0 || v[i].l >= nl || v[i].c < 0 || v[i].c >= nc)
        {
            continue;
        }

        if (matriz[v[i].l][v[i].c] != '#')
        {
            continue;
        }

        queimam.push_back(v[i]);
    }
    return queimam;
}

/*verifique a primeira posição e queime-o
inicie a pilha com esse elemento
enquanto a pilha não estiver vazia faça
    pegue topo da pilha
    faça uma lista com todos os vizinhos de topo que podem ser queimados
    se lista eh vazia
        desempilhe
    senão
        escolha um dos vizinhos
        queime
        empilhe
*/

void queimar(matrix &matriz, Pos p)
{
    srand(time(NULL));
    // int nl = matriz.size();
    // int nc = matriz[0].size();

    if (matriz[p.l][p.c] != '#')
    {
        return;
    }

    matriz[p.l][p.c] = 'o';

    stack<Pos> pilha;
    pilha.push(p);

    while (!pilha.empty())
    {
        vector<Pos> queimaveis = podem_queimar(get_vizinhos(pilha.top()), matriz);
        if (queimaveis.empty())
        {
            pilha.pop();
        }
        else
        {
            // sorteando o vizinho a ser queimado
            int vq = rand() % queimaveis.size();
            matriz[queimaveis[vq].l][queimaveis[vq].c] = 'o';
            pilha.push(queimaveis[vq]);
        }
    }
}

int main()
{
    matrix floresta;
    int nl{}, nc{}, li{}, ci{};
    cin >> nl >> nc >> li >> ci;
    for (int l = 0; l < nl; l++)
    {
        string line;
        cin >> line;
        floresta.push_back(line);
    }
    Pos pos_inicio(li, ci);
    queimar(floresta, pos_inicio);
    show(floresta);

    return 0;
}