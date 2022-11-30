#include <iostream>
#include <sstream> //cabeçalho que contém o tipo de dado stringstream
#include <vector>  //cabeçalho que contém a estrutura de dados vector
#include <string>

using namespace std;

void mostrar(vector<int> vet) {
    cout << "[ ";
    for (auto linha : vet)
        cout << linha << " ";
    cout << " ]\n";
}

void rmostra(vector<int> vet) {
    cout << "[ ";
    for(int i = vet.size() - 1; i >= 0; i--) {
        cout << vet[i] << " ";
    }
    cout << " ]\n";
}

int sum(vector<int> vet) {
    return (vet.size() == 1) ? vet[0] : vet[0] + sum(vector<int>(vet.begin() + 1, vet.end()));
}

int mult(vector<int> vet, int size) {
    return (size == 0) ? 1 : vet[size - 1] * mult(vet, size - 1);
}

int menor_valor(vector<int> vet, int size, int min) {
    if (size == 0)
        return min;

    if (vet[size - 1] < min)
        min = vet[size - 1];

    return menor_valor(vet, size - 1, min);
}

void inverte(vector<int>& vet, int i, int j) {
    int aux;
    if (i < j) {
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
        inverte(vet, i + 1, j - 1);
    }
}

int main(){

    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> vet;
    int value;
    while (ss >> value)
        vet.push_back(value);
    cout << "vet : ";
    mostrar(vet);
    cout << "rvet : ";
    rmostra(vet);
    cout << "sum : " << sum(vet) << '\n';
    cout << "mult: " << mult(vet, vet.size()) << '\n';
    cout << "min: " << menor_valor(vet, vet.size(), value) << '\n';
    cout << "inv : ";
    inverte(vet, 0, (int)vet.size() - 1);
    mostrar(vet);

}