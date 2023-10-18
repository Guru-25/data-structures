#include <iostream>

using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class Queue {
private:
    int front;
    int rear;
    int size;
    Node** Q;

public:
    Queue(int size) {
        front = rear = -1;
        this->size = size;
        Q = new Node*[size];
    }

    void enqueue(Node* x) {
        if (rear == size - 1)
            cout << "queue full" << endl;
        else {
            rear++;
            Q[rear] = x;
        }
    }

    Node* dequeue() {
        Node* x = NULL;
        if (front == rear)
            cout << "queue is empty" << endl;
        else {
            x = Q[front + 1];
            front++;
        }
        return x;
    }

    int isEmpty() {
        return front == rear;
    }
};

class Tree {
    Node* root;

public:
    Tree() {
        root = NULL;
    }

    void CreateTree() {
        Node* p, * t = NULL;
        int x;
        Queue q(100);
        cout << "enter root value: ";
        cin >> x;
        root = new Node;
        root->data = x;
        root->lchild = root->rchild = NULL;
        q.enqueue(root);
        while (!q.isEmpty()) {
            p = q.dequeue();
            cout << "enter left child of " << p->data << ": ";
            cin >> x;
            if (x != -1) {
                t = new Node;
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                q.enqueue(t);
            }
            cout << "enter right child of " << p->data << ": ";
            cin >> x;
            if (x != -1) {
                t = new Node;
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                q.enqueue(t);
            }
        }
    }

    void Preorder() {
        Preorder(root);
    }

    void Preorder(Node* p) {
        if (p) {
            cout << p->data << " ";
            Preorder(p->lchild);
            Preorder(p->rchild);
        }
    }

    void Postorder() {
        Postorder(root);
    }

    void Postorder(Node* p) {
        if (p) {
            Postorder(p->lchild);
            Postorder(p->rchild);
            cout << p->data << " ";
        }
    }

    void Inorder() {
        Inorder(root);
    }

    void Inorder(Node* p) {
        if (p) {
            Inorder(p->lchild);
            cout << p->data << " ";
            Inorder(p->rchild);
        }
    }

    void Levelorder() {
        Levelorder(root);
    }

    void Levelorder(Node* p) {
        Queue q(100);
        cout << root->data << " ";
        q.enqueue(root);
        while (!q.isEmpty()) {
            root = q.dequeue();
            if (root->lchild) {
                cout << root->lchild->data << " ";
                q.enqueue(root->lchild);
            }
            if (root->rchild) {
                cout << root->rchild->data << " ";
                q.enqueue(root->rchild);
            }
        }
    }
};

int main() {
    Tree t;
    t.CreateTree();
    cout << endl;
    cout << "Pre order: ";
    t.Preorder();
    cout << endl;
    cout << "In order: ";
    t.Inorder();
    cout << endl;
    cout << "Post order: ";
    t.Postorder();
    cout << endl;
    return 0;
}
