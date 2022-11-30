#include <iostream>

using namespace std;

int main() {
    int qtdP = 0;

    cin >> qtdP;

    float valor[qtdP];
    float chute [qtdP];
    string segChance[qtdP];

    int first = 0;
    int sec = 0;

    for (int i = 0; i < qtdP; i++){
        cin.ignore() >> valor[i];
    }

    for (int i = 0; i < qtdP; i++){
        cin.ignore() >> chute[i];
    }

    for (int i = 0; i < qtdP; i++){
        cin.ignore() >> segChance[i];
    }

    for (int i = 0; i < qtdP; i++) {
        
        if (chute[i] == valor[i] && segChance[i] == "m" || segChance[i] == "M"){
            i++;
        } else if (chute[i] > valor[i] && segChance[i] == "m") {
            sec++;
        }
    }

    if (first == sec){
        cout << "empate" << endl;
    } else if (first > sec){
        cout << "primeiro" << endl;
    } else if (first < sec){
        cout << "segundo" << endl;
    }
}