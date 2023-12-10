#include <iostream>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

struct Node* createNode(char data) {
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

class Stack {
    Node* data[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(Node* node) {
        data[++top] = node;
    }

    Node* pop() {
        return data[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int isValidPostfixExpression(const char postfix[]) {
    int operandCount = 0;
    int operatorCount = 0;

    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];

        if (isspace(c)) {
            continue;
        } else if (isalnum(c)) {
            operandCount++;
        } else if (isOperator(c)) {
            operatorCount++;
        } else {
            return 0;
        }

        if (operatorCount >= operandCount) {
            return 0;
        }
    }

    if (operandCount - operatorCount != 1) {
        return 0;
    }

    return 1;
}

int evaluateExpressionTree(Node* root) {
    if (root != nullptr) {
        if (!isOperator(root->data)) {
            return root->data - '0';
        }

        int left = evaluateExpressionTree(root->left);
        int right = evaluateExpressionTree(root->right);

        if (root->data == '+') {
            return left + right;
        } else if (root->data == '-') {
            return left - right;
        } else if (root->data == '*') {
            return left * right;
        } else if (root->data == '/') {
            return left / right;
        }
    }
    return 0;
}

void printPrefix(Node* root) {
    if (root != nullptr) {
        cout << root->data;
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

void printInfix(Node* root, int isRoot) {
    if (root != nullptr) {
        if (isOperator(root->data) && !isRoot) {
            cout << "(";
        }
        printInfix(root->left, 0);
        cout << root->data;
        printInfix(root->right, 0);
        if (isOperator(root->data) && !isRoot) {
            cout << ")";
        }
    }
}

void printPostfix(Node* root) {
    if (root != nullptr) {
        printPostfix(root->left);
        printPostfix(root->right);
        cout << root->data;
    }
}

int main() {
    char postfix[100];

    cout << "enter postfix expression: ";
    cin >> postfix;

    if (isValidPostfixExpression(postfix)) {
        Stack stack;

        for (int i = 0; postfix[i]; i++) {
            char c = postfix[i];

            Node* newNode = createNode(c);

            if (isOperator(c)) {
                newNode->right = stack.pop();
                newNode->left = stack.pop();
            }

            stack.push(newNode);
        }

        Node* root = stack.pop();

        int result = evaluateExpressionTree(root);
        cout << endl;
        cout << "result: " << result << endl;

        cout << "prefix expression: ";
        printPrefix(root);
        cout << endl;

        cout << "infix expression: ";
        printInfix(root, 1);
        cout << endl;

        cout << "postfix expression: ";
        printPostfix(root);
        cout << endl;
    }
    else {
        cout << "invalid postfix expression" << endl;
    }

    return 0;
}
