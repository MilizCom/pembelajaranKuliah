#include <iostream>

using namespace std;

const int MAX = 10;

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL, *current, *new_node;

// Menghitung banyak data
int count() {
    int item_count = 0;
    if (top == NULL) return item_count;
    else {
        current = top;
        while (current != NULL) {
            item_count++;
            current = current->next;
        }
    }
    return item_count;
}

bool isEmpty() {
    if (top == NULL) return true;
    return false;
}

// Mengecek apakah tumpukan sudah penuh
bool isFull() {
    if (count() == MAX) return true;
    return false;
}

// Melihat data berdasarkan urutan
void peek(int order) {
    int item = 0;
    if (isEmpty()) cout << "Stack is empty!";
    else {
        current = top;
        while (current != NULL) {
            item++;
            if (item == order) {
                cout << "Data at order " << order << " is " << current->data;
                break;
            }
            current = current->next;
        }
    }
}

void destroy() {
    // Implementasi penghapusan tumpukan (stack destruction)
}

void push(int val) {
    if (isFull()) cout << "Stack is overflow!";
    else {
        struct Node* newnode = new Node();
        newnode->data = val;
        newnode->next = top;
        top = newnode;
    }
}

void pop() {
    if (isEmpty()) cout << "Stack Underflow" << endl;
    else {
        cout << "The popped element is " << top->data << endl;
        top = top->next;
    }
}

void display() {
    if (isEmpty()) cout << "Stack is empty!";
    else {
        current = top;
        cout << "Stack elements are: ";
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
    }
    cout << endl;
}

int main() {
    push(9);
    push(3);
    push(8);
    display();
    pop();
    display();
    return 0;
}

