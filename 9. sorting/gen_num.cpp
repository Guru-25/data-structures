#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int n = 10000;
    
    ofstream outputFile("random_numbers.txt");

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open the file for writing." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int random_num = rand();
        outputFile << random_num << endl;
    }

    outputFile.close();
    cout << "Random numbers have been written to 'random_numbers.txt'." << endl;

    return 0;
}