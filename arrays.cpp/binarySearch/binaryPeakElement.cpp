#include <iostream>
using namespace std;

int findPeak(int arr[], int n) {
    int i = 0, j = n - 1;

    while (i < j) {
        int mid = i + (j - i) / 2;

        if (arr[mid] < arr[mid + 1]) {
            i = mid + 1;   // move right
        } else {
            j = mid;       // move left (including mid)
        }
    }

    return i;   // index of peak
}

int main() {
    int n;
    cout << "enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int peakIndex = findPeak(arr, n);

    cout << "Peak index: " << peakIndex << endl;
    cout << "Peak value: " << arr[peakIndex] << endl;

    return 0;
}