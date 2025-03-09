#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Graph {
    int V;
    Node** adjList;

    Graph(int vertices) {
        V = vertices;
        adjList = new Node*[V];
        for (int i = 0; i < V; i++) {
            adjList[i] = nullptr;
        }
    }

    void addEdge(int u, int v) {
        Node* newNode = new Node{v, adjList[u]};
        adjList[u] = newNode;
        // cout << newNode->data << " ";
        newNode = new Node{u, adjList[v]};
        adjList[v] = newNode;
        // cout << newNode->data << " ";
    }

    bool isBipartiteUtil(int v, int color[], int c) {
        color[v] = c;

        Node* temp = adjList[v];
        while (temp) {
            if (color[temp->data] == -1) {
                if (!isBipartiteUtil(temp->data, color, 1 - c))
                    return false;
            } else if (color[temp->data] == color[v])
                return false;

            temp = temp->next;
        }
        return true;
    }

    bool isBipartite() {
        int color[V];
        for (int i = 0; i < V; i++)
            color[i] = -1;

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!isBipartiteUtil(i, color, 0))
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    // g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    cout << "Graph is bipartite: " << (g.isBipartite() ? "Yes" : "No") << endl;
    return 0;
}