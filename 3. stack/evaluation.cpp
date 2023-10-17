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

int isOperator(char x) {
    return x == '+' || x =='-' || x == '*' || x == '/';
}

int pre(char x) {
    switch (x) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

int main() {
    string infix;
    cout << "enter infix: ";
    cin >> infix;

    char *postfix = new char[infix.size() +1];
    Stack stk(infix.size());
    int i=0, j=0;

    while(infix[i] != '\0') {
        if(!isOperator(infix[i])) {
            postfix[j]=infix[i];
            i++;
            j++;
        } else {
            if(pre(infix[i]) > pre(stk.stackTop())) {
                stk.push(infix[i]);
                i++;
            } else {
                postfix[j]=stk.pop();
                stk.push(infix[i]);
                j++;
                i++;
            }
        }
    }
    while(!stk.isEmpty()) {
        postfix[j]=stk.pop();
        j++;
    }
    postfix[j] = '\0';
    cout << "postfix: " << postfix << endl;

    j = 0;
    int x,y;
    while(postfix[j] != '\0') {
        if(!isOperator(postfix[j])) {
            stk.push(postfix[j] - '0');
            j++;
        } 
        else{
            y = stk.pop(); 
            x = stk.pop();
            switch(postfix[j]) {
                case '+':
                    stk.push(x+y);
                    break;
                case '-':
                    stk.push(x-y);
                    break;
                case '*':
                    stk.push(x*y);
                    break;
                case '/':
                    stk.push(x/y);
                    break;
            }
            j++;
        }
    }
    cout << "ans: " << stk.stackTop() << endl;
    delete[] postfix;

    return 0;
}