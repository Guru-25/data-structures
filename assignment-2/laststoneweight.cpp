#include <iostream>

#define MAX_HEAP_SIZE 100

using namespace std;

class MaxHeap {
public:
    int heapArray[MAX_HEAP_SIZE];
    int size;

    MaxHeap() {
        size = 0;
    }

    void insertMax(int value) {
        if (size >= MAX_HEAP_SIZE) {
            cout << "Heap is full, cannot insert." << endl;
            return;
        }

        int i = ++(size);
        heapArray[i] = value;

        while (i != 1 && heapArray[i / 2] < heapArray[i]) {
            swap(heapArray[i], heapArray[i / 2]);
            i = i / 2;
        }
    }

    int deleteMax() {
        if (size == 0) {
            cout << "Heap is empty, cannot delete." << endl;
            return -1;
        }

        int root = heapArray[1];
        heapArray[1] = heapArray[size];
        size--;

        int i = 1;
        int left, right, largest;

        while (true) {
            left = 2 * i;
            right = 2 * i + 1;
            largest = i;

            if (left <= size && heapArray[left] > heapArray[largest]) {
                largest = left;
            }
            if (right <= size && heapArray[right] > heapArray[largest]) {
                largest = right;
            }

            if (largest == i) {
                break;
            }

            swap(heapArray[i], heapArray[largest]);
            i = largest;
        }

        return root;
    }
};

int lastStoneWeight(int stones[], int n) {
    if (n == 0) return 0;
    MaxHeap heap;
    for (int i = 0; i < n; i++) {
        heap.insertMax(stones[i]);
    }
    while (heap.size > 1) {
        int s1 = heap.deleteMax();
        int s2 = heap.deleteMax();
        if (s1 != s2) {
            heap.insertMax(s1 - s2);
        }
    }
    return (heap.size == 0) ? 0 : heap.deleteMax();
}

int main() {
    int n;

    cout << "enter no of stones: ";
    cin >> n;
    int arr[n];
    cout << "enter the stones: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "last stone weight: " << lastStoneWeight(arr, n) << endl;

    return 0;
}