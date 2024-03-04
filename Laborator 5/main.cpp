//Aceasta este o implementare simplă a algoritmului Edmonds-Karp pentru a
//rezolva problema fluxului maxim într-un graf orientat fără circuite. Acesta
//utilizează o matrice de adiacență pentru a reprezenta grafurile și BFS
//(parcurgerea în lățime)pentru a căuta drumuri de la sursă la destinație

#include <iostream>
#include <queue>
#include <climits>
#include <fstream>

using namespace std;

// Numărul maxim de vârfuri în graf
#define V 100

// Funcția pentru a verifica dacă există un drum de la s la t folosind BFS
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // Un vector pentru a verifica dacă un vârf a fost vizitat în timpul BFS
    bool visited[V];
    for (bool & i : visited) {
        i = false;
    }

    // Coada pentru BFS
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // BFS
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // Dacă am ajuns la vârful destinație în timpul BFS, înseamnă că există un drum
    return visited[t];
}

// Funcția care implementează algoritmul Edmonds-Karp pentru rezolvarea problemei fluxului maxim
int edmondsKarp(int graph[V][V], int s, int t)
{
    int u, v;

    // Crearea unei copii a grafului inițial pentru a stoca capacitățile restante
    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    // Vectorul în care se va stoca lanțul de vârfuri
    int parent[V];

    int maxFlow = 0; // Fluxul maxim

    // Cât timp există un drum de la s la t, se calculează fluxul maxim posibil pe acel drum și se actualizează rGraph[]
    while (bfs(rGraph, s, t, parent)) {
        int pathFlow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        // Actualizarea capacităților arcelor și arcelor inverse de-a lungul drumului
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        // Adăugarea fluxului maxim al drumului curent la fluxul total
        maxFlow += pathFlow;
    }

    // Returnarea fluxului maxim
    return maxFlow;
}

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    ofstream out(argv[2]);

    int nrVarfuri, nrMuchii, x, y, flux;
    in >> nrVarfuri >> nrMuchii;
    int graf[V][V];

    for (int i = 0; i < nrVarfuri; i++)
        for (int j = 0; j < nrVarfuri; j++)
            graf[i][j] = 0;

    while(!in.eof()) {
        in >> x >> y >> flux;
        graf[x][y] = flux;
    }

    int s = 0; // Vârful sursă
    int t = nrVarfuri - 1; // Vârful destinație

    out << "Fluxul maxim este: " << edmondsKarp(graf, s, t) << endl;

    return 0;
}

