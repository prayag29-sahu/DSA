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

    int minKey(int mw[], bool mstv[]) {
        int min = INT_MAX, min_index;

        for (int v = 0; v < V; v++) {
            if (!mstv[v] && mw[v] < min) {
                min = mw[v];
                min_index = v;
            }
        }
        return min_index;
    }

    void primMST() {
        int start[V]; 
        int mw[V];  
        bool mstv[V]; 
        for (int i = 0; i < V; i++) {
            mw[i] = INT_MAX;
            mstv[i] = false;
        }

        mw[0] = 0;
        start[0] = -1;
        for (int i = 0; i < V - 1; i++) {
            int u = minKey(mw, mstv);
            mstv[u] = true;

            Node* temp = adjList[u];
            while (temp) {
                int v = temp->data;
                if (!mstv[v] && temp->weight < mw[v]) {
                    start[v] = u;
                    mw[v] = temp->weight;
                }
                temp = temp->next;
            }
        }
        int sum = 0;
        for (int i = 0; i < V;i++)
        {
            sum = sum + mw[i];
        }
            cout << "Edge \tWeight\n";
        for (int i = 1; i < V; i++) {
            cout << start[i] << " - " << i << " \t" << mw[i] << endl;
        }
        cout << "Total Weight = " << sum;
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.primMST();
    return 0;
}