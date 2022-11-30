#include <iostream>
using namespace std;

void hanoi(int num, char orig, char dest, char aux1, char aux2) {
    if (num == 1){
        cout << orig << " -> " << dest << endl;
    }
    else
    {
        hanoi(num - 1, orig, aux1, dest, aux2);
        cout << orig << " -> " << dest << endl;
        hanoi(num - 1, aux1, dest, orig, aux2);
    }
}

int main()
{
    int qte;
    cin >> qte;
    hanoi(qte, 'A', 'C', 'B', 'D');
    return 0;
}