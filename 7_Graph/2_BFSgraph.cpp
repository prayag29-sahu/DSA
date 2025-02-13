#include <iostream>
using namespace std;

const int MAX = 100; 

void bfs(int adj[MAX][MAX], int s, int V)
{

    int queue[MAX], front = 0, rear = 0;

    bool visited[MAX] = {false};

    visited[s] = true;
    queue[rear++] = s;


    while (front < rear)
    {

        int curr = queue[front++];
        cout << curr << " ";

        for (int i = 0; i < V; i++)
        {
            if (adj[curr][i] == 1 && !visited[i])
            {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

void addEdge(int adj[MAX][MAX], int u, int v)
{
    adj[u][v] = 1;
    adj[v][u] = 1; 
}

int main()
{

    int V = 5;


    int adj[MAX][MAX] = {0};

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    cout << "BFS starting from 0: \n";
    bfs(adj, 0, V);

    return 0;
}
