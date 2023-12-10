#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* createNode(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    Node* insert(Node* current, int data) {
        if (current == NULL)
            return createNode(data);

        if (data < current->data)
            current->left = insert(current->left, data);
        else if (data > current->data)
            current->right = insert(current->right, data);

        return current;
    }

    Node* search(Node* current, int key) {
        if (current == NULL || current->data == key)
            return current;

        if (key < current->data)
            return search(current->left, key);
        return search(current->right, key);
    }

    int findLargestInLeftSubtree(Node* current) {
        if (current->right == nullptr)
            return current->data;
        return findLargestInLeftSubtree(current->right);
    }
    Node* deleteNode(Node* current, int key) {
        if (current == NULL)
            return current;

        if (key < current->data)
            current->left = deleteNode(current->left, key);
        else if (key > current->data)
            current->right = deleteNode(current->right, key);
        else {
            if (current->left == NULL) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == NULL) {
                Node* temp = current->left;
                delete current;
                return temp;
            }

            current->data = findLargestInLeftSubtree(current->left);
            current->left = deleteNode(current->left, current->data);
        }
        return current;
    }

    void inorderTraversal(Node* current) {
        if (current != NULL) {
            inorderTraversal(current->left);
            cout << current->data << " ";
            inorderTraversal(current->right);
        }
    }

    Node* findLCA(Node* current, int n1, int n2) {
        if (current == nullptr)
            return nullptr;

        if (n1 < current->data && n2 < current->data)
            return findLCA(current->left, n1, n2);
        else if (n1 > current->data && n2 > current->data)
            return findLCA(current->right, n1, n2);

        return current;
    }
};

int main() {
    BST bst;
    int choice, data;
    Node* lca = NULL; 

    while (1) {
        cout << "\n1 for insert\n2 for search\n3 for delete\n4 for least common ancestor\n";
        cout << "enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                bst.root = bst.insert(bst.root, data);
                bst.inorderTraversal(bst.root);
                cout << endl;
                break;
            case 2:
                cout << "Enter element to search: ";
                cin >> data;
                if (bst.search(bst.root, data))
                    cout << "Element found in the BST." << endl;
                else
                    cout << "Element not found in the BST." << endl;
                break;
            case 3:
                cout << "Enter element to delete: ";
                cin >> data;
                bst.root = bst.deleteNode(bst.root, data);
                cout << "element " << data << " was deleted" << endl;
                bst.inorderTraversal(bst.root);
                cout << endl;
                break;
            case 4:
                int n1, n2;
                cout << "Enter two nodes to find their LCA: ";
                cin >> n1 >> n2;
                lca = bst.findLCA(bst.root, n1, n2);
                if (lca)
                    cout << "Lowest Common Ancestor: " << lca->data << endl;
                else
                    cout << "Nodes not found or no common ancestor." << endl;
                break;
            default:
                cout << "invalid" << endl;
        }
    }

    return 0;
}