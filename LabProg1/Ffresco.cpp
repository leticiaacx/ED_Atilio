#include <iostream>
#include <string>
using namespace std;

bool comparar(string frase, int n){
    if(frase[n - 1] == frase[n + 1]){
        return true;
    }
}

int main(){
    string entrada;
    getline(cin, entrada);

    for(int i = 0; i < entrada.length(); i++){
        if(entrada[i] == ' '){
            if (comparar(entrada, i)){
                i+=1;
                continue;  
            }
            
        } else {
            cout << entrada[i];
        }
    }
}