#include <iostream>
#include <set>
#include <algorithm> // For std::max_element, std::min_element

using namespace std;

// Class for Binary Search Tree
class BST {
public:
    set<int> bstSet;

    // Function to insert a node into the BST
    void insert(int data) {
        bstSet.insert(data);
    }

    // Function to print the BST in inorder (ascending) order
    void inorderTraversal() {
        cout << "In-order BST traversal: ";
        for (const auto& elem : bstSet) {
            cout << elem << " ";
        }
        cout << endl;
    }

    // Function to find the largest element in the BST
    int findLargest() {
        if (bstSet.empty()) {
            cout << "BST is empty" << endl;
            return -1;
        }
        return *std::max_element(bstSet.begin(), bstSet.end());
    }

    // Function to find the smallest element in the BST
    int findSmallest() {
        if (bstSet.empty()) {
            cout << "BST is empty" << endl;
            return -1;
        }
        return *std::min_element(bstSet.begin(), bstSet.end());
    }

    // Function to find the largest element in the left subtree
    int findLargestInLeftSubtree() {
        if (bstSet.empty()) {
            cout << "BST is empty" << endl;
            return -1;
        }
        auto leftMaxIterator = std::max_element(bstSet.begin(), bstSet.lower_bound(*bstSet.begin()));
        return *leftMaxIterator;
    }

    // Function to find the smallest element in the right subtree
    int findSmallestInRightSubtree() {
        if (bstSet.empty()) {
            cout << "BST is empty" << endl;
            return -1;
        }
        auto rightMinIterator = std::min_element(bstSet.upper_bound(*bstSet.rbegin()), bstSet.end());
        return *rightMinIterator;
    }

    // Function to search for an element in the BST
    bool search(int key) {
        return bstSet.find(key) != bstSet.end();
    }

    // Function to delete a node with a given data
    void deleteNode(int key) {
        auto it = bstSet.find(key);
        if (it != bstSet.end()) {
            bstSet.erase(it);
        }
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
                bst.insert(data);
                break;
            case 2:
                bst.inorderTraversal();
                break;
            case 3:
                cout << "Largest element: " << bst.findLargest() << endl;
                break;
            case 4:
                cout << "Smallest element: " << bst.findSmallest() << endl;
                break;
            case 5:
                cout << "Largest in Left Subtree: " << bst.findLargestInLeftSubtree() << endl;
                break;
            case 6:
                cout << "Smallest in Right Subtree: " << bst.findSmallestInRightSubtree() << endl;
                break;
            case 7:
                cout << "Enter element to search: ";
                cin >> data;
                if (bst.search(data))
                    cout << "Element found in the BST." << endl;
                else
                    cout << "Element not found in the BST." << endl;
                break;
            case 8:
                cout << "Enter element to delete: ";
                cin >> data;
                bst.deleteNode(data);
                break;
            case 9:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
