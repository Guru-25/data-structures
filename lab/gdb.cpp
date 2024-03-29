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
public:
    Node* root;

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
            cout << "enter lchild child of " << p->data << ": ";
            cin >> x;
            if (x != -1) {
                t = new Node;
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                q.enqueue(t);
            }
            cout << "enter rchild child of " << p->data << ": ";
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

    int Height() {
        return Height(root);
    }

    int Height(Node* root) {
        int x = 0, y = 0;
        if (root == nullptr)
            return -1;
        x = Height(root->lchild);
        y = Height(root->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }

    int CountNodes() {
        return CountNodes(root);
    }

    int CountNodes(Node* root) {
        if (root == nullptr)
            return 0;
        return CountNodes(root->lchild) + CountNodes(root->rchild) + 1;
    }

    int SumNodes() {
        return SumNodes(root);
    }

    int SumNodes(Node* root) {
        if (root == nullptr)
            return 0;
        return SumNodes(root->lchild) + SumNodes(root->rchild) + root->data;
    }

    int CountLeafNodes() {
        return CountLeafNodes(root);
    }

    int CountLeafNodes(Node* root) {
        if (root == nullptr)
            return 0;
        if (root->lchild == nullptr && root->rchild == nullptr)
            return 1;
        return CountLeafNodes(root->lchild) + CountLeafNodes(root->rchild);
    }

    // int rangesum(Node* p,int n1,int n2){
    //     int x,y;
    //     if(p){
    //         x=rangesum(p->lchild,n1,n2);
    //         y=rangesum(p->rchild,n1,n2);
    //         if(p->data >=n1 && p->data<=n2){
    //             return x+y+p->data;
    //         }
    //         else{
    //             return x+y;
    //         }
    //     }
    //     return 0;
    // }
    int kthsmallest(Node* p, int k) {
        int x, y;
        static int count = 0;  // Using static to maintain count across recursive calls

        if (p) {
            x = kthsmallest(p->lchild, k);
            count++;
            if (k == count) {
                return p->data;
            }
            y = kthsmallest(p->rchild, k);
        }

        return 0;
    }
    // int kthlargest(Node* p, int k) {
    //     int x, y;
    //     static int count = 0;  // Using static to maintain count across recursive calls

    //     if (p) {
    //         x = kthlargest(p->lchild, k);
    //         count++;
    //         if (k == count) {
    //             return p->data;
    //         }
    //         y = kthlargest(p->rchild, k);
    //     }

    //     return 0;
    // }
};

int main() {
    Tree t;
    t.CreateTree();
    
    int choice;
    
    while (true) {
        cout << endl;
        cout << "1 for height" << endl;
        cout << "2 for no of nodes" << endl;
        cout << "3 for sum of nodes" << endl;
        cout << "4 for no of leaf nodes" << endl;
        cout << "enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "height: " << t.Height() << endl;
                break;
            case 2:
                cout << "no of nodes: " << t.CountNodes() << endl;
                break;
            case 3:
                cout << "sum of nodes: " << t.SumNodes() << endl;
                break;
            case 4:
                cout << "no of leaf nodes: " << t.CountLeafNodes() << endl;
                break;
            case 5:
                cout<<t.kthsmallest(t.root,3)<<endl;
                break;
            default:
                cout << "invalid choice" << endl;
        }
    }
    return 0;
}
