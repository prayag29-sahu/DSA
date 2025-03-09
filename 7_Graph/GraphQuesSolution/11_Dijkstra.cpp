#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    int weight;
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

    void addEdge(int u, int v, int w) {
        Node* newNode = new Node{v, w, adjList[u]};
        adjList[u] = newNode;
        newNode = new Node{u, w, adjList[v]};
        adjList[v] = newNode;
    }

    int minDistance(int dist[], bool sptSet[]) {
        int min = INT_MAX, min_index;

        for (int i = 0; i < V; i++) {
            if (!sptSet[i] && dist[i] < min) {
                min = dist[i];
                min_index = i;
            }
        }
        return min_index;
    }

    void dijkstra(int src) {
        int dist[V];
        bool sptSet[V];

        for (int i = 0; i < V; i++) {
            dist[i] = INT_MAX;
            sptSet[i] = false;
        }

        dist[src] = 0;

        for (int i = 0; i < V - 1; i++) {
            int u = minDistance(dist, sptSet);
            sptSet[u] = true;

            Node* temp = adjList[u];
            while (temp) {
                int v = temp->data;
                if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + temp->weight < dist[v]) {
                    dist[v] = dist[u] + temp->weight;
                }
                temp = temp->next;
            }
        }
        int sum = 0;
        for (int i = 0; i < V; i++)
        {
            sum = sum + dist[i];
        }
        cout << "Vertex \tDistance from Source\n";
        for (int i = 0; i < V; i++) {
            cout << i << " \t\t" << dist[i] << endl;
        }
        cout << "Minimum Distance = " << sum;
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 4, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 2, 6);
    g.addEdge(4, 2, 9);
    g.addEdge(4, 3, 2);

    g.dijkstra(0);
    return 0;
}