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
        front = 0;
        rear = 0;
        this->size = size;
        Q = new int[size];
    }
    void enqueue(int x) {
        if(isFull())
            cout << "Queue is full" << endl;
        else {
            rear = (rear + 1) % size;
            Q[rear] = x;
        }
    }
    int dequeue() {
        int x = -1;
        if(isEmpty())
            cout << "Queue is empty" << endl;
        else {
            front = (front + 1) % size;
            x = Q[front];
        }
        return x;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            int i = front + 1;
            while (i != (rear + 1) % size) {
                if(Q[i] == 0) {
                    cout << 1 << " ";
                } else {
                    cout << Q[i] << " ";
                }
                i = (i + 1) % size;
            }
            cout << endl;
        }
    }

    int isFull() {
        return (rear + 1) % size == front;
    }

    int isEmpty() {
        return front == rear;
    }

    int first() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return Q[(front + 1) % size];
    }

    int last() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; 
        }
        return Q[rear];
    }
    int Qsize() {
        if (isEmpty()) {
            return 0;
        } else {
            return (rear - front + size) % size;
        }
    }
};

int main() {
    int n, k;
    cout << "enter no of people: ";
    cin >> n;
    cout << "enter the value of k: ";
    cin >> k;

    Queue q(n + 1);

    for (int i = 1; i <= n; i++) {
        q.enqueue(i);
    }
    q.display();

    while (!q.isEmpty()) {
        for (int i = 0; i < k - 1; i++) {
            int temp = q.dequeue();
            q.enqueue(temp);
        }
        int eliminated = q.dequeue();
        cout << eliminated << " is eliminted" << endl;
        q.display();

        if (q.Qsize() == 1) {
            break;
        }
    }
    cout << "the winner is: " << q.first() << endl;
}