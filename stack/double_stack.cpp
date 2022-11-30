#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

void emborcar(stack<int> &gaveta, stack<int> &prateleira)
{
    while (!gaveta.empty())
    {
        prateleira.push(gaveta.top());
        gaveta.pop();
    }
}

int main()
{
    stack<int> gaveta;
    stack<int> prateleira;

    int q{0};
    cin >> q;
    cin.ignore();

    while (q != 0)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if (cmd == "exit")
        {
            break;
        }
        else if (cmd == "1")
        {
            int num{0};
            ss >> num;
            gaveta.push(num);
            q--;
        }
        else if (cmd == "2")
        {
            if (prateleira.size() != 0)
            {
                prateleira.pop();
            }
            else
            {
                emborcar(gaveta, prateleira);
                prateleira.pop();
            }
            q--;
        }
        else if (cmd == "3")
        {
            if (prateleira.empty())
            {
                emborcar(gaveta, prateleira);
                cout << "Quem esta no topo: " << prateleira.top() << '\n';
            }
            else
            {
                cout << "Quem esta no topo: " << prateleira.top() << '\n';
            }
            q--;
        }
        else
        {
            cout << "fail: comando invalido" << '\n';
        }
    }
    return 0;
}