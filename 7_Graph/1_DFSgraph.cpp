#include <iostream>
using namespace std;

const int MAX = 100;

void DFSRec(int adj[MAX][MAX], bool visited[MAX], int s, int V)
{
    visited[s] = true;

    for (int i = 0; i < V; i++)
    {
        if (adj[s][i] == 1 && !visited[i])
        {
            cout  << i << " ";
            DFSRec(adj, visited, i, V);
        }
    }
}

void DFS(int adj[MAX][MAX], int s, int V)
{
    bool visited[MAX] = {false};
    DFSRec(adj, visited, s, V);
}

void addEdge(int adj[MAX][MAX], int s, int t)
{
    adj[s][t] = 1;
    adj[t][s] = 1;
}

int main()
{
    int V = 5;
    int adj[MAX][MAX] = {0};

    int edges[][2] = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};
    int numEdges = sizeof(edges) / sizeof(edges[0]);
    for (int i = 0; i < numEdges; i++)
    {
        addEdge(adj, edges[i][0], edges[i][1]);
    }

    int s = 1;
    cout << "Edges in DFS traversal from source: " << s << endl;
    DFS(adj, s, V);

    return 0;
}
