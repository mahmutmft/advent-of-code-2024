#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int main() {
    const int MAX_ROWS = 1100;
    const int MAX_COLS = 20;
    long matrica[MAX_ROWS][MAX_COLS] = {0};
    int n = 0;
    string line;

    while (true) {
        getline(cin, line);
        if (line == ".") break;

        stringstream ss(line);
        int num, m = 0;
        while (ss >> num) {
            matrica[n][m++] = num;
        }
        n++;
    }

    int counter = 0;

    for (int i = 0; i < n; i++) {
        bool isSafe = true;
        bool increasing = false, decreasing = false;

        for (int j = 0; j < MAX_COLS - 1 && matrica[i][j + 1] != 0; j++) {
            int diff = matrica[i][j + 1] - matrica[i][j];
            if (abs(diff) < 1 || abs(diff) > 3) {
                isSafe = false;
                break;
            }
            if (diff > 0) {
                if (decreasing) {
                    isSafe = false;
                    break;
                }
                increasing = true;
            } else if (diff < 0) {
                if (increasing) {
                    isSafe = false;
                    break;
                }
                decreasing = true;
            }
        }

        if (isSafe) {
            counter++;
        }
    }

    cout<<counter<<endl;
    return 0;
}
