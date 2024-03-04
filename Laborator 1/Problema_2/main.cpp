#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void dfs(int k, int n, int (*a)[10], int *v) {
    v[k]=1;
    for(int i = 1; i <= n; i++)
        if(a[k][i] == 1 && v[i] == 0)
            dfs(i, n, a, v);

}

int main(){
    ifstream f("date.txt");
    /// graf dat prin matrice de adiacenta
    int ma[10][10], n;
    f >> n;
    for (int i=1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f >> ma[i][j];

    /// a. sa se determine nodurile izolate dintr-un graf
    int aux, k = 0;
    cout << "Nodurile izolate sunt:";
    cout << endl;
    for (int i = 1; i <= n; i++) {
        aux = 0;
        for (int j = 1; j <= n; j++)
            if (ma[i][j] == 1) aux++;
        if (aux == 0) {
            cout << i << ' ';
            k = 1;
        }
    }
    if (k == 0) cout<<"Nu exista!";
    cout << endl;

    /// b. sa se determine daca graful este regular
    int grad, grad_all = 0, ok = 0 ;
    for (int i=1;i<=n;i++) {
        grad = 0;
        for (int j = 1; j <= n; j++)
            if (ma[i][j] == 1) grad++;
        if (grad_all == 0) grad_all = grad;
        if (grad != grad_all) {
            cout << "Graful nu este regular!" << endl;
            ok = 1;
            break;
        }
    }
    if (ok == 0) cout<<"Graful este regular!"<<endl;

    /// d. pentru un graf reprezentat cu o matrice de adiacenta sa se determine daca este conex
    int v[10]={0};
    dfs(1,n,ma,v);
    ok = 0;
    for(int i=1;i<=n;i++){
        if(v[i] == 0) {
            cout << "Graful nu este conex!" << endl;
            ok = 1;
            break;
        }
    }
    if (ok == 0) cout<<"Graful este conex!"<<endl;
    cout<<endl;

    /// c. pentru un graf reprezentat cu matricea de adiacenta sa se determine matricea distantelor
    int md[10][10]={0};
    int inf = INFINITY;

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            md[i][j] = ma[i][j];
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(md[i][j] == 0 && i != j)
                md[i][j] = inf;

    for(k = 1; k <= n; k ++)
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                if(i != j)
                    if(md[i][k] != inf && md[k][j] != inf && md[i][j] > md[i][k] + md[k][j])
                        md[i][j] = md[i][k] + md[k][j];
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
            if(md[i][j] == inf)
                cout << "inf ";
            else
                cout << " " << md[i][j] << "  ";
        cout << '\n';
    }

    f.close();
    return 0;
}

