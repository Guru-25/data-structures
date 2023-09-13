#include <iostream>

using namespace std;

class Node {
public:
    int item;
    Node* next;
};

class LinkedList {
public:
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
};

int main() {
    string n1, n2;
    LinkedList l1, l2;
    cout << "enter n1: ";
    cin >> n1;
    cout << "enter n2: ";
    cin >> n2;

    for (char c : n1) {
        int digit = c - '0';
        l1.insert(digit, 0);
    }

    for (char c : n2) {
        int digit = c - '0';
        l2.insert(digit, 0);
    }

    LinkedList result;
    int carry = 0;

    Node* cur1 = l1.head;
    Node* cur2 = l2.head;

    while (cur1 || cur2 || carry) {
        int sum = carry;
        if (cur1) {
            sum += cur1->item;
            cur1 = cur1->next;
        }
        if (cur2) {
            sum += cur2->item;
            cur2 = cur2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;
        result.insert(digit, 0);
    }
    
    result.print();

    return 0;
}