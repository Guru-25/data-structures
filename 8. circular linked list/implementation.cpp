#include <iostream>

using namespace std;

class Node {
public:
    int item;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() {
        head = NULL;
    }

    int length() {
        Node* temp = head;
        int len = 0;
        do {
            len++;
            temp = temp->next;
        } while (temp != head);
        return len;
    }

    void print() {
        Node* temp = head;
        do {
            cout << temp->item << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    Node* search(int x) {
        Node* temp = head;
        do {
            if (x == temp->item) {
                return temp;
            }
            temp = temp->next;
        } while (temp != head);
        return NULL;
    }

    void insert(int x, int index) {
        Node* temp = head;
        Node* newnode = new Node;
        newnode->item = x;
        newnode->next = head;
        if (head == NULL) {
            newnode->next = newnode;
            head = newnode;
        }
        else if (index == 0) {
            head = newnode;
        }
        else {
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            newnode->next = temp->next;
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
        newnode->next = head;
        while (temp != pos) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void insertBefore(int x, int y) {
        Node* temp = head;
        Node* pos = search(y);
        if (pos == NULL) {
            cout << "not found" << endl;
            return;
        }
        Node* newnode = new Node;
        newnode->item = x;
        newnode->next = head;

        if (pos == head) {
            head = newnode;
        }
        else {
            while (temp->next != pos) {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
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
            delete pos;
        }
        else {
            while (temp != pos) {
                temp1 = temp;
                temp = temp->next;
            }
            val = temp->item;
            temp1->next = temp->next;
            delete temp;
        }
        return val;
    }
};

int main() {
    int index = -1;
    int choice, x, y;
    CircularLinkedList l;
    do {
        cout << "-----\n1 for insert\n2 for insert after\n3 for insert before\n4 for delete element\n5 search element\n6 print\n7 length\n8 for exit\n\nenter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "enter element: ";
            cin >> x;
            l.insert(x, ++index);
            l.print();
            break;
        case 2:
            cout << "enter element to be inserted: " << endl;
            cin >> x;
            cout << "enter element where the element should be inserted after: ";
            cin >> y;
            l.insertAfter(x, y);
            l.print();
            break;
        case 3:
            cout << "enter element to be inserted: " << endl;
            cin >> x;
            cout << "enter element where the element should be inserted before: ";
            cin >> y;
            l.insertBefore(x, y);
            l.print();
            break;
        case 4:
            cout << "enter element to be deleted: ";
            cin >> x;
            cout << "element " << l.deleteItem(x) << " was deleted" << endl;
            l.print();
            break;
        case 5:
            cout << "enter element to search: ";
            cin >> x;
            cout << l.search(x) << endl;
            break;
        case 6:
            l.print();
            break;
        case 7:
            cout << "length of the linked list is: " << l.length() << endl;
            break;
        case 8:
            break;
        }
    } while (choice != 8);
}