#include <iostream>
#include <string>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, int n)
{
    if(str[0] == '\0'){
        return 0;
    }

    return (n == str[0]) + contaCaracteres(&(str[1]), n);
}

int main()
{
    string str = {};
    getline(cin, str);
    char i;
    cin >> i;

    int conta = contaCaracteres(str, i);

    cout << conta << endl;
    
}