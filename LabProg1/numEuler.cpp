#include <iostream>
#include <iomanip>
using namespace std;

double fatorial(int n){// função que faz o fatorial e retorna o resultado q ta salvo em a
    double a = 1;
    for (double i = 1; i <= n; i++){
        a *= i;
    }
    return a;
}

double euler (int n){ // função que euler, que chama a função fatorial 
    double e = 1;
    for (int i = 1; i <= n; i++) {
        e += 1 / fatorial(i);
    }
    return e;
}


int main(){
    int c = 0;
    cin >> c;
    cout << setprecision(6) << fixed << euler(c) << endl;
}
