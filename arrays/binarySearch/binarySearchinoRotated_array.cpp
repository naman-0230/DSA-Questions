#include <iostream>
#include<vector>
using namespace std;

int searchElement(vector<int>&arr, int target) {
    int i = 0, j = arr.size()- 1;

    while (i<=j) {
        int mid = i + (j - i) / 2;
    if(arr[mid]==target) return mid;

    if(arr[mid]==arr[i] && arr[mid]==arr[j]){            // for handling DUPLICATES
        i++;                                             //reducing window size 
        j--;
    }

    if(arr[i]<=arr[mid]){
        if(target<arr[mid] && target>=arr[i]){              // left hand is sorted
             j=mid-1;
             }
        else{
            i=mid+1;
        
        }     
    }
    else{
        if(target>arr[mid] && target<=arr[j]){             // right hand is sorted
          i=mid+1;
        }
        else{
         j=mid-1;
            
        }
        }
}
        

    
    return -1;   // if not found
}
int main() {
    int n;
    cout << "enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<< "enter target";
    int target;
    cin>>target;

    int Index = searchElement(arr, target);
  
    cout << " index: " <<Index;

    return 0;
}