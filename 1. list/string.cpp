#include <iostream>

using namespace std;

struct Cricket {
    string team;
    string captain;
};

void printEach(Cricket c) {
    cout << c.team << " - " << c.captain;
}

void printAll(Cricket c[], int n) {
    for(int i =0; i<n;i++) {
        printEach(c[i]);
        cout << endl;
    }
}

int search(Cricket c[], int n, string cap) {
    for(int i =0; i<n;i++) {
        if(c[i].captain == cap) {
            printEach(c[i]);
            return 1;
        }
    }
    cout << "no team is present" << endl;
    return 0;
}

void insert(Cricket c[], int n, int pos, string team, string captain) {
        int index=size-1;
        for( int i = n; i >= pos; i--) {
            c[i + 1] = c[i];
        }
        c[pos].team = team;
        c[pos].captain = captain;

        printAll(c, n);
}

void del(Cricket c[], int n, int pos) {
    n--;
    for(int i = pos; i <= n; i++) {
        c[i] = c[i + 1];
    }
    printAll(c, n);
}

int main() {
    Cricket c[10];
    int n, i;
    int choice, pos;
    string cap, team;

    cout << "no of teams: ";
    cin >> n;
    for(i = 0; i<n;i++) {
        cout << "enter team " << i+1 << ": ";
        cin >> c[i].team;
        cout << "enter captain " << i+1 << ": ";
        cin >> c[i].captain;
    }
    do {
        cout << "\n\n1 for print\n2 for captain search\n 3 for insert\n4 for delete\n\nenter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            printAll(c, n);
            break;
        case 2:
            cout << "enter captain: ";
            cin >> cap;
            search(c, n, cap);
            break;
        case 3:
            cout << "enter team: ";
            cin >> team;
            cout << "enter captain: ";
            cin >> cap;
            cout << "enter position: ";
            cin >> pos;
            insert(c, n, pos, team, cap);
            break;
        case 4:
            cout << "enter position: ";
            cin >> pos;
            del(c, n, pos);
            break;
        case 5:
            break;
        default:
            cout << "not valid choice";
            break;
        } 
    } while (choice != 5);
    return 0;
}