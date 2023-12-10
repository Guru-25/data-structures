#include <iostream>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int data) {
        val = data;
        left = right = nullptr;
    }
};

void insert(TreeNode **root, int val) {
    if (*root == nullptr) {
        *root = new TreeNode(val);
        return;
    }

    if (val < (*root)->val) {
        insert(&((*root)->left), val);
    } else {
        insert(&((*root)->right), val);
    }
}

TreeNode *make_tree(int arr[], int n) {
    TreeNode *root = nullptr;
    for (int i = 0; i < n; i++) {
        insert(&root, arr[i]);
    }
    return root;
}

const int INF = -1e8;

class Solution {
public:
    void printData(pair<int, int> t) {
        cout << t.first << " " << t.second << endl;
    }

    pair<int, int> solve(TreeNode *node) {
        if (!node) {
            return {0, 0};
        }

        pair<int, int> leftVal = solve(node->left);
        pair<int, int> rightVal = solve(node->right);

        int withRoot = node->val + leftVal.second + rightVal.second;
        int withoutRoot = max(leftVal.first + rightVal.first, leftVal.second + rightVal.second);

        return {withRoot, withoutRoot};
    }

    int rob(TreeNode *root) {
        pair<int, int> a = solve(root);
        return max(a.first, a.second);
    }
};

int main() {
    Solution ob;
    int n;

    cout << "enter no of houses: ";
    cin >> n;
    int arr[n];
    cout << "enter the houses: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    TreeNode *root = make_tree(arr, n);

    cout << "maximum amount that can be robbed: " << ob.rob(root) << endl;
}
