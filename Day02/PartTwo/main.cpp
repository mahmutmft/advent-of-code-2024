#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

const int MAX_ROWS = 1100;
const int MAX_COLS = 20;

bool isSafe(long row[], int size) {
    bool increasing = false, decreasing = false;
    for (int i = 0; i < size - 1; i++) {
        int diff = row[i + 1] - row[i];
        if (abs(diff) < 1 || abs(diff) > 3) {
            return false;
        }
        if (diff > 0) {
            if (decreasing) {
                return false;
            }
            increasing = true;
        } else if (diff < 0) {
            if (increasing) {
                return false;
            }
            decreasing = true;
        }
    }
    return true;
}


int main() {
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
    int safeCount = 0;
    for (int i = 0; i < n; i++) {
        int m = 0;
        while (m < MAX_COLS && matrica[i][m] != 0) {
            m++;
        }
        if (isSafe(matrica[i], m)) {
            safeCount++;
        } else {
            bool madeSafe = false;
            for (int j = 0; j < m; j++) {
                long tempRow[MAX_COLS];
                int tempIndex = 0;

                for (int k = 0; k < m; k++) {
                    if (k != j) {
                        tempRow[tempIndex++] = matrica[i][k];
                    }
                }

                if (isSafe(tempRow, tempIndex)) {
                    madeSafe = true;
                    break;
                }
            }

            if (madeSafe) {
                safeCount++;
            }
        }
    }

    cout << safeCount << endl;
    return 0;
}
