#include <iostream>
#include <fstream>

int INF = 100000;
using namespace std;

int main(int argc, char* argv[]) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    int nrVarfuri, nrArce, nodSursa;
    fin >> nrVarfuri >> nrArce >> nodSursa;

    int matrice[101][101]={0}, drum[101], ver[101];

    int nod1, nod2, cost;
    for (int i = 0; i < nrArce; i++) {
        fin >> nod1 >> nod2 >> cost;
        matrice[nod1][nod2] = cost;
    }

    for(int i = 0; i < nrVarfuri; i ++)
        for(int j = 1; j <= nrVarfuri; j ++)
            if(matrice[i][j] == 0)
                matrice[i][j] = INF;

    for(int i = 0; i < nrVarfuri; i ++)
        drum[i] = matrice[nodSursa][i];

    ver[nodSursa] = 1;
    drum[nodSursa] = 0;

    for(int i = 0; i < nrVarfuri - 1; i ++){
        int k = 1;
        for(int j = 0; j < nrVarfuri; j ++)
            if(ver[j] == 0 && drum[j] < drum[k])
                k = j;

        if(k == 1) break;

        ver[k] = 1;
        for(int j = 0; j < nrVarfuri; j ++)
            if(ver[j] == 0 && drum[j] > drum[k] + matrice[k][j])
                drum[j] = drum[k] + matrice[k][j];
    }

    for(int i = 0; i < nrVarfuri; i ++)
        if(drum[i] == INF)
            fout << "INF" << " ";
        else
            fout << drum[i] << " ";


    fin.close();
    fout.close();
    return 0;
}
