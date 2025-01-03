#include <iostream>
using namespace std;

struct node
{
    int coefficient;
    int power;
    node *next;
};

node *createNode(int coef, int pow)
{
    node *newNode = new node();
    newNode->coefficient = coef;
    newNode->power = pow;
    newNode->next = nullptr;
    return newNode;
}

void addNode(node *&first, int coef, int pow)
{
    node *temp = first;
    node *newNode = createNode(coef, pow);

    if (!first)
    {
        first = newNode;
        return;
    }

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(node *first)
{
    node *temp = first;
    while (temp != nullptr)
    {
        cout << temp->coefficient << "x^" << temp->power;
        if (temp->next != nullptr)
            cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

void addToResult(node *&result, int coef, int pow)
{
    node *temp = result;
    node *prev = nullptr;

    while (temp != nullptr && temp->power > pow)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp != nullptr && temp->power == pow)
    {
        temp->coefficient += coef;
    }
    else
    {
        node *newNode = createNode(coef, pow);
        if (prev == nullptr)
        {
            newNode->next = result;
            result = newNode;
        }
        else
        {
            newNode->next = temp;
            prev->next = newNode;
        }
    }
}

node *polyMultiply(node *poly1, node *poly2)
{
    node *result = nullptr;
    node *ptr1 = poly1;

    while (ptr1 != nullptr)
    {
        node *ptr2 = poly2;
        while (ptr2 != nullptr)
        {
            int coef = ptr1->coefficient * ptr2->coefficient;
            int pow = ptr1->power + ptr2->power;
            addToResult(result, coef, pow);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    return result;
}

int main()
{
    node *poly1 = nullptr, *poly2 = nullptr;
    int coef, pow;
    char choice;

    cout << "Enter coefficient for first term of the first polynomial: ";
    cin >> coef;
    cout << "Enter power for first term of the first polynomial: ";
    cin >> pow;
    addNode(poly1, coef, pow);

    while (true)
    {
        cout << "Do you want to add another term to the first polynomial? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N')
            break;
        cout << "Enter coefficient: ";
        cin >> coef;
        cout << "Enter power: ";
        cin >> pow;
        addNode(poly1, coef, pow);
    }

    cout << "Enter coefficient for first term of the second polynomial: ";
    cin >> coef;
    cout << "Enter power for first term of the second polynomial: ";
    cin >> pow;
    addNode(poly2, coef, pow);

    while (true)
    {
        cout << "Do you want to add another term to the second polynomial? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N')
            break;
        cout << "Enter coefficient: ";
        cin >> coef;
        cout << "Enter power: ";
        cin >> pow;
        addNode(poly2, coef, pow);
    }


    cout << "\nFirst Polynomial: ";
    display(poly1);
    cout << "Second Polynomial: ";
    display(poly2);

    node *result = polyMultiply(poly1, poly2);
    cout << "Multiplied Polynomial: ";
    display(result);

    return 0;
}
