#include <iostream>
#include <vector>

using namespace std;

class ZeroMatrix {
private:
    vector<vector<int>> matrix;
    int i, j;

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

    void zero(int r, int c) {
        vector<int> row(r, 1);
        vector<int> col(c, 1);
  
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
  
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (row[i] == 0 || col[j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    ZeroMatrix z;
    int r, c;

    cout << "enter rows: ";
    cin >> r;
    cout << "enter columns: ";
    cin >> c;
    cout << "enter elements: ";

    z.getInput(r, c);
    z.zero(r, c);
    z.printMatrix(r, c);

    return 0;
}