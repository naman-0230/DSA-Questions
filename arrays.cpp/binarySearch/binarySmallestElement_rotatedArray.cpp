#include <iostream>
using namespace std;

int smallestElement(int arr[], int n) {
    int i = 0, j = n - 1;

    while (i <j) {
        int mid = i + (j - i) / 2;

        if (arr[mid]>arr[j]) {        ///remember to comapre with j
            i = mid+1;   
        }
        else if(arr[mid]<arr[j]){
            j = mid;     
        }
        else{
           j--;            /// important concept*************////when mid is equal to j we dont know
        }                         /// where to go so we just reduce the window size
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

    int peakIndex = smallestElement(arr, n);
  
    cout << "smallest index: " << peakIndex << endl;
    cout << "smallest value: " << arr[peakIndex] << endl;

    return 0;
}