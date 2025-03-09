#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Graph
{
    int V;          
    Node **adjList; 

    Graph(int vertices)
    {
        V = vertices;
        adjList = new Node *[V];

        for (int i = 0; i < V; i++)
        {
            adjList[i] = nullptr;
        }
    }

    void addEdge(int u, int v)
    {
        Node *newNodeU = new Node{v, adjList[u]};
        adjList[u] = newNodeU;

        Node *newNodeV = new Node{u, adjList[v]};
        adjList[v] = newNodeV;
    }

    void BFS(int start)
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int ttemp = q.front();
            q.pop();

            cout << ttemp << " ";

            Node *temp = adjList[ttemp];
            while (temp != nullptr)
            {
                if (!visited[temp->data])
                {
                    visited[temp->data] = true;
                    q.push(temp->data);
                }
                temp = temp->next;
            }
        }

        delete[] visited;
    }
};

int main()
{

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    cout << "BFS traversal : ";
    g.BFS(0); 

    return 0;
}
