#include <iostream>
#include <climits>
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
        Node *newNode = new Node{v, adjList[u]};
        adjList[u] = newNode;
        newNode = new Node{u, adjList[v]};
        adjList[v] = newNode;
    }

    void shortestPath(int src)
    {
        int dist[V];
        bool visited[V] = {false};

        for (int i = 0; i < V; i++)
        {
            dist[i] = INT_MAX;
        }
        dist[src] = 0; 

        queue<int> q;
        q.push(src);
        // cout << src << endl; // 0
        visited[src] = true;

        while (!q.empty())
        {
            int ttemp = q.front();
            q.pop();
            // cout << "ttemp = " << ttemp << endl; //0
            Node *temp = adjList[ttemp];
            // cout << temp->data << endl; // 2
            while (temp)
            {
                int neighbor = temp->data;
                // cout << neighbor << " "; // 2,1
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    dist[neighbor] = dist[ttemp] + 1;
                    q.push(neighbor);
                }
                temp = temp->next;
            }
        }

        for (int i = 0; i < V; i++)
        {
            cout << "Shortest path from " << src << " to " << i << " is " << dist[i] << endl;
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    cout << "Shortest Path from node 0:" << endl;
    g.shortestPath(0);
    return 0;
}
