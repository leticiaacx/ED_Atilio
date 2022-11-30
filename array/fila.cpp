#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &v)
{
    os << "[ ";
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i];
        if (i != (int)v.size() - 1)
        {
            os << ", ";
        }
    }
    os << " ]";
    return os;
}

// forma horrivel ps: fuja dela
void remover_desistentes(vector<int> &fila, int desistiu)
{
    for (int i = 0; i < (int)fila.size(); i++)
    {
        if (fila[i] == desistiu)
        {
            fila.erase(fila.begin() + i);
            return;
        }
    }
}

// forma sensacional
vector<int> quem_sobrou_sucesso(vector<int> fila, vector<int> sairam)
{
    vector<int> sobraram;
    unordered_set<int> sairam_set(begin(sairam), end(sairam));

    for (auto elem : fila)
    {
        if (sairam_set.find(elem) == sairam_set.end())
        {
            sobraram.push_back(elem);
        }
    }
    return sobraram;
}

void filaizar(vector<int> &vetor, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        int line;
        cin >> line;
        vetor.push_back(line);
    }
}

int main()
{
    int n{0};
    cin >> n;
    vector<int> fila;
    fila.reserve(n);

    filaizar(fila, n);

    int m{0};
    cin >> m;
    vector<int> desistentes;
    desistentes.reserve(m);

    filaizar(desistentes, m);
    // forma triste
    /*for (int i = 0; i < m; i++) {
        remover_desistentes(fila, desistentes[i]);
    }*/

    // forma show
    cout << quem_sobrou_sucesso(fila, desistentes) << '\n';

    return 0;
}