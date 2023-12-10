#include<iostream>
#define SIZE 10

using namespace std;

int Hash(int key){ // H
    return key%SIZE;
}
int linear(int H[], int key){
    int index=Hash(key);
    int i=0;
    while(H[(index+i)%SIZE] != -1 && H[(index+i)%SIZE] != 0){
        i++;
    }
    return (index+i)%SIZE;
}
void insert(int H[], int key){
    int index=Hash(key);
    if(H[index]==-1){
        H[index]=key;
    }
    index=linear(H,key);
}
int search(int H[], int key){
    int index=Hash(key);
    int i=0;
    while(H[(index+i)%SIZE] != key){
        i++;
        if(H[(index+i)%SIZE] ==0){
            return -1;
        }
    }
    return (index+i)%SIZE;
}
void del(int H[], int key){
    int index=search(H,key);
    if(index==-1){
        cout<<"nothing to delete"<<endl;
    }
    else{
        H[index]=-1;
    }
}
void print(int H[]){
    for(int i=0;i<SIZE;i++){
        if(H[i]==-1){
            cout << i << " - -"<<endl;
        }
        else{
            cout<<i<< " - "<< (H[i]==0?"-":to_string(H[i]))<<endl;
        }
    }
}
void twopair(int A[],int target){
    int H[SIZE]={0};
    for(int i=0;i<SIZE;i++){
        if(A[i]!=0){
            int complement=target-A[i];
            int index=search(H,complement);
            if(index!=-1 && complement!=0){
                cout << "Pair: "<< A[i]<<", "<<complement<<endl;
            }
            insert(H,A[i]);
        }
    }
}

int main(){
    int choice,x,temp,target;
    int H[SIZE]={-1};
    while(true){
        cout<<"1 ins\n2 sear\n3 del\n4 two pair\nchoice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter: ";
                cin>>x;
                insert(H,x);
                print(H);
                break;
            case 2:
                cout<<"enter: ";
                cin>>x;
                temp=search(H,x);
                if(temp!=-1){
                    cout<<"found at index "<<temp<<endl;
                }
                else{
                    cout<<"not found"<<endl;
                }
                break;
            case 3:
                cout<<"enter: ";
                cin>>x;
                del(H,x);
                print(H);
                break;
            case 4:
                cout<<"enter target: ";
                cin>>target;
                twopair(H,target);
        }
    }
}