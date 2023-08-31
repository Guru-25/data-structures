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
        front++;
        return Q[front];
    }

    int last() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; 
        }
        return Q[rear];
    }
};

int main() {
    int size, x;
    cout << "size of queue: ";
    cin >> size;
    Queue ogQueue(size);
    Queue posQueue(size);
    Queue negQueue(size);
    Queue newQueue(size);
    cout << "enter values: ";
    for(int i = 0; i<size;i++) {
        cin >> x;
        ogQueue.enqueue(x);
    }
    
    while (!ogQueue.isEmpty()) {
        int e = ogQueue.dequeue();
        if (e >= 0) {
            posQueue.enqueue(e);
        } else {
            negQueue.enqueue(e);
        }
    }

    cout << "positive queue: ";
    posQueue.display();
    
    cout << "negative queue: ";
    negQueue.display();

    
    while (!posQueue.isEmpty()) {
        newQueue.enqueue(posQueue.dequeue());
    }

    while (!negQueue.isEmpty()) {
        newQueue.enqueue(negQueue.dequeue());
    }

    cout << "merged queue: ";
    newQueue.display();

    return 0;
}
