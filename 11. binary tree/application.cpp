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

    void CreateTree() {#include<iostream>

using namespace std;

class Node{//
public://
    Node* left;
    Node* right;
    int data;
};
class Queue{
private:
    int front, rear,size;
    Node** q; //
public:
    Queue(int size):size(size){
        front=rear=-1;
        q=new Node*[size]; //
    }

    void enqueue(Node* x){
        if(rear==size-1){
            cout<<"full"<<endl;
        }
        else{
            rear++;
            q[rear]=x;
        }
    }
    Node* dequeue(){
        Node* x=NULL;
        if(front == rear){
            cout<<"empty"<<endl;
        }
        else{
            x=q[front+1];
            front++;
        }
        return x;
    }

    int isEmpty(){
        return front==rear;
    }
};
class Tree{
public:
    Node* root;

    Tree(){
        root=NULL;
    }
    void create(){
        int x;
        Node* p;
        Node* t;
        Queue q(100);
        cout<<"enter root: ";
        cin>>x;
        root=new Node; // very very imp
        root->data=x;
        root->left=root->right=NULL;
        q.enqueue(root);
        while(!q.isEmpty()){
            p=q.dequeue();
            cout<<"left of "<<p->data<<": ";
            cin>>x;
            if(x!=-1){
                t=new Node;
                t->data=x;
                t->left=t->right=NULL;
                p->left=t;
                q.enqueue(t);
            }
            cout<<"right of "<<p->data<<": ";
            cin>>x;
            if(x!=-1){
                t=new Node;
                t->data=x;
                t->left=t->right=NULL;
                p->right=t;
                q.enqueue(t);
            }
        }
    }
    void pre(Node* p){
        if(p){
            cout<<p->data<<" ";
            pre(p->left);
            pre(p->right);
        }
    }
    void in(Node* p){
        if(p){
            in(p->left);
            cout<<p->data<<" ";
            in(p->right);
        }
    }
    void post(Node* p){
        if(p){
            post(p->left);
            post(p->right);
            cout<<p->data<<" ";
        }
    }
    void level(){ //
        Queue q(100);
        cout << root->data<<" ";
        q.enqueue(root);
        while(!q.isEmpty()){
            root=q.dequeue();
            if(root->left){
                cout<<root->left->data<<" ";
                q.enqueue(root->left);
            }
            if(root->right){
                cout<<root->right->data<<" ";
                q.enqueue(root->right);
            }
        }
    }
    int rangesum(Node* p, int n1,int n2){
        int x,y;
        if(p){
            x=rangesum(p->left,n1,n2);
            y=rangesum(p->right,n1,n2);
            if(p->data>=n1 && p->data<=n2){
                return x+y+p->data;
            }
            else{
                return x+y;
            }
        }
        return 0;
    }
    int kthsmallest(Node* p, int k, int& count){
        if(p==NULL){
            return -1;
        }
        int lefte = kthsmallest(p->left,k,count);
        if(lefte != -1){
            return lefte;
        }
        count++;
        if(count==k){
            return p->data;
        }
        return kthsmallest(p->left,k,count);
    }
};

int main(){
    int choice;
    Tree t;
    while(true){
        cout<<"1 insert\\n2 pre\\n3 in\\n4 post\\n5 level\\n6 range sum\\n7 kth smallest\\nchoice: ";
        cin>>choice;
        switch(choice){
            case 1:
                t.create();
                break;
            case 2:
                t.pre(t.root);
                cout <<endl;
                break;
            case 3:
                t.in(t.root);
                cout <<endl;
                break;
            case 4:
                t.post(t.root);
                cout <<endl;
                break;
            case 5:
                t.level();
                cout<<endl;
                break;
            case 6:
                cout <<t.rangesum(t.root,1,4)<<endl;
                break;
            case 7:
                int k;
                int count=0;
                cout<<"enter k: ";
                cin>>k;
                int kthsmallest=t.kthsmallest(t.root,k,count);
                if(kthsmallest!=-1){
                    cout<<kthsmallest<<endl;
                } else{
                    cout<<"not found"<<endl;
                }
                break;
        }
    }

    return 0;
}
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

    int rangesum(Node* p,int n1,int n2){
        int x,y;
        if(p){
            x=rangesum(p->left,n1,n2);
            y=rangesum(p->right,n1,n2);
            if(p->data >=n1 && p->data<=n2){
                return x+y+p->data;
            }
            else{
                return x+y;
            }
        }
        return 0;
    }
    int kthsmallest(Node* p, int k) {
        int x, y;
        static int count = 0;  // Using static to maintain count across recursive calls

        if (p) {
            x = kthsmallest(p->left, k);
            count++;
            if (k == count) {
                return p->data;
            }
            y = kthsmallest(p->right, k);
        }

        return 0;
    }
    int count(Node* p) {
        int x, y;
        if (p) {
            x = count(p->left);
            y = count(p->right);
            return x+y+1;
        }
        return 0;
    }
    int kthlargest(Node* p, int k) {
        int x, y;

        if (p) {
            x = kthlargest(p->left, k);
            count++;
            if (k == count) {
                return p->data;
            }
            y = kthlargest(p->right, k);
        }

        return 0;
    }
    int main(){
        int k=10;
        k=count(p) - k;
        kthlargest(p, k);
    }
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
            default:
                cout << "invalid choice" << endl;
        }
    }
    return 0;
}
