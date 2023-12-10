
#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct User {
    string name;
    string phoneNumber;
    double saldo;

    User(string userName, string userPhoneNumber, double userSaldo) : name(userName), phoneNumber(userPhoneNumber), saldo(userSaldo) {}
};

struct Node {
    string title;
    double price;
    User user;
    Node* left;
    Node* right;

    Node(string bookTitle, double bookPrice, User bookUser)
        : title(bookTitle), price(bookPrice), user(bookUser), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, string title, double price, User user) {
        if (node == nullptr) {
            return new Node(title, price, user);
        }

        if (title < node->title) {
            node->left = insert(node->left, title, price, user);
        } else if (title > node->title) {
            node->right = insert(node->right, title, price, user);
        }

        return node;
    }

    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << "Judul: " << node->title << ", Harga: " << node->price << ", Peminjam: " << node->user.name << endl;
            inorderTraversal(node->right);
        }
    }

    Node* searchByPrice(Node* node, double price) {
        if (node == nullptr || node->price == price) {
            return node;
        }

        if (price < node->price) {
            return searchByPrice(node->left, price);
        }

        return searchByPrice(node->right, price);
    }

public:
    BST() : root(nullptr) {}

    void insert(string title, double price, User user) {
        root = insert(root, title, price, user);
        cout << "Buku " << title << " dengan harga " << price << " berhasil ditambahkan ke dalam BST oleh " << user.name << "." << endl;
    }

    void display() {
        cout << "\nDaftar Buku dalam BST (Inorder Traversal):" << endl;
        inorderTraversal(root);
    }

    Node* searchByPrice(double price) {
        Node* result = searchByPrice(root, price);
        if (result != nullptr) {
            cout << "Buku dengan harga " << result->price << " ditemukan dalam BST." << endl;
        } else {
            cout << "Buku dengan harga " << price << " tidak ditemukan dalam BST." << endl;
        }
        return result;
    }

    // Add a function to return a book by title
    void returnBook(string title) {
        // Implementing book return logic here
        // For simplicity, let's just remove the book from the BST
        // In a real-world scenario, you may want to update book status or perform other actions
        // (e.g., updating user information, handling fines, etc.)
        // You can also add additional logic based on your requirements.
        root = removeBook(root, title);
        cout << "Buku dengan judul " << title << " berhasil dikembalikan." << endl;
    }

private:
    Node* removeBook(Node* node, string title) {
        if (node == nullptr) {
            return node;
        }

        if (title < node->title) {
            node->left = removeBook(node->left, title);
        } else if (title > node->title) {
            node->right = removeBook(node->right, title);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Node* temp = minValueNode(node->right);

            // Copy the inorder successor's content to this node
            node->title = temp->title;
            node->price = temp->price;
            node->user = temp->user;

            // Delete the inorder successor
            node->right = removeBook(node->right, temp->title);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;

        // Loop down to find the leftmost leaf
        while (current->left != nullptr) {
            current = current->left;
        }

        return current;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string title, double price, User user) {
        Node* newNode = new Node(title, price, user);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->right = newNode;
            rear = newNode;
        }
        cout << "Buku " << title << " dengan harga " << price << " berhasil ditambahkan ke dalam antrian oleh " << user.name << "." << endl;
    }

    void dequeue(BST& bst) {
        if (isEmpty()) {
            cout << "Antrian kosong. Tidak ada buku yang dapat dihapus." << endl;
            return;
        }

        Node* temp = front;
        front = front->right;
        bst.insert(temp->title, temp->price, temp->user);
        cout << "Buku " << temp->title << " dengan harga " << temp->price << " berhasil dipindahkan ke dalam BST oleh " << temp->user.name << "." << endl;
        delete temp;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(string title, double price, User user) {
        Node* newNode = new Node(title, price, user);
        newNode->right = top;
        top = newNode;
        cout << "Buku " << title << " dengan harga " << price << " berhasil ditambahkan ke dalam stack oleh " << user.name << "." << endl;
    }

    void pop(BST& bst) {
        if (isEmpty()) {
            cout << "Stack kosong. Tidak ada buku yang dapat diambil dari stack." << endl;
            return;
        }

        Node* temp = top;
        top = top->right;
        bst.insert(temp->title, temp->price, temp->user);
        cout << "Buku " << temp->title << " dengan harga " << temp->price << " berhasil diambil dari stack oleh " << temp->user.name << "." << endl;
        delete temp;
    }
};

int main() {
    BST bst;
    Queue bookQueue;
    Stack bookStack;

    // Menu program
    int choice;
    string bookTitle, userName, phoneNumber;
    double bookPrice, saldo;

    do {
        cout << "\nMenu Peminjaman Buku Perpustakaan" << endl;
        cout << "1. Tambah Buku ke Antrian" << endl;
        cout << "2. Pindahkan Buku dari Antrian ke BST" << endl;
        cout << "3. Lihat Daftar Buku dalam BST" << endl;
        cout << "4. Cari Buku berdasarkan Harga" << endl;
        cout << "5. Kembalikan Buku" << endl;  // Added option to return a book
        cout << "6. Ambil Buku dari Stack" << endl;  // Added option to take a book from the stack
        cout << "7. Keluar" << endl;
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan judul buku: ";
                cin.ignore();
                getline(cin, bookTitle);
                cout << "Masukkan harga buku: ";
                while (!(cin >> bookPrice)) {
                    cout << "Invalid input. Please enter a numeric value for harga buku: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Masukkan nama peminjam: ";
                cin.ignore();
                getline(cin, userName);
                cout << "Masukkan nomor HP peminjam: ";
                getline(cin, phoneNumber);
                cout << "Masukkan saldo peminjam: ";
                while (!(cin >> saldo)) {
                    cout << "Invalid input. Please enter a numeric value for saldo: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                bookQueue.enqueue(bookTitle, bookPrice, User(userName, phoneNumber, saldo));
                break;
            case 2:
                bookQueue.dequeue(bst);
                break;
            case 3:
                bst.display();
                break;
            case 4:
                cout << "Masukkan harga buku yang ingin dicari: ";
                while (!(cin >> bookPrice)) {
                    cout << "Invalid input. Please enter a numeric value for harga buku: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                bst.searchByPrice(bookPrice);
                break;
            case 5:
                cout << "Masukkan judul buku yang ingin dikembalikan: ";
                cin.ignore();
                getline(cin, bookTitle);
                bst.returnBook(bookTitle);
                break;
            case 6:
                bookStack.pop(bst);
                break;
            case 7:
                // Exit the program
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

    } while (choice != 7);

    return 0;
}
