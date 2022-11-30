#include <iostream>
using namespace std;

bool ordem(int vet[], int tam){
    if(vet[0] == 0){
        return true;
    }

    for(int i = 1; i < tam - 1; i++){
        if(vet[i] >= vet[i + 1]){
            return false; 
        } 
    }

    return true;

}
  

int main(){
    int n = 0;
    int vetor[n];

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> vetor[i];
    }

    if(ordem(vetor, n)){
        cout << "ok" << endl;
    } else {
        cout << "precisa de ajuste" << endl;
    }

}