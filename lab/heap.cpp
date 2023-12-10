#include<iostream>

using namespace std;

void insert(int H[], int n){
    int temp,i;
    i=n;
    temp=H[i];
    while(i>1 && temp>H[i/2]){
        H[i]=H[i/2];
        i=i/2;
    }
    H[i]=temp;
}
int findmax(int H[], int n){
    return H[1];
}
int del(int H[], int n){
    int i,j,val;
    val=H[1];
    H[1]=H[n];
    i=1;
    j=2*i;
    while(j<n-1){
        if(H[j+1]>H[j]){
            j=j+1;
        }
        if(H[i]<H[j]){
            int temp=H[i];
            H[i]=H[j];
            H[j]=temp;
            i=j;
            j=2*j;
        }
        else{
            break;
        }
    }
    return val;
}

void print(int H[], int n){
    for(int i=1;i<=n;i++){
        cout<<H[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int H[100];
    int arr[100];
    int newsize, s;
    int choice,x;
    int n=0;
    while(true){
        cout<<"1 insert\n2 find max\n3 delete\n4 for sort\nchoice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter: ";
                cin>>x;
                n++;
                H[n]=x;
                insert(H,n);
                print(H,n);
                break;
            case 2:
                cout<<"max is: "<<findmax(H,n)<<endl;
                break;
            case 3:
                cout <<"element " <<del(H,n)<< " was deleted"<<endl;
                n--;
                print(H,n);
                break;
            case 4:
                newsize=n;
                s=0;
                for(int i=n;i>=1;i--){
                    arr[s]=del(H,i);
                    s++;
                }
                // for(int i=newsize-1;i>=0;i--){
                //     cout << arr[i]<<" ";
                // }
                for(int i=0;i<=newsize-1;i++){
                    cout << arr[i]<<" ";
                }
                cout <<endl;
        }
    }
}