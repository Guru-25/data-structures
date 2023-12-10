#include<iostream>

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
        return kthsmallest(p->right,k,count);
    }
};

int main(){
    int choice;
    Tree t;
    while(true){
        cout<<"1 insert\n2 pre\n3 in\n4 post\n5 level\n6 range sum\n7 kth smallest\nchoice: ";
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