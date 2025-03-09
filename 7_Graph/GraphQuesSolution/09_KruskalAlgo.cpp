#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

struct Edge
{
    int u, v, w;
    Edge *next;
};

Edge *createEdge(int u, int v, int w)
{
    Edge *newEdge = new Edge;
    newEdge->u = u;
    newEdge->v = v;
    newEdge->w = w;
    newEdge->next = nullptr;
    return newEdge;
}

void insertEdge(Edge **head, int u, int v, int w)
{
    Edge *newEdge = createEdge(u, v, w);
    if (*head == nullptr || (*head)->w >= newEdge->w)
    {
        newEdge->next = *head;
        *head = newEdge;
    }
    else
    {
        Edge *temp = *head;
        while (temp->next != nullptr && temp->next->w < newEdge->w)
        {
            temp = temp->next;
        }
        newEdge->next = temp->next;
        temp->next = newEdge;
    }
}

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data= data;
    newNode->next = nullptr;
    return newNode;
}

void addEdge(Node *adjList[], int u, int v)
{
    Node *newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

bool dfsCycleCheck(Node *adjList[], bool visited[], int v, int parent)
{
    visited[v] = true;
    Node *temp = adjList[v];

    while (temp != nullptr)
    {
        if (!visited[temp->data])
        {
            if (dfsCycleCheck(adjList, visited, temp->data, v))
            {
                return true;
            }
        }
        else if (temp->data != parent)
        {
            return true; 
        }
        temp = temp->next;
    }

    return false;
}

bool isCycle(Node *adjList[], int V, int u, int v)
{
    bool visited[V] = {false};

    addEdge(adjList, u, v);

    bool hasCycle = dfsCycleCheck(adjList, visited, u, -1);

    if (hasCycle)
    {

        Node **temp = &adjList[u];
        while (*temp && (*temp)->data != v)
            temp = &((*temp)->next);
        if (*temp)
            *temp = (*temp)->next;

        temp = &adjList[v];
        while (*temp && (*temp)->data != u)
            temp = &((*temp)->next);
        if (*temp)
            *temp = (*temp)->next;
    }

    return hasCycle;
}

int kruskal(int V, Edge *edgeList)
{
    Node *adjList[V]; 
    for (int i = 0; i < V; i++)
    {
        adjList[i] = nullptr;
    }

    int minCost = 0;
    int edgeCount = 0;
    Edge *temp = edgeList;

    while (temp != nullptr && edgeCount < V - 1)
    {
        int u = temp->u;
        int v = temp->v;
        int w = temp->w;

        if (!isCycle(adjList, V, u, v))
        {
            cout << "Edge (" << u << ", " << v << ") with weight " << w << " added to MST.\n";
            minCost += w;
            edgeCount++;
        }

        temp = temp->next;
    }

    return minCost;
}

int main()
{
    int V = 6; 

    Edge *edgeList = nullptr;

    insertEdge(&edgeList, 0, 1, 4);
    insertEdge(&edgeList, 0, 2, 4);
    insertEdge(&edgeList, 1, 2, 2);
    insertEdge(&edgeList, 1, 3, 6);
    insertEdge(&edgeList, 2, 3, 8);
    insertEdge(&edgeList, 2, 4, 9);
    insertEdge(&edgeList, 3, 4, 7);
    insertEdge(&edgeList, 3, 5, 5);
    insertEdge(&edgeList, 4, 5, 3);

    cout << "Minimum cost of MST: " << kruskal(V, edgeList) << endl;

    return 0;
}
