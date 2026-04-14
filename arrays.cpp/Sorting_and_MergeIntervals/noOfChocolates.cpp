#include <bits/stdc++.h>
using namespace std;

int chocolateDistribution(vector<int>& arr, int m) {
    int n = arr.size();

    if (m == 0 || n == 0) return 0;
    if (n < m) return -1;

    sort(arr.begin(), arr.end());

    int mini = INT_MAX;
    
    for (int i = 0; i + m - 1 < n; i++) {
        int diff = arr[i + m - 1] - arr[i];
        mini = min(mini, diff);
    }

    return mini;
}

int main() {
    vector<int> arr = {7, 3, 2, 4, 9, 12, 56};
    int m = 3;

    cout << chocolateDistribution(arr, m);

    return 0;
}