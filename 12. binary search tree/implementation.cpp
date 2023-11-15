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

    // Function to print the BST in inorder (ascending) order
    void inorderTraversal(Node* current) {
        if (current != nullptr) {
            inorderTraversal(current->left);
            cout << current->data << " ";
            inorderTraversal(current->right);
        }
    }

    // Function to find the largest element in the BST
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

    // Function to find the largest element in the left subtree
    int findLargestInLeftSubtree(Node* current) {
        if (current->right == nullptr)
            return current->data;
        return findLargestInLeftSubtree(current->right);
    }

    // Function to find the smallest element in the right subtree
    int findSmallestInRightSubtree(Node* current) {
        if (current->left == nullptr)
            return current->data;
        return findSmallestInRightSubtree(current->left);
    }

    // Function to search for an element in the BST
    Node* search(Node* current, int key) {
        if (current == nullptr || current->data == key)
            return current;

        if (key < current->data)
            return search(current->left, key);
        return search(current->right, key);
    }

    // Function to delete a node with a given data
    Node* deleteNode(Node* current, int key) {
        if (current == nullptr)
            return current;

        if (key < current->data)
            current->left = deleteNode(current->left, key);
        else if (key > current->data)
            current->right = deleteNode(current->right, key);
        else {
            if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                return temp;
            }

            current->data = findLargestInLeftSubtree(current->left);
            current->left = deleteNode(current->left, current->data);
        }
        return current;
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