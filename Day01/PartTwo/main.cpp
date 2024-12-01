#include <iostream>
#include <cmath>
using namespace std;

void bubbleSort(long arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                long temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    long niza[999], niza2[999];
    int n = 0, number = 0, number2 = 0;

    while (true) {
        cin >> number >> number2;
        if (!number || !number2) break;
        niza[n] = number;
        niza2[n] = number2;
        n++;
    }

    bubbleSort(niza, n);
    bubbleSort(niza2, n);
    int sum = 0;
    for (int i=0;i<n;i++) {
        int counter = 0;
        for (int j =0;j<n;j++) {
            if (niza[i] == niza2[j]) {
                counter++;
            }
        }
        sum += niza[i] * counter;
    }
    cout << sum;
    return 0;
}
