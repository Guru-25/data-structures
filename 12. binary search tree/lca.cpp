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
        root = nullptr;
    }

    // Function to create a new node
    Node* createNode(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    // Function to insert a node into the BST
    Node* insert(Node* current, int data) {
        if (current == nullptr)
            return createNode(data);

        if (data < current->data)
            current->left = insert(current->left, data);
        else if (data > current->data)
            current->right = insert(current->right, data);

        return current;
    }

    // Function to find the LCA of two nodes in the BST
    Node* findLCA(Node* p, int n1, int n2) {
        if (p == NULL)
            return nullptr;

        if (n1 < p->data && n2 < p->data)
            return findLCA(p->left, n1, n2);
        else if (n1 > p->data && n2 > p->data)
            return findLCA(p->right, n1, n2);

        return p;
    }

    // Function to print the BST in inorder (ascending) order
    void inorderTraversal(Node* current) {
        if (current != nullptr) {
            inorderTraversal(current->left);
            cout << current->data << " ";
            inorderTraversal(current->right);
        }
    }
};

int main() {
    BST bst;
    int choice, data;

    Node* lca = nullptr;  // Moved the declaration outside the switch

    while (1) {
        cout << "\n1. Insert\n2. Print\n3. Find LCA\n4. Exit\n";
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
                int n1, n2;
                cout << "Enter two nodes to find their LCA: ";
                cin >> n1 >> n2;
                lca = bst.findLCA(bst.root, n1, n2);
                if (lca)
                    cout << "Lowest Common Ancestor: " << lca->data << endl;
                else
                    cout << "Nodes not found or no common ancestor." << endl;
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}