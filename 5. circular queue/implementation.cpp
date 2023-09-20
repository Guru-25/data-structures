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
    int size,choice,x;
    cout<<"size of queue: ";
    cin >> size;
    Queue q(size+1);
    do{
        cout<<"-----\n1 for enqueue\n2 for dequeue\n3 for is empty\n4 for is full\n5 for front element\n6 for rear element\n7 for exit\nenter a choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout << "enter element: ";
                cin >> x;
                q.enqueue(x);
                q.display();
                break;
            case 2:
                cout << "element " << q.dequeue() << " was dequeued"<<endl;
                q.display();
                break;
            case 3:
                cout<<"is empty: " << q.isEmpty()<<endl;
                break;
            case 4:
                cout<<"is full: " << q.isFull()<<endl;
                break;
            case 5:
                cout<<"front element: " << q.frontQ()<<endl;
                break;
            case 6:
                cout<<"rear element: " << q.rearQ()<<endl;
                break;
        }
    } while (choice!=7);
}