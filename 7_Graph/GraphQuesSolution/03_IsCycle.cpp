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

    bool detectCycleUtil(int v, bool visited[], int result) {
        visited[v] = true;

        Node* temp = adjList[v];
        while (temp) {
            if (!visited[temp->data]) {
                if (detectCycleUtil(temp->data, visited, v))
                    return true;
            } else if (temp->data != result)
                return true;

            temp = temp->next;
        }
        return false;
    }

    bool detectCycle() {
        bool visited[V] = {false};
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (detectCycleUtil(i, visited, -1))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1); // Cycle

    cout << "Graph contains cycle: " << (g.detectCycle() ? "Yes" : "No") << endl;
    return 0;
}