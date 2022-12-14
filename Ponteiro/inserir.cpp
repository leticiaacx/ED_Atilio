#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct aluno {
    int matricula;
    char nome[50];
    float media;
};

aluno le_aluno() {
    aluno a;
    cin >> a.matricula;
    cin.ignore(); 
    cin.get(a.nome, 50);
    cin >> a.media;
    return a;
}

aluno *insere_aluno(aluno *v, int *n, aluno novo) {
    aluno *novoA = v;
    v = new (nothrow) aluno[*n + 1];

  if (v == nullptr) {
    cout << "Error! Nao ha como alocar memoria";
    return 0;
  }

  for (int i = 0; i < *n; i++)
    v[i] = novoA[i];

  v[*n] = novo;
  (*n)++;

  delete[] novoA;
  return v;
}

aluno *remove_aluno(aluno *v, int *n, int matricula) {
    for (int i = 0; i < *n; i++){
        if (v[i].matricula == matricula){
            int tam = *n - 1;

            v[i] = v[tam];

            aluno *temp = v;
            v = new (nothrow) aluno[tam];

            if (v == nullptr){
                cout << "Error! Nao ha como realocar memoria";
                return 0;
            }

            for (int j = 0; j < tam; j++){
                v[j] = temp[j];
            }

            (*n)--;
            delete[] temp;
            break;
        }
    }

    return v;
}

int main() {
    int num_oper = 0, i, n = 0;
    cin >> num_oper;
    aluno *v = 0;

    for (i = 0; i < num_oper; i++) {
        cin.ignore(); // lê e descarta o caractere '\n' do buffer
        char oper;
        cin >> oper;
        if (oper == 'i') {
            aluno a = le_aluno();
            v = insere_aluno(v, &n, a);
        } else {
            int mat;
            cin >> mat;
            v = remove_aluno(v, &n, mat);
        }
    }

    for (i = 0; i < n; i++){
        cout << v[i].matricula << "\n"
            << v[i].nome << "\n"
            << std::fixed << setprecision(1) << v[i].media << "\n";
    }

    delete[] v;

    return 0;
}