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
        Node* temp;
        temp = head;
        int len = 0;
        do {
            len++;
            temp = temp->next;
        } while (temp != head);
        return len;
    }

    void print() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->item << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    Node* search(int x) {
        Node* temp;
        temp = head;
        do {
            if (x == temp->item) {
                return temp;
            }
            temp = temp->next;
        } while (temp != head);
        return NULL;
    }

    void insert(int x, int index) {
        Node* temp;
        temp = head;
        Node* newnode;
        if (head == NULL) {
            newnode = new Node;
            newnode->item = x;
            newnode->next = newnode;
            head = newnode;
        }
        else if (index == 0) {
            newnode = new Node;
            newnode->item = x;
            newnode->next = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newnode;
            head = newnode;
        }
        else {
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            newnode = new Node;
            newnode->item = x;
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    void rotate(int k) {
        if (head == NULL || k <= 0) {
            return;
        }

        Node* current = head;
        int count = 1;

        while (current->next != head) {
            current = current->next;
            count++;
        }

        k = k % count;

        if (k == 0) {
            return;
        }

        current = head;
        for (int i = 1; i < (count - k); i++) {
            current = current->next;
        }

        Node* newHead = current->next;
        current->next = head;
        head = newHead;

        current = head;
        for (int i = 1; i < count; i++) {
            current = current->next;
        }
        current->next = head;
    }
};

int main() {
    int n,x,k;
    CircularLinkedList l;
    int index = -1;
    cout<<"enter n: ";
    cin>>n;
    cout<<"enter: ";
    for(int i=0;i<n;i++){
        cin>>x;
        l.insert(x,++index);
    }
    cout<<"k: ";
    cin>>k;
    l.rotate(k);

    l.print();

    return 0;
}