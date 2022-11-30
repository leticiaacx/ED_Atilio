#include <iostream>
#include <vector>
using namespace std;

void show(vector<int> vet)
{
    cout << "[";
    for (auto x : vet)
        cout << " " << x;
    cout << " ]\n";
}

void somar(vector<int> vet)
{
    if (vet.size() == 1)
        return;
    vector<int> aux;
    for (int i = 0; i < vet.size() - 1; i++)
        aux.push_back(vet[i] + vet[i + 1]);
    somar(aux);
    show(aux);
}

int main()
{
    int n;
    cin >> n;
    vector<int> vet;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vet.push_back(x);
    }

    somar(vet);
    show(vet);
}