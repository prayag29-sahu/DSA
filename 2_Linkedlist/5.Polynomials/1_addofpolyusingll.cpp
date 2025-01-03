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

node *polyAdd(node *poly1, node *poly2)
{
    node *result = nullptr;
    node *ptr1 = poly1, *ptr2 = poly2;

    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if (ptr1->power == ptr2->power)
        {
            addNode(result, ptr1->coefficient + ptr2->coefficient, ptr1->power);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->power > ptr2->power)
        {
            addNode(result, ptr1->coefficient, ptr1->power);
            ptr1 = ptr1->next;
        }
        else
        {
            addNode(result, ptr2->coefficient, ptr2->power);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != nullptr)
    {
        addNode(result, ptr1->coefficient, ptr1->power);
        ptr1 = ptr1->next;
    }

    while (ptr2 != nullptr)
    {
        addNode(result, ptr2->coefficient, ptr2->power);
        ptr2 = ptr2->next;
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


    node *result = polyAdd(poly1, poly2);
    cout << "Added Polynomial: ";
    display(result);

    return 0;
}
