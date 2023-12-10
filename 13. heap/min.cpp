#include <iostream>

using namespace std;

void insert(int A[], int n) {
    int i, temp;
    i = n;
    temp = A[i];
    while (i > 1 && temp < A[i / 2]) {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

int del(int A[], int n) {
    int i, j, val;
    val = A[1];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = 2 * i;
    while (j < n - 1) {
        if (A[j + 1] < A[j]) {
            j = j + 1;
        }
        if (A[i] > A[j]) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        } else {
            break;
        }
    }
    return val;
}

void displayHeap(int heap[], int size) {
    cout << "Heap: ";
    for (int i = 1; i <= size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int heap[100]; // Assuming a maximum heap size of 100
    int size = 0;
    int arr[100];
    int newsize,s;
   // int heap[] = {0, 10, 20, 30, 25,5,40,35};
    int choice, value;

    while (true) {
        cout << "1. Insert element\n2. Delete element\n3. Display\n4. Sort\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                size++;
                heap[size] = value;
                insert(heap, size);
                displayHeap(heap, size);
                break;
            case 2:
                if (size == 0) {
                    cout << "Heap is empty. Cannot delete." << endl;
                } else {
                    int deletedValue = del(heap, size);
                    size--;
                    cout << "Deleted element: " << deletedValue << endl;
                    displayHeap(heap, size);
                }
                break;
            case 3:
                displayHeap(heap, size);
                break;
            case 4:
                newsize = size;
                s = 0;
                for (int i = size; i >= 1; i--) {
                    arr[s] = del(heap, i);
                    s++;
                }
                for (int i = newsize - 1; i >= 0; i--) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
