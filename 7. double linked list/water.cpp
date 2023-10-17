#include <iostream>

using namespace std;

class Node {
public:
    int item;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    int length() {
        int len = 0;
        Node* temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insert(int x) {
        Node* newnode = new Node;
        newnode->item = x;
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
};

int main() {
    int n;
    DoublyLinkedList list;
    int x;
    cout<<"enter n:";
    cin>>n;
    cout<<"enter: ";
    for(int i=0;i<n;i++){
        cin>>x;
        list.insert(x);
    }

    list.insert(4);
    list.insert(1);
    list.insert(4);
    // list.insert(2);
    // list.insert(5);
    // list.insert(4);
    // list.insert(8);
    // list.insert(3);
    // list.insert(7);

    Node* left = list.head;
    Node* right = list.tail;
    int max_area_value = 0;

    while (left != right) {
        int distance = 0;
        Node* temp = left;
        while (temp != right) {
            distance++;
            temp = temp->next;
        }

        int area = min(left->item, right->item) * distance;
        max_area_value = max(max_area_value, area);

        if (left->item < right->item) {
            left = left->next;
        } else {
            right = right->prev;
        }
    }

    cout << "The maximum area of the container is: " << max_area_value << endl;

    return 0;
}
