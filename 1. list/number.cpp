#include <iostream>

using namespace std;

class Number {
    private:
    int list[10];
    int index;
    int i;

    public:
    Number(int initialList[], int size) {
        for (i = 0; i < size; i++) {
            list[i] = initialList[i];
        }
        index = size - 1;
    }

    int sizeList() {
        return index + 1;
    }

    void printList() {
        for (i = 0; i <= index; i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }

    void insert(int x, int pos) {
        index++;
        for(i = index; i >= pos; i--) {
            list[i + 1] = list[i];
        }
        list[pos] = x;
        printList();
    }

    int search(int y) {
        int flag = -1;
        for(i = 0; i <= index; i++) {
            if(y == list[i]) {
                return i;
            }
        }
        return flag;
    }

    void insertAfter(int x, int y) {
        int pos = search(y);
        if(pos != -1) {
            insert(x, pos + 1);
        }
        else {
            cout << "The item is not present on the list" << endl;
        }
    }

    void insertBefore(int x, int y) {
        int pos = search(y);
        if(pos != -1) {
            insert(x, pos);
        }
        else {
            cout << "The item is not present on the list" << endl;
        }
    }

    void deleteElement(int pos) {
        index--;
        for(i = pos; i <= index; i++) {
            list[i] = list[i + 1];
        }
        printList();
    }

    int insertInOrder(int x) {
        for(i = 0; i <= index; i++) {
            if(x < list[i]) {
                insert(x, i);
                return 0;
            }
        }
        insert(x, index + 1);
        return 0;
    }
};

int main() {
    int initialList[10];
    int size;
    int choice;
    int x, pos, after, before;

    cout << "enter size of the array: ";
    cin >> size;

    cout << "enter array elements: ";
    for (int i = 0; i < size; i++) {
        cin >> initialList[i];
    }

    Number n(initialList, size);

    do {
        cout << "\n1 for size\n2 for insert in order\n3 for insert\n4 for insert after\n5 for insert before\n6 for delete element\n7 for print\n8 for exit\n\nEnter a choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            cout << "ok" << endl;
            cout << "Size of the list is " << n.sizeList() << endl;
            break;
        case 2:
            cout << "Enter the element: ";
            cin >> x;
            n.insertInOrder(x);
            break;
        case 3:
            cout << "Enter the element: ";
            cin >> x;
            cout << "Enter the position: ";
            cin >> pos;
            n.insert(x, pos);
            break;
        case 4:
            cout << "Enter the element: ";
            cin >> x;
            cout << "Enter the insert after element: ";
            cin >> after;
            n.insertAfter(x, after);
            break;
        case 5:
            cout << "Enter the element: ";
            cin >> x;
            cout << "Enter the insert before element: ";
            cin >> before;
            n.insertBefore(x, before);
            break;
        case 6:
            cout << "Enter the index of position: ";
            cin >> pos;
            n.deleteElement(pos);
            break;
        case 7:
            n.printList();
            break;
        case 8:
            exit;
            break;
        default:
            cout << "Please enter a valid choice" << endl;
        }
    } while(choice != 8);
}