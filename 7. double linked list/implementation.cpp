#include <iostream>

using namespace std;

class Node {
public:
    int item;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = NULL;
    }

    int length() {
        Node* temp = head;
        int len = 0;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->item << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* search(int x) {
        Node* temp = head;
        while (temp != NULL) {
            if (x == temp->item) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void insert(int x, int index) {
        Node* temp = head;
        Node* newnode = new Node;
        newnode->item = x;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL) {
            head = newnode;
        }
        else if (index == 0) {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        else {
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            newnode->next = temp->next;
            newnode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newnode;
            }
            temp->next = newnode;
        }
    }

    void insertAfter(int x, int y) {
        Node* temp = head;
        Node* pos = search(y);
        if (pos == NULL) {
            cout << "not found" << endl;
            return;
        }
        Node* newnode = new Node;
        newnode->item = x;
        newnode->prev = pos;
        if (pos->next != NULL) {
            pos->next->prev = newnode;
        }
        newnode->next = pos->next;
        pos->next = newnode;
    }

    void insertBefore(int x, int y) {
        Node* temp = head;
        Node* pos = search(y);
        if (pos == NULL) {
            cout << "not found" << endl;
            return;
        }
        Node* newnode;
        newnode = new Node;
        newnode->item = x;
        newnode->next = pos;
        newnode->prev = pos->prev;
        if (pos->prev != NULL) {
            pos->prev->next = newnode;
        }
        else {
            head = newnode;
        }
        pos->prev = newnode;
    }

    int deleteItem(int x) {
        int val;
        Node* temp = head;
        Node* temp1 = NULL;
        Node* pos = search(x);
        if (pos == NULL) {
            cout << "not found" << endl;
            return -1;
        }
        if (pos == head) {
            val = head->item;
            head = head->next;
            if(head != NULL){
                head->prev = NULL;
            }
            delete pos;
        }
        else {
            while (temp != pos) {
                temp1 = temp;
                temp = temp->next;
            }
            val = temp->item;
            temp1->next = temp->next;
            if(temp->next!=NULL) {
                temp->next->prev = temp1;
            }
            delete temp;
        }
        return val;
    }
};

int main() {
    int index = -1;
    int choice, x, y;
    DoublyLinkedList dl;
    do {
        cout << "-----\n1 for insert\n2 for insert after\n3 for insert before\n4 for delete element\n5 search element\n6 print\n7 length\n8 for exit\n\nenter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "enter element: ";
                cin >> x;
                dl.insert(x, ++index);
                dl.print();
                break;
            case 2:
                cout << "enter element to be inserted: " << endl;
                cin >> x;
                cout << "enter element where the element should be inserted after: ";
                cin >> y;
                dl.insertAfter(x, y);
                dl.print();
                break;
            case 3:
                cout << "enter element to be inserted: " << endl;
                cin >> x;
                cout << "enter element where the element should be inserted before: ";
                cin >> y;
                dl.insertBefore(x, y);
                dl.print();
                break;
            case 4:
                cout << "enter element to be deleted: ";
                cin >> x;
                cout << "element " << dl.deleteItem(x) << " was deleted" << endl;
                dl.print();
                break;
            case 5:
                cout << "enter element to search: ";
                cin >> x;
                cout << dl.search(x) << endl;
                break;
            case 6:
                dl.print();
                break;
            case 7:
                cout << "length of the doubly linked list is: " << dl.length() << endl;
                break;
            case 8:
                break;
        }
    } while (choice != 8);
}
