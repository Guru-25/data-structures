#include <iostream>

using namespace std;

class Node {
public:
    int item;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    int length() {
        Node* temp;
        temp = head;
        int len = 0;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void print() {
        Node* temp;
        temp = head;
        while(temp != NULL) {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* search(int x) {
        Node* temp;
        temp = head;
        while(temp != NULL) {
            if(x == temp->item) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void insert(int x, int index) {
        Node* temp;
        temp = head;
        Node* newnode;
        if(head == NULL) {
            newnode = new Node;
            newnode->item = x;
            newnode->next = NULL;
            head = newnode;
        }
        else if(index == 0) {
            newnode = new Node;
            newnode->item = x;
            newnode->next = head;
            head = newnode;
        }
        else {
            for(int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            newnode = new Node;
            newnode->item = x;
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    void insertAfter(int x, int y) {
        Node* temp;
        temp = head;
        Node* pos = search(y);
        if(pos == NULL) {
            cout << "not found" << endl;
            return;
        }
        Node* newnode;
        newnode = new Node;
        newnode->item = x;
        newnode->next = NULL;
        while(temp != pos) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void insertBefore(int x, int y) {
        Node* temp;
        temp = head;
        Node* pos = search(y);
        if(pos == NULL) {
            cout << "not found" << endl;
            return;
        }
        Node* newnode;
        newnode = new Node;
        newnode->item = x;
        newnode->next = NULL;

        if(pos == head) {
            newnode->next = head;
            head = newnode;
        }
        else {
            while(temp->next != pos) {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    int deleteItem(int x) {
        int val;
        Node* temp;
        Node* temp1;
        temp1 = NULL;
        temp = head;
        Node* pos = search(x);
        if(pos == NULL) {
            cout << "not found" << endl;
            return -1;
        }
        if(head == pos) {
            val = head->item;
            head = head->next;
            delete temp;
        }
        else {
            while(temp != pos) {
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
    LinkedList l;
    do {
        cout << "-----\n1 for insert\n2 for insert after\n3 for insert before\n4 for delete element\n5 search element\n6 print\n7 length\n8 for exit\n\nenter choice: ";
        cin >> choice;
        switch(choice) {
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
    } while(choice != 8);
}