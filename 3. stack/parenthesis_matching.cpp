#include <iostream>

using namespace std;

class Stack {
private:
    int size;
    char* S;
    int top;
public:
    Stack(int size);
    void push(char x);
    char pop();
    int isFull();
    int isEmpty();
};

Stack::Stack(int size) : size(size) {
    S = new char[size];
    top = -1;
}

void Stack::push(char x) {
    if (!isFull()) {
        top++;
        S[top] = x;
    } else {
        cout << "Stack Overflow" << endl;
    }
}

char Stack::pop() {
    char x;
    if (!isEmpty()) {
        x = S[top];
        top--;
    } else {
        cout << "Stack Underflow" << endl;
    }
    return x;
}

int Stack::isFull() {
    return top == size - 1;
}

int Stack::isEmpty() {
    return top == -1;
}

Stack::~Stack() {
    delete[] S;
}

int main() {
    string exp;
    cout << "enter infix: ";
    cin >> exp;

    Stack stk(exp.size());
    bool balanced = true;
    for(int i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            stk.push(exp[i]);
        } else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (stk.isEmpty()) {
                balanced = false;
                break;
            }
            char topBracket = stk.pop();
            if((exp[i] == ')' && topBracket != '(') || (exp[i] == ']' && topBracket != '[') || (exp[i] == '}' && topBracket != '{')) {
                balanced = false;
                break;
            }
        }
    }
    
    if(balanced && stk.isEmpty()) {
        cout << "matches" << endl;
    } else {
        cout << "not matches" << endl;
    }

    return 0;
}