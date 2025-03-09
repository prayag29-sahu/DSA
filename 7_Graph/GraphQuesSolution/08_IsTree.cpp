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
        newNode = new Node{u, adjList[v]};
        adjList[v] = newNode;
    }

    bool DFSUtil(int v, bool visited[], int parent) {
        visited[v] = true;

        Node* temp = adjList[v];
        while (temp) {
            if (!visited[temp->data]) {
                if (!DFSUtil(temp->data, visited, v)) {
                    return false;
                }
            } else if (temp->data != parent) {
                return false;  
            }
            temp = temp->next;
        }
        return true;
    }

    bool isTree() {
        bool visited[V] = {false};

        if (!DFSUtil(0, visited, -1)) {
            return false;
        }

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    if (g.isTree()) {
        cout << "Graph is a tree." << endl;
    } else {
        cout << "Graph is not a tree." << endl;
    }
    return 0;
}