#include <iostream>
#include <vector>

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

void rotacionar(vector<int> &v, int tam)
{
    vector<int> aux(tam);
    aux[0] = v[(int)v.size() - 1];
    for (int i = 0; i < (int)v.size() - 1; i++)
    {
        aux[i + 1] = v[i];
    }

    v = aux;
}

void inicializar(vector<int> &vetor, int tam)
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

    int tam{0};
    int rotar{0};
    cin >> tam >> rotar;
    vector<int> l;
    l.reserve(tam);

    inicializar(l, tam);

    for (int i = 0; i < rotar; i++)
    {
        rotacionar(l, tam);
    }

    cout << l << '\n';
    return 0;
}