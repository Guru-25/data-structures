#include<iostream>

using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
};

class BST{
public:
    Node* root;

    BST(){
        root=NULL;
    }

    Node* search(Node* p, int key){
        if(p==NULL){
            return NULL;
        }
        if(key==p->data){
            return p;
        }
        else if(key<p->data){
            return search(p->left, key);
        }
        else {
            return search(p->right, key);
        }
        return NULL;
    }
    Node* insert(Node* p, int key){
        Node* t;
        if(p==NULL){
            t=new Node;
            t->data=key;
            t->left=NULL;
            t->right=NULL;
            return t;
        }
        else if(key<p->data){
            p->left=insert(p->left,key);
        }
        else if(key>p->data){
            p->right=insert(p->right,key);
        }
        return p;
    }
    int largestlst(Node* p){
        if(p->right==NULL){
            return p->data;
        }
        else{
            return largestlst(p->right);
        }
    }
    Node* del(Node* p, int key){
        if(p==NULL){
            return NULL;
        }
        else if(key<p->data){
            p->left=del(p->left,key);
        }
        else if(key>p->data){
            p->right=del(p->right,key);
        }
        else{
            if(p->left==NULL){
                Node* temp=p->right;
                return temp;
                delete p;
            }
            if(p->right==NULL){
                Node* temp=p->left;
                return temp;
                delete p;
            }
            p->data=largestlst(p->left);
            p->left=del(p->left,p->data);
        }
        return p;
    }
    void inorder(Node* p){
        if(p){
            inorder(p->left);
            cout<<p->data<<" ";
            inorder(p->right);
        }
    }
    int count(Node* p){
        int x,y;
        if(p){
            x=count(p->left);
            y=count(p->right);
            return x+y+1;
        }
        return 0;
    }
    int kthSmallest(Node* p, int k, int& count) {
        if (p == NULL) {
            return -1;  // Return -1 if k is out of bounds
        }

        int leftResult = kthSmallest(p->left, k, count);

        if (leftResult != -1) {
            return leftResult;
        }

        count++;
        if (count == k) {
            return p->data;
        }

        return kthSmallest(p->right, k, count);
    }
    
};

int main(){
    int choice, x;
    BST bst;
    while(true){
        cout << "1 insert\n2 search\n3 delete\n4 kth smallest\nchoice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "enter: ";
                cin >> x;
                bst.root = bst.insert(bst.root, x);
                bst.inorder(bst.root);
                cout << endl;
                break;
            case 2:
                cout << "enter: ";
                cin >> x;
                if (bst.search(bst.root, x) != NULL){
                    cout << x << " was found" << endl;
                } else{
                    cout << x << " was not found" << endl;
                }
                break;
            case 3:
                cout << "enter: ";
                cin >> x;
                if (bst.search(bst.root, x) != NULL){
                    bst.root = bst.del(bst.root, x);
                    cout << x << " was deleted" << endl;
                } else{
                    cout << x << " was not found" << endl;
                }
                bst.inorder(bst.root);
                cout << endl;
                break;
            case 4:
                int k;
                cout << "Enter k: ";
                cin >> k;
                k=(bst.count(bst.root)-k)+1;
                int count = 0;
                int kthSmallestElement = bst.kthSmallest(bst.root, k, count);
                if (kthSmallestElement != -1) {
                    cout << "The kth smallest element is: " << kthSmallestElement << endl;
                } else {
                    cout << "Invalid value of k" << endl;
                }
                break;
        }
    }
}