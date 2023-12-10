#include <iostream>

using namespace std;

class Node {
public:
    int item;
    Node* next;
};

class CircularLinkedListQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularLinkedListQueue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->item = value;
        newNode->next = NULL;
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front; // Make it circular
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Make it circular
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; // Return a sentinel value
        } else {
            int value = front->item;
            if (front == rear) {
                delete front;
                front = rear = NULL;
            } else {
                Node* temp = front;
                front = front->next;
                rear->next = front; // Update the rear to point to the new front (circular)
                delete temp;
            }
            return value;
        }
    }

    int firstElement() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; // Return a sentinel value or throw an exception
        } else {
            return front->item;
        }
    }

    int rearElement() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; // Return a sentinel value or throw an exception
        } else {
            return rear->item;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Queue: ";
        do {
            cout << current->item << " ";
            current = current->next;
        } while (current != front);
        cout << endl;
    }
};

int main() {
    CircularLinkedListQueue queue;

    int choice, x;
    const int maxLimit = 5; // Set a maximum limit for the queue
    do {
        cout << "-----\n1 for enqueue\n2 for dequeue\n3 for display\n4 for firstElement\n5 for rearElement\n6 for exit\n\nenter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> x;
                queue.enqueue(x);
                queue.display();
                break;
            case 2:
                x = queue.dequeue();
                if (x != -1) {
                    cout << "Dequeued element: " << x << endl;
                    queue.display();
                }
                break;
            case 3:
                queue.display();
                break;
            case 4:
                x = queue.firstElement();
                if (x != -1) {
                    cout << "Front element: " << x << endl;
                }
                break;
            case 5:
                x = queue.rearElement();
                if (x != -1) {
                    cout << "Rear element: " << x << endl;
                }
                break;
            case 6:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
