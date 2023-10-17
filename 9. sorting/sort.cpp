#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int j = i - 1;
        int x = arr[i];
        while (j > -1 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

void selectionSort(int arr[], int n){
  int k,j;
  for(int i=0;i<n-1;i++){
        k=i;
    for(int j=i+1;j<n;j++){
      if(arr[j]<arr[k]){
        k=j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[k];
    arr[k] = temp;
  }
}

void ShellSort(int A[], int n) {
    int gap, i, j, temp;

    for (gap = n / 2; gap >= 1; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp) {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}

void merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    int B[10000];

    while (i <= mid && j <= h) {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];

    for (i = l; i <= h; i++)
        A[i] = B[i];
}

void MergeSort(int A[], int n) {
    int p, l, h, mid, i;

    for (p = 2; p <= n; p = p * 2) {
        for (i = 0; i + p <= n; i = i + p) {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }

        if (n - i > p / 2) {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, n - 1);
        }
    }

    if (p / 2 < n) {
        merge(A, 0, p / 2 - 1, n - 1);
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;
    while (1) {
        while (left <= right && arr[left] <= pivot)
            left = left + 1;
        while (arr[right] >= pivot && right >= left)
            right = right - 1;
        if (right < left)
            break;
        else
            swap(&arr[left], &arr[right]);
    }
    swap(&arr[low], &arr[right]);
    return right;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {

    for (int n=1000;n<=5000;n+=1000){

    ifstream inputFile("random_numbers.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the file for reading." << endl;
        return 1;
    }

    int arr_bubble[n];
    int arr_insertion[n];
    int arr_selection[n];
    int arr_shell[n];
    int arr_merge[n];
    int arr_quick[n];

    int index = 0;
    int num;
    while (inputFile >> num && index < n) {
        arr_bubble[index] = arr_insertion[index] = arr_selection[index] = arr_shell[index] = arr_merge[index] = arr_quick[index] = num;
        index++;
    }

    inputFile.close();

    auto start_bubble = chrono::high_resolution_clock::now();
    bubbleSort(arr_bubble, n);
    auto end_bubble = chrono::high_resolution_clock::now();
    auto duration2_bubble = chrono::duration_cast<chrono::milliseconds>(end_bubble - start_bubble);
    auto duration_bubble = chrono::duration_cast<chrono::microseconds>(end_bubble - start_bubble);


    auto start_insertion = chrono::high_resolution_clock::now();
    insertionSort(arr_insertion, n);
    auto end_insertion = chrono::high_resolution_clock::now();
    auto duration_insertion = chrono::duration_cast<chrono::microseconds>(end_insertion - start_insertion);
    auto duration2_insertion = chrono::duration_cast<chrono::milliseconds>(end_insertion - start_insertion);


    auto start_selection = chrono::high_resolution_clock::now();
    selectionSort(arr_selection, n);
    auto end_selection = chrono::high_resolution_clock::now();
    auto duration_selection = chrono::duration_cast<chrono::microseconds>(end_selection - start_selection);
    auto duration2_selection = chrono::duration_cast<chrono::milliseconds>(end_selection - start_selection);


    auto start_shell = chrono::high_resolution_clock::now();
    ShellSort(arr_shell, n);
    auto end_shell = chrono::high_resolution_clock::now();
    auto duration_shell = chrono::duration_cast<chrono::microseconds>(end_shell - start_shell);
    auto duration2_shell = chrono::duration_cast<chrono::milliseconds>(end_shell - start_shell);


    auto start_merge = chrono::high_resolution_clock::now();
    MergeSort(arr_merge, n);
    auto end_merge = chrono::high_resolution_clock::now();
    auto duration_merge = chrono::duration_cast<chrono::microseconds>(end_merge - start_merge);
    auto duration2_merge = chrono::duration_cast<chrono::milliseconds>(end_merge - start_merge);

    auto start_quick = chrono::high_resolution_clock::now();
    quickSort(arr_quick, 0, n-1);
    auto end_quick = chrono::high_resolution_clock::now();
    auto duration_quick = chrono::duration_cast<chrono::microseconds>(end_quick - start_quick);
    auto duration2_quick = chrono::duration_cast<chrono::milliseconds>(end_quick - start_quick);

    cout<<"when n="<<n<<":\n";

    cout << "Time in Milliseconds: " << endl <<endl;
    cout << "Time taken by bubble sort: " << duration2_bubble.count() << " milliseconds" << endl;
    cout << "Time taken by insertion sort: " << duration2_insertion.count() << " milliseconds" << endl;
    cout << "Time taken by selection sort: " << duration2_selection.count() << " milliseconds" << endl;
    cout << "Time taken by Shell sort: " << duration2_shell.count() << " milliseconds" << endl;
    cout << "Time taken by Merge sort: " << duration2_merge.count() << " milliseconds" << endl;
    cout << "Time taken by Quick sort: " << duration2_quick.count() << " milliseconds" << endl;

    cout << endl << endl << "Time in Microseconds: " << endl <<endl;
    cout << "Time taken by bubble sort: " << duration_bubble.count() << " microseconds" << endl;
    cout << "Time taken by insertion sort: " << duration_insertion.count() << " microseconds" << endl;
    cout << "Time taken by selection sort: " << duration_selection.count() << " microseconds" << endl;
    cout << "Time taken by Shell sort: " << duration_shell.count() << " microseconds" << endl;
    cout << "Time taken by Merge sort: " << duration_merge.count() << " microseconds" << endl;
    cout << "Time taken by Quick sort: " << duration_quick.count() << " microseconds" << endl << endl <<endl;


    ofstream outputFile("execution_times.txt",ios::app);

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open the file for writing." << endl;
        return 1;
    }

    outputFile << "For n = " << n << " :" << endl;
    outputFile << "Bubble Sort: " << duration_bubble.count() << " microseconds" << endl;
    outputFile << "Insertion Sort: " << duration_insertion.count() << " microseconds" << endl;
    outputFile << "Selection Sort: " << duration_selection.count() << " microseconds" << endl;
    outputFile << "Shell Sort: " << duration_shell.count() << " microseconds" << endl;
    outputFile << "Merge Sort: " << duration_merge.count() << " microseconds" << endl;
    outputFile << "Quick Sort: " << duration_quick.count() << " microseconds" << endl << endl ;

    outputFile.close();
    }

    return 0;
}