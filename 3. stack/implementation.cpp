#include <iostream>

using namespace std;

class Stack {
private:
    int size;
    int* S;
    int top;
public:
    Stack(int size);
    void push(int x);
    int pop();
    int peek(int index);
    int stackTop();
    int isFull();
    int isEmpty();
    void display();
};

Stack::Stack(int size) : size(size) {
    S = new int[size];
    top = -1;
}

void Stack::push(int x) {
    if (!isFull()) {
        top++;
        S[top] = x;
    } else {
        cout << "Stack Overflow" << endl;
    }
}

int Stack::pop() {
    int x = -1;
    if (!isEmpty()) {
        x = S[top];
        top--;
    } else {
        cout << "Stack Underflow" << endl;
    }
    return x;
}

int Stack::peek(int index) {
    int x = -1;
    if(top - index < 0 || top - index > size - 1) {
        cout << "invalid position" << endl;
    } else {
        x = S[top - index];
    }
    return x;
}

int Stack::stackTop() {
    if (!isEmpty()) {
        return S[top];
    }
    return -1;
}

void Stack::display() {
    for(int i = top; i >= 0; i--) {
        cout << i << " - " << S[i] << endl;
    }
}

int Stack::isFull() {
    return top == size - 1;
}

int Stack::isEmpty() {
    return top == -1;
}

int main() {
    int choice, x, size;
    cout << "enter size: ";
    cin >> size;

    Stack stk(size);

    do {
        cout << "\n----------\n\n1 for push\n2 for is stack full\n3 for peek\n4 for top element\n5 for pop\n6 for is stack empty\n7 for display\n8 for exit\n\nenter choice: ";
        cin >> choice;

        cout << "\nBefore operation:" << endl;
        stk.display();
        cout << endl;

        switch(choice) {
            case 1:
                cout << "enter element: ";
                cin >> x;
                stk.push(x);
                cout << "\nAfter push:" << endl;
                stk.display();
                break;
            case 2:
                cout << "Stack full: " << stk.isFull() << endl;
                break;
            case 3:
                cout << "enter index: ";
                cin >> x;
                cout << stk.peek(x) << endl; 
                break;
            case 4:
                cout << "Top element: " << stk.stackTop() << endl;
                break;
            case 5:
                stk.pop();
                cout << "After pop:" << endl;
                stk.display();
                break;
            case 6:
                cout << "Stack empty: " << stk.isEmpty() << endl;
                break;
            case 7:
                cout << "After display:" << endl;
                stk.display();
                break;
            case 8:
                break;
            default:
                cout << "not a valid choice" << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}