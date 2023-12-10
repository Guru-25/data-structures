#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class BST{
public:
    Node* root;

    BST(){
        root=NULL;
    }
    Node* insert(Node* p, int x){
        Node* t;
        if(p==NULL){
            t=new Node;
            t->data=x;
            t->left=NULL;
            t->right=NULL;
            return t; //return
        }
        else if(x<p->data){
            p->left=insert(p->left,x);
        }
        else if(x>p->data){
            p->right=insert(p->right,x);
        }
        return p;//return
    }
    Node* search(Node* p, int key){
        if(p==NULL){
            return NULL;
        }
        if(p->data==key){
            return p;
        }
        else if(key <p->data){
            return search(p->left,key); //return is must
        }
        else{
            return search(p->right,key); //return is must
        }
        return NULL;
    }
    int largestlst(Node* p){
        if(p->right==NULL){
            return p->data;
        }
        return largestlst(p->right);
    }

    Node* del(Node* p, int x){
        if(p==NULL){
            return p;
        }
        if(x<p->data){
            p->left=del(p->left,x);
        }
        else if(x>p->data){
            p->right=del(p->right,x);
        }
        else{
            if(p->left==NULL){
                Node* temp=p->right;
                delete p;
                return temp;
            }
            if(p->right==NULL){
                Node* temp=p->left;
                delete p;
                return temp;
            }
            
            p->data=largestlst(p->left);
            p->left=del(p->left,p->data); // imp
        }
        return p;//
    }
    void inoder(Node* p){
        if(p){
            inoder(p->left);
            cout<<p->data<< " ";
            inoder(p->right);
        }
    }
};
int main(){
    int choice,x;
    BST bst;
    while(true){
        cout<<"1 insert\n2 search\n3 delete\nchoice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter: ";
                cin >>x;
                bst.root=bst.insert(bst.root,x); //imp
                bst.inoder(bst.root);
                cout<<endl;
                break;
            case 2:
                cout<<"enter: ";
                cin >> x;
                if(bst.search(bst.root,x)){
                    cout<<"found"<<endl;
                }
                else{
                    cout<<"not found"<<endl;
                }
                break;
            case 3:
                cout<<"enter: ";
                cin >> x;
                if(bst.search(bst.root,x)!=NULL){
                    bst.root=bst.del(bst.root, x); // imp
                    cout << x << " was deleted"<<endl;
                }
                else{
                    cout<<"not found"<<endl;
                }
                bst.inoder(bst.root);
                cout<<endl;
                break;
        }
    }
}