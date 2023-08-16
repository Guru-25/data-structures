#include <iostream>
#include <vector>

using namespace std;

class HorizontalFlipping {
private:
    vector<vector<int>> matrix;
    int i, j, k;

public:
    void getInput(int r, int c) {
        matrix.resize(r, vector<int>(c));

        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
            cin >> matrix[i][j];
            }
        }
    }

    void printMatrix(int r, int c) {
        cout << endl;
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void flip(int r, int c) {
        for (i = 0; i < r; i++) {
            j = 0;
            k = c - 1;

            while (j < k) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][k];
                matrix[i][k] = temp;
                j++;
                k--;
            }
        }

        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] = 0;
                }
                else {
                    matrix[i][j] = 1;
                }
            }
        }
    }
};

int main() {
    HorizontalFlipping f;
    int r, c;

    cout << "enter rows: ";
    cin >> r;
    cout << "enter columns: ";
    cin >> c;
    cout << "enter elements: ";
    f.getInput(r, c);
    f.flip(r, c);
    f.printMatrix(r, c);

    return 0;
}