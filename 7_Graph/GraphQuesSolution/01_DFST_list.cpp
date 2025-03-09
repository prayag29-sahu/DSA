#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

struct graph
{
    int v;
    node **adjlist;

    graph(int visited)
    {
        v = visited;
        adjlist = new node *[v];
        for (int i = 0; i < v; i++)
        {
            adjlist[i] = nullptr;
        }
    }
    void addedge(int u, int v)
    {
        node *newNode = new node{v, adjlist[u]};
        adjlist[u] = newNode;
        // cout << newNode->data << " ";
        newNode = new node{u, adjlist[v]};
        adjlist[v] = newNode;
        // cout << newNode->data << " ";
    }
    void DFST(int start, bool visited[])
    {
        visited[start] = true;
        cout << start << " ";
        node *temp = adjlist[start];
        while (temp)
        {
            if (!visited[temp->data])
            {
                DFST(temp->data, visited);
            }
            temp = temp->next;
        }
    }
    void DFS(int start)
    {
        bool visited[v] = {false};
        DFST(start, visited);
    }
};

int main()
{
    graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 3);
    cout << "DFS Traversal: ";
    g.DFS(0);
}

// o/p (DFS Traversal: 0 2 3 1  )