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

    void insert(int x, int index) {
        Node* temp = head;
        Node* newnode = new Node;
        newnode->item = x;
        newnode->next = NULL;
        if(head == NULL) {
            head = newnode;
        }
        else if(index == 0) {
            newnode->next = head;
            head = newnode;
        }
        else {
            for(int i = 1; i < index; i++) {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    Node* search(int x) {
        Node* temp = head;
        while(temp != NULL) {
            if(x == temp->item) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    int deleteItem(int x) {
        int val;
        Node* temp = head;
        Node* temp1 = NULL;
        Node* pos = search(x);
        if(pos == NULL) {
            cout << "not found" << endl;
            return -1;
        }
        if(pos == head) {
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

    void print() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->item << " -> ";
            temp = temp->next;
        }
        cout << "NULL"<< endl;
    }

    void add(){
        string n1, n2;
        LinkedList l1, l2;
        cout << "enter n1: ";
        cin >> n1;
        cout << "enter n2: ";
        cin >> n2;
        int i=0;

        while(n1[i]!='\0'){
            int digit = n1[i] - '0';
            l1.insert(digit, 0);
            i++;
        }
        i=0;

        while(n2[i]!='\0'){
            int digit = n2[i] - '0';
            l2.insert(digit, 0);
            i++;
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
    }
};

int main() {
    int index = -1;
    int choice, x, y;
    LinkedList l;
    do {
        cout << "-----\n1 for insert\n2 for search\n3 for delete element\n4 for add\n\nenter choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "enter element: ";
                cin >> x;
                l.insert(x, ++index);
                l.print();
                break;
            case 2:
                cout << "enter element to search: ";
                cin >> x;
                if(l.search(x) !=NULL){
                    cout << x <<" was found"<<endl;
                } else{
                    cout << x <<" was not found"<<endl;
                }
                break;
            case 3:
                cout << "enter element to be deleted: ";
                cin >> x;
                cout << "element " << l.deleteItem(x) << " was deleted" << endl;
                l.print();
                break;
            case 4:
                l.add();
                break;
            case 5:
                break;
        }
    } while(choice != 5);
}