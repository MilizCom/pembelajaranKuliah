#include <iostream>
using namespace std;

const int MAX = 5;

struct Numbers
{
    int num;
    Numbers *next;
};

Numbers *new_node, *front = NULL, *back = NULL, *current = NULL;

int count()
{
    int count = 0;
    current = front;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

bool isEmpty()
{
    if (front == NULL)
        return true;
    return false;
}

bool isFull()
{
    if (count() >= MAX)
        return true;
    return false;
}

void enqueue(int num)
{
    if (isFull())
    {
        cout << "Queue is full\n";
    }
    else
    {
        new_node = new Numbers();
        new_node->num = num;
        if (!isEmpty())
        {
            back->next = new_node;
            back = new_node;
        }
        else
        {
            new_node->next = NULL;
            front = back = new_node;
        }
    }
}

void dequeue()
{
    if (!isEmpty())
    {
        current = front;
        front = front->next;
        cout << "Dequeue element is " << current->num << endl;
        delete current;
    }
    else
    {
        cout << "Queue is empty\n";
    }
}

void display()
{
    current = front;
    cout << "Elements in Queue: ";
    while (current != NULL)
    {
        cout << current->num << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    // Your test code can go here
    enqueue(2);
    enqueue(6);
    enqueue(5);
    dequeue();
    display();
    return 0;
}
