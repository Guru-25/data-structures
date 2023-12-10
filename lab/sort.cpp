#include<iostream>

using namespace std;

int search(int A[], int n, int target){
    for(int i=0;i<n;i++){
        if(target==A[i]){
            return i;
        }
    }
    return -1;
}

int binary(int A[],int n,int target){
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(A[mid] == target){
            return mid;
        } else if(A[mid]<target){
            low = mid+1;
        } else{
            high=mid-1;
        }
    }
    return -1;
}

void bubble(int A[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}

void insertion(int A[],int n){
    for(int i=0;i<n;i++){
        int j=i-1;
        int x=A[i]; // carefull
        while(j>-1 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

void selection(int A[], int n){
    int i, k,j;
    for(i=0;i<n-1;i++){
        k=i;
        for(j=i+1;j<n;j++){ //i+1
            if(A[j] <A[k]){ //
                k=j; //
            }
        }
        int temp=A[i];
        A[i]=A[k];
        A[k]=temp;
    }
}

void shell(int A[], int n){
    int gap, temp, j;
    for(gap=n/2;gap>=1;gap/=2){ //>=1
        for(int i=gap;i<n;i++){ // < n
            temp=A[i];
            j=i-gap;
            while(j>=0 && A[j]> temp){
                A[j+gap]=A[j]; // A[j+gap] not A[j+1]
                j=j-gap;
            }
            A[j+gap]=temp;
        }
    }
}

void print(int A[], int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n=5;
    int A[n]={3,2,4,1,7};
    // cout<< search(A,n, 7)<< endl;
    cout<< binary(A,n, 7)<< endl;
    // bubble(A,n);
    // insertion(A,n);
    // selection(A,n);
    // shell(A,n);
    // print(A,n);
    return 0;
}