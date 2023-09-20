#include <iostream>
using namespace std;

class Queue{
private:
    int front; 
    int rear;
    int* Q;
    int size;
public:
    Queue(int size){
        front=0;
        rear=0;
        this->size=size;
        Q = new int[size];
    }
    int enqueue(int x){
        if(isFull()){
            cout << "queue is full";
        }
        else{
            rear=(rear+1)%size;
            Q[rear] = x;
        }
    }
    int dequeue(){
        int x=-1;
        if(isEmpty()){
            cout << "queue is empty";
        }
        else{
            front=(front+1)%size;
            x=Q[front];
        }
        return x;
    }
    int isFull(){
        return (rear+1)%size==front;
    }
    int isEmpty(){
        return front==rear;
    }
    int frontQ(){
        int x=-1;
        if(isEmpty()){
            cout << "queue is empty";
        }
        else{
            x=Q[(front+1)%size];
        }
        return x;
    }
    int rearQ(){
        int x=-1;
        if(isEmpty()){
            cout << "queue is empty";
        }
        else{
            x=Q[rear];
        }
        return x;
    }
    void display() {
        if (isEmpty()) {
            cout << endl;
        } else {
            int i = front + 1;
            do {
                cout << Q[i] << " ";
                i = (i + 1) % size;
            } while (i != (rear + 1) % size);
            cout << endl;
        }
    }
};

int main(){
    int tot,n,last,start_position,i;
    cout << "enter total disks: ";
    cin>>tot;
    cout <<"enter the number of disks: ";
    cin>>n;
    last=tot-1;
    int disks[n];
    Queue q1(n+2);
    Queue q2(n+1);
    cout <<"enter the disks: ";
    for(i=0;i<n;i++){
        cin >> disks[i];
    }
    for(i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(disks[i]>disks[j]){
                int temp=disks[i];
                disks[i]=disks[j];
                disks[j]=temp;
            }
        }
    }
    cout<<"enter starting disk: ";
    cin >> start_position;

    for(i=0;i<n;i++){
        if(disks[i]>=start_position){
            q1.enqueue(disks[i]);
        }
        else{
            q2.enqueue(disks[i]);
        }
    }
    q1.enqueue(last);
    int total=0;
    int current=start_position;
    while(!q1.isEmpty()){
        int e=q1.dequeue();
        cout<<"disk was moved to "<<e<<endl;
        total= total + e-current;
        current=e;
    }
    cout<<"disk was moved to 0"<<endl;
    current=0;
    while(!q2.isEmpty()){
        int e=q2.dequeue();
        cout<<"disk was moved to "<<e<<endl;
        total= total + e-current;
        current=e;
    }
    cout<<"total distance is: "<<total<<endl;
}