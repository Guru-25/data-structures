#include <iostream>
#define SIZE 10

using namespace std;

void Print(int* vec, int n, string s) {
    cout << s << ":" << endl;
    for (int i = 0; i < n; i++) {
        if (vec[i] != 0) {
            cout << i << " - " << (vec[i] ==0 ? "-" : to_string(vec[i]))<< endl;
        } else {
            cout << i << " - -" << endl;
        }
    }
}

int Hash(int key) {
    return key % SIZE;
}

int LinearProbe(int H[], int key) {
    int index = Hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != 0) {
        i++;
    }
    return (index + i) % SIZE;
}

void Insert(int H[], int key) {
    int index = Hash(key);

    if (H[index] != 0) {
        index = LinearProbe(H, key);
    }
    H[index] = key;
}

int Search(int H[], int key) {
    int index = Hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != key) {
        i++;
    }
    return (index + i) % SIZE;
}

void Delete(int H[], int key) {
    int index = Search(H, key);
    if (index != 0) {
        H[index] = 0; // Mark as deleted
        cout << "Key " << key << " deleted." << endl;
    } else {
        cout << "Key not found. Deletion failed." << endl;
    }
}

void twoSum(int A[], int n, int target) {
    int HT[SIZE] = {0};
    for (int i = 0; i < n; i++) {
        if(A[i] != 0){
            int complement = target - A[i];
            int index = Search(HT, complement);
            if (index != 0 && complement != 0) {
                cout << "Pair: " << A[i] << ", " << complement << endl;
            }
            Insert(HT, A[i]);
        }
    }
}

int main() {
    int option;
    int key;
    int HT[SIZE] = {0};
    int index;

    while (true) {
        cout << "1 for insert" << endl;
        cout << "2 for search" << endl;
        cout << "3 for two-sum" << endl;
        cout << "4 for delete" << endl;
        cout << "enter choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "enter the value to insert: ";
                cin >> key;
                Insert(HT, key);
                Print(HT, SIZE, "HT");
                break;
            case 2:
                cout << "enter the value to search: ";
                cin >> key;
                index = Search(HT, key);
                if (index != -1) {
                    cout << "key found at: " << index << endl;
                } else {
                    cout << "key not found" << endl;
                }
                break;
            case 3:
                int target;
                cout << "enter the target value for two-sum: ";
                cin >> target;
                twoSum(HT, SIZE, target);
                break;
            case 4:
                cout << "enter the value to delete: ";
                cin >> key;
                Delete(HT, key);
                Print(HT, SIZE, "HT");
                break;
            default:
                cout << "invalid option" << endl;
        }
    }

    return 0;
}
