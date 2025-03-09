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
        // cout << adjList[u]->data << " "; // (2 0 0 1 3 1 Topological Sorting: 5 4 2 3 1 0 )
        
    }

    void topologicalSortUtil(int v, bool visited[], int result[], int &index) {
        visited[v] = true;
        // cout << v << " "; // [Topological Sorting: 0 1 2 3 4 5     5 4 2 3 1 0 ]
        Node *temp = adjList[v];
        // cout << adjList[v]->data << endl;
        while (temp)
        {
            // cout << temp->data << " "; // [Topological Sorting: 3 1 1 0 0 2    5 4 2 3 1 0 ]
            if (!visited[temp->data]) {
                topologicalSortUtil(temp->data, visited, result, index);
            }
            temp = temp->next;
        }
        result[index--] = v;
    }

    void topologicalSort() {
        bool visited[V] = {false};
        int result[V];
        int index = V - 1;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, result, index);
            }
        }

        for (int i = 0; i < V; i++) {
            cout << result[i] << " ";
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Topological Sorting: ";
    g.topologicalSort();
    return 0;
}