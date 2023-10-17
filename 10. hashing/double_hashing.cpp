#include <iostream>
#define SIZE 10
#define PRIME 7

using namespace std;

void Print(int* vec, int n, string s) {
    cout << s << ":" << endl;
    for (int i = 0; i < n; i++) {
        if (vec[i] != 0) {
            cout << i << " - " << vec[i] << endl;
        } else {
            cout << i << " - -" << endl;
        }
    }
}

int Hash(int key) {
    return key % SIZE;
}

int PrimeHash(int key) {
    return PRIME - (key % PRIME);
}

int DoubleHash(int H[], int key) {
    int idx = Hash(key);
    int i = 0;
    while (H[(idx + i * PrimeHash(key)) % SIZE] != 0) {
        i++;
    }
    return (idx + i * PrimeHash(key)) % SIZE;
}

void Insert(int H[], int key) {
    int idx = Hash(key);

    if (H[idx] != 0) {
        idx = DoubleHash(H, key);
    }
    H[idx] = key;
}

int Search(int H[], int key) {
    int idx = Hash(key);
    int i = 0;
    while (H[(idx + i * PrimeHash(key)) % SIZE] != key) {
        i++;
        if (H[(idx + i * PrimeHash(key)) % SIZE] == 0) {
            return -1;
        }
    }
    return (idx + i * PrimeHash(key)) % SIZE;
}

float LoadFactor(int H[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (H[i] != 0) {
            count++;
        }
    }
    return static_cast<float>(count) / size;
}

int main() {
    int HT[SIZE] = {0};
    int option, key;
    int index;

    while (true) {
        cout << "1 for insert" << endl;
        cout << "2 for search" << endl;
        cout << "3 for load factor" << endl;
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
                cout << "load factor: " << LoadFactor(HT, SIZE) << endl;
                break;

            default:
                cout << "invalid option" << endl;
        }
    }
}