#include <iostream>
#include <vector>
#include <string>

using namespace std;

void mostrar(vector<vector<string>>& mapa) {
    for (int i = 0; i < mapa.size(); i++) {
        for (int j = 0; j < mapa[0].size(); j++)
            cout << mapa[i][j];
        cout << "\n";
    }
}

void queimar(vector<vector<string>>& mapa, int pos_lin, int pos_col)
{
    int num_lin = mapa.size();
    int num_col = mapa[0].size();
    if (pos_lin >= num_lin || pos_col >= num_col || pos_lin < 0 || pos_col < 0)
        return;

    if (mapa[pos_lin][pos_col] != "#")
        return;

    mapa[pos_lin][pos_col] = 'o';
    // mostrar(mapa);

    queimar(mapa, pos_lin, pos_col - 1);
    queimar(mapa, pos_lin - 1, pos_col);
    queimar(mapa, pos_lin, pos_col + 1);
    queimar(mapa, pos_lin + 1, pos_col);
}

int main(){

    int nl, nc, lfire, cfire;
    cin >> nl >> nc >> lfire >> cfire;
    vector<vector<string>> mapa(nl, vector<string>(nc, "*"));
    mostrar(mapa);

    for (int i = 0; i < nl; i++) {
        string s;
        getline(cin >> ws, s);
        for (int j = 0; j < nc; j++) {
            mapa[i][j] = s[j];	
        }
    }
    queimar(mapa, lfire, cfire);
    mostrar(mapa);
}