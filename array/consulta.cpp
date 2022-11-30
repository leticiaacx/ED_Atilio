#include <iostream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &v)
{
    os << " ";
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i];
        if (i != (int)v.size() - 1)
        {
            os << " ";
        }
    }
    os << " ";
    return os;
}

int contar(vector<string> entrada, string sequencia_consulta)
{
    int contador{0};
    for (auto sequencia_entrada : entrada)
    {
        if (sequencia_consulta == sequencia_entrada)
        {
            contador++;
        }
    }
    return contador;
}

vector<int> matchingStrings(vector<string> entrada, vector<string> consulta)
{
    vector<int> res;

    for (auto sequencia_consulta : consulta)
    {
        res.push_back(contar(entrada, sequencia_consulta));
    }

    return res;
}

void inicializar(vector<string> &vetor, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        string line;
        cin >> line;
        vetor.push_back(line);
    }
}

int main()
{
    int tamanho_entrada{0};
    cin >> tamanho_entrada;
    vector<string> entrada;
    entrada.reserve(tamanho_entrada);

    inicializar(entrada, tamanho_entrada);

    int tamanho_consulta{0};
    cin >> tamanho_consulta;
    vector<string> consulta;
    consulta.reserve(tamanho_consulta);

    inicializar(consulta, tamanho_consulta);

    vector<int> resultado = matchingStrings(entrada, consulta);
    cout << resultado << '\n';

    return 0;
}