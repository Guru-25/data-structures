#include <iostream>

using namespace std;

// Define the structure for a binary search tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Class for Binary Search Tree
class BST {
public:
    Node* root;

    // Constructor to initialize an empty BST
    BST() {
        root = NULL;
    }

    Node* search(Node* p, int key) {
        if(p==NULL){
            return p;
        }
        if(key == p->data){
            return p;
        }
        else if(key < p->data){
            search(p->left,key);
        }
        else{
            search(p->right,key);
        }
        return p;
    }

    Node* insert(Node* p, int key) {
        Node* t;
        if(p==NULL){
            t=new Node;
            t->data=key;
            t->left=NULL;
            t->right=NULL;
            return t;
        }

        if(key<p->data){
            p->left=insert(p->left,key);
        }
        else if(key > p->data){
            p->right=insert(p->right,key);
        }

        return p; // if key==data
    }

    void inorderTraversal(Node* p) {
        if (p) {
            inorderTraversal(p->left);
            cout << p->data << " ";
            inorderTraversal(p->right);
        }
    }

    int findLargestInLeftSubtree(Node* p) {
        if (p->right == NULL)
            return p->data;
        return findLargestInLeftSubtree(p->right);
    }

    Node* deleteNode(Node* p, int key) {
        if (p == NULL)
            return p;

        if (key < p->data)
            p->left = deleteNode(p->left, key);
        else if (key > p->data)
            p->right = deleteNode(p->right, key);
        else {
            if (p->left == NULL) {
                Node* temp = p->right;
                delete p;
                return temp;
            }
            else if (p->right == NULL) {
                Node* temp = p->left;
                delete p;
                return temp;
            }

            p->data = findLargestInLeftSubtree(p->left);
            p->left = deleteNode(p->left, p->data);
        }
        return p;
    }

    int findLargest(Node* current) {
        if (current == nullptr) {
            cout << "BST is empty" << endl;
            return -1;
        }
        while (current->right != nullptr)
            current = current->right;
        return current->data;
    }

    // Function to find the smallest element in the BST
    int findSmallest(Node* current) {
        if (current == nullptr) {
            cout << "BST is empty" << endl;
            return -1;
        }
        while (current->left != nullptr)
            current = current->left;
        return current->data;
    }

    // Function to find the smallest element in the right subtree
    int findSmallestInRightSubtree(Node* current) {
        if (current->left == nullptr)
            return current->data;
        return findSmallestInRightSubtree(current->left);
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

};

int main() {
    BST bst;
    int choice, data;

    while (1) {
        cout << "\n1. Insert\n2. Print\n3. Find Largest\n4. Find Smallest\n5. Find Largest in Left Subtree\n6. Find Smallest in Right Subtree\n7. Search\n8. Delete\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                bst.root = bst.insert(bst.root, data);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                bst.inorderTraversal(bst.root);
                cout << endl;
                break;
            case 3:
                cout << "Largest element: " << bst.findLargest(bst.root) << endl;
                break;
            case 4:
                cout << "Smallest element: " << bst.findSmallest(bst.root) << endl;
                break;
            case 5:
                cout << "Largest in Left Subtree: " << bst.findLargestInLeftSubtree(bst.root->left) << endl;
                break;
            case 6:
                cout << "Smallest in Right Subtree: " << bst.findSmallestInRightSubtree(bst.root->right) << endl;
                break;
            case 7:
                cout << "Enter element to search: ";
                cin >> data;
                if (bst.search(bst.root, data))
                    cout << "Element found in the BST." << endl;
                else
                    cout << "Element not found in the BST." << endl;
                break;
            case 8:
                cout << "Enter element to delete: ";
                cin >> data;
                bst.root = bst.deleteNode(bst.root, data);
                break;
            case 9:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}