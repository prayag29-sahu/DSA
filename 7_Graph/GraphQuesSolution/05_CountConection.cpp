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
    void DFST(int V, bool visited[])
    {
        visited[V] = true;
        node *temp = adjlist[V];
        while (temp)
        {
            if (!visited[temp->data])
            {
                DFST(temp->data, visited);
            }
            temp = temp->next;
        }
    }

    int countConnectedComponents()
    {
        bool visited[v] = {false};
        int count = 0;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                DFST(i, visited);
                count++;
            }
        }
        return count;
    }
};

int main()
{
    graph g(5);
    g.addedge(0, 1);
    g.addedge(1, 2);
    g.addedge(3, 4);

    cout << "Number of connected components: " << g.countConnectedComponents() << endl;
    return 0;
}

// o/p (Number of connected components: 2)