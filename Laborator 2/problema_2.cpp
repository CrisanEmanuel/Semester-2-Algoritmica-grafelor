#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream f("graf.txt");
    int numar_varfuri, v1, v2, matrice[20][20] = {0};

    f >> numar_varfuri;
    while (!f.eof()) {
        f >> v1 >> v2;
        matrice[v1][v2] = 1;
    }

    for (int k = 1; k <= numar_varfuri; k++)
        for (int i = 1; i <= numar_varfuri; i++)
            for (int j = 1; j <= numar_varfuri; j++)
                if (matrice[i][j] == 0)
                    matrice[i][j] = (matrice[i][k] && matrice[k][j]);


    cout << "Matricea inchiderilor este:\n";
    for(int i = 1; i <= numar_varfuri; i++) {
        for (int j = 1; j <= numar_varfuri; j++)
            cout << matrice[i][j] << ' ';
        cout << endl;
    }
}
