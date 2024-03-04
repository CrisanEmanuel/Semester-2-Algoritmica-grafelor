#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream f("in.txt");
    /// File (lista de muchii) -> Matricea de adiacenta 1
    int n,ma1[10][10]={0},p,q;
    f>>n;
    for (int i=1;i<=n;i++){
        f>>q>>p;
        ma1[q][p] = 1;
        ma1[p][q] = 1;
    }

    cout<<"File -> Matricea de adiacenta:";
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<ma1[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;

    /// Matricea de adiacenta 1 -> Lista de adiacenta 1
    int la1[10][10]={0};
    int k;
    for(int i=1;i<=n;i++){
        k=1;
        for (int j=1;j<=n;j++)
            if(ma1[i][j]==1) {
                la1[i][k]=j;
                k++;
            }
    }

    cout<<"Matricea de adiacenta -> Lista de adiacenta:";
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<": ";
        for(int j=1;j<=n;j++)
            if(la1[i][j]!=0)
                cout<<la1[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;

    /// Lista de adiacenta 1 -> Matricea de incidenta
    int mi[10][10]={0};
    k=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n-1;j++)
            if(la1[i][j]!=0 && i<la1[i][j]){
                k++;
                mi[i][k]=1;
                mi[la1[i][j]][k]=1;
            }
    cout<<"Lista de adiacenta -> Matricea de incidenta:";
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++)
            cout<<mi[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;

    /// Matricea de incidenta -> Lista de adiacenta 2
    int la2[10][10]={0};
    int aux1,aux2;
    k=1;

    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++)
            if(mi[i][j]==1){
                aux1=aux2;
                aux2=i;
            }
        la2[aux1][k] = aux2;
        la2[aux2][k] = aux1;
        k++;

    }
    cout<<"Matricea de incidenta -> Lista de adiacenta:";
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<": ";
        for(int j=1;j<=n;j++)
            if(la2[i][j]!=0)
                cout<<la2[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;

    /// Lista de adiacenta 2 -> Matrice de adiacenta 2
    int ma2[10][10]={0};

    cout<<"Lista de adiacenta -> Matrice de adiacenta:";
    cout<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(la2[i][j]!=0){
                ma2[i][la2[i][j]]=1;
            }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<ma2[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;

    /// Matricea de adiacenta 2 -> Lista de adiacenta 3
    int la3[10][10]={0};
    for(int i=1;i<=n;i++){
        k=1;
        for (int j=1;j<=n;j++)
            if(ma2[i][j]==1) {
                la3[i][k]=j;
                k++;
            }
    }

    cout<<"Matricea de adiacenta -> Lista de adiacenta:";
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<": ";
        for(int j=1;j<=n;j++)
            if(la3[i][j]!=0)
                cout<<la3[i][j]<<' ';
        cout<<endl;
    }
    f.close();
    return 0;
}