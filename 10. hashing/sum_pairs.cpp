#include <iostream>
#define SIZE 10
#define PRIME 7

using namespace std;

void Print(int* vec, int n, string s) {
    cout << s << ":" << endl;
    for (int i = 0; i < n; i++) {
        if (vec[i] != 0) {
            cout << vec[i] << endl;
        } else {
            cout << "-" << endl;
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

void twoSum(int A[], int n, int target) {
    int HT[SIZE] = {0};
    for (int i = 0; i < n; i++) {
        int complement = target - A[i];
        int index = Search(HT, complement);
        if (index != -1) {
            cout << "Pair: " << A[i] << ", " << complement << endl;
        }
        Insert(HT, A[i]);
    }
}

int main() {
    int n, target;
    cout << "enter n: ";
    cin >> n;
    int A[n];
    cout << "enter numbers: ";
    for(int i = 0;i < n;i++) {
        cin >> A[i];
    }

    cout << "enter target: ";
    cin >> target;

    cout << "pairs that sum to " << target << ":" << endl;
    twoSum(A, n, target);

    return 0;
}