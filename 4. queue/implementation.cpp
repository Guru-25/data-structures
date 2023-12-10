#include <iostream>

using namespace std;

class Queue {
private:
    int front;
    int rear;
    int size;
    int* Q;
public:
    Queue(int size) {
        front = -1;
        rear = -1;
        this->size = size;
        Q = new int[size];
    }
    void enqueue(int x) {
        if(isFull())
            cout << "Queue is full" << endl;
        else {
            rear++;
            Q[rear] = x;
        }
    }
    int dequeue() {
        int x = -1;
        if(isEmpty())
            cout << "Queue is empty" << endl;
        else {
            front++;
            x = Q[front];
        }
        return x;
    }
    void display() {
        for(int i = front + 1; i <= rear; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    }

    int isFull() {
        return rear == size - 1;
    }

    int isEmpty() {
        return front == rear;
    }

    int first() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; 
        }
        return Q[front+1];
    }

    int last() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; 
        }
        return Q[rear];
    }
    
    ~Queue() {
        delete[] Q;
    }
};

int main() {
    int size, choice, x;
    cout << "enter size: ";
    cin >> size;
    Queue q(size);
    do {
        cout << "-----\n1 for enqueue\n2 for dequeue\n3 for display\n4 for is full\n5 for is empty\n6 for first element\n7 for last element\n8 for exit\n\nenter choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "before enqueue:" << endl;
                q.display();
                cout << "enter element: ";
                cin >> x;
                q.enqueue(x);
                cout << "after enqueue:" << endl;
                q.display();
                break;
            case 2:
                cout << "before dequeue:" << endl;
                q.display();
                q.dequeue();
                cout << "after dequeue:" << endl;
                q.display();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "is full: " << q.isFull() << endl;
                break;
            case 5:
                cout << "is empty: " << q.isEmpty() << endl;
                break;
            case 6:
                cout << "first element: " << q.first() << endl;
                break;
            case 7:
                cout << "last element: " << q.last() << endl;
                break;
            case 8:
                break;
        }
    } while(choice != 8);
}