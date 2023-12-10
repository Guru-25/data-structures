#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class HashTable {
public:
    Node** HT;

    HashTable() {
        HT = new Node*[10];
        for (int i = 0; i < 10; i++) {
            HT[i] = nullptr;
        }
    }

    int hash(int key) {
        return key % 10;
    }

    void Insert(int key) {
        int hIdx = hash(key);
        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = nullptr;

        if (HT[hIdx] == nullptr) {
            HT[hIdx] = newNode;
        } else {
            Node* current = HT[hIdx];
            Node* previous = HT[hIdx];

            while (current && current->data < key) {
                previous = current;
                current = current->next;
            }

            if (previous == HT[hIdx]) {
                newNode->next = HT[hIdx];
                HT[hIdx] = newNode;
            } else {
                newNode->next = previous->next;
                previous->next = newNode;
            }
        }
    }

    int Search(int key) {
        int hIdx = hash(key);
        Node* current = HT[hIdx];

        while (current) {
            if (current->data == key) {
                return current->data;
            }
            current = current->next;
        }

        return -1;
    }

    void PrintTable() {
        for (int i = 0; i < 10; i++) {
            Node* current = HT[i];
            cout << i << " - ";
            while (current) {
                cout << current->data;
                if (current->next) {
                    cout << "->";
                }
                current = current->next;
            }
            cout << (HT[i] ? "" : "-") << endl;
        }
    }

    float LoadFactor() {
        int count = 0;
        for (int i = 0; i < 10; i++) {
            Node* current = HT[i];
            while (current) {
                count++;
                current = current->next;
            }
        }
        return static_cast<float>(count) / 10.0;
    }
};

int main() {
    HashTable H;

    int option;
    int key;
    int value;

    while (true) {
        cout << "1 for insert" << endl;
        cout << "2 for search" << endl;
        cout << "3 for load factor" << endl;
        cout << "enter choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "enter the value to insert: ";
                cin >> key;
                H.Insert(key);
                H.PrintTable();
                break;

            case 2:
                cout << "enter the value to search: ";
                cin >> key;
                value = H.Search(key);
                if (value != -1) {
                    cout << "key found at " << value << endl;
                } else {
                    cout << "key not found" << endl;
                }
                break;

            case 3:
                cout << "load factor: " << H.LoadFactor() << endl;
                break;

            default:
                cout << "invalid option" << endl;
        }
    }

    return 0;
}
