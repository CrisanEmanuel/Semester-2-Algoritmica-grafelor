#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
    ifstream in (argv[1]);
    ofstream out (argv[2]);

    int i, j, nrV, e, min, x;

    in>>nrV;

    // numarul de muchii, e = numar varfuri - 1
    e = nrV-1;
    int edge[e][2], deg[nrV+1];

    for (i = 0; i < nrV+1; i++) {
        deg[i] = 0;
    }

    vector<int> vec;
    int vf;
    while(!in.eof()){
        in >> vf;
        vec.push_back(vf);
    }

    // salvam muchiile
    for(i = 1; i <= e; i++)
    {
        if (vec[i] != -1) {
            edge[i][0] = vec[i];
            edge[i][1] = i;

            deg[edge[i][0]]++;
            deg[edge[i][1]]++;
        }
        else {
            edge[i][0] = -1;
            edge[i][1] = -1;
        }
    }

    out << nrV - 1 << endl;

    out<<"{ ";
    for(i = 1; i < nrV; i++)
    {
        min = 10000;

        // luam vf cu cea mai mica valoare
        for(j = 0; j < e; j++)
        {
            if(deg[edge[j][0]] == 1 && edge[j][0] != -1)
            {
                if(min > edge[j][0])
                {
                    min = edge[j][0];
                    x = j;
                }
            }
            if(deg[edge[j][1]] == 1 && edge[j][1] != -1)
            {
                if(min > edge[j][1])
                {
                    min = edge[j][1];
                    x = j;
                }
            }
        }

        // sterge varful selectat reducand gradul la 0
        deg[edge[x][0]]--;

        // reducem gradul varfului dupa ce am eliminat muchia
        deg[edge[x][1]]--;

        // afisam varful de la care s-a sters o frunza
        if(deg[edge[x][0]] == 0)
            out<<edge[x][1]<<" ";
        else
            out<<edge[x][0]<<" ";
    }
    out<<"}";
    return 0;
}
