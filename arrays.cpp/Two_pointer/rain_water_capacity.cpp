#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> height = {5, 2, 3, 1, 2};

    int left = 0, right = height.size() - 1;
    int leftmax = 0, rightmax = 0;
    int water = 0;

    while(left<right) {
        leftmax= max(leftmax, height[left]);
        rightmax= max(rightmax, height[right]);
        if(leftmax < rightmax){
            
            water += (leftmax - height[left]);
            left++;
        }
        
        else {
                water += (rightmax - height[right]);
            
            right--;
        }
    }

    cout<< water;

    return 0;
}