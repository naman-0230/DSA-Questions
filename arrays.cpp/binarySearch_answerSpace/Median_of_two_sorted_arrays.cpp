#include<iostream>
#include<vector>
#include<climits>
using namespace std;

double findMedian(vector<int> &a , vector<int> &b){      ///many imp concepts in all
int a1 = a.size();
int b1 = b.size();
int left = (a1 + b1 + 1)/2;            // taking more on left (by preference)
int right = a1 + b1 - left;

if(a1 > b1){
    return findMedian(b,a);         //making sure we apply BS on smaller array
}

int i = 0; int j = a1;

int r2;                    // all four variables near median value of both arrays
int r1;                    //    . . . . l1 | r1 . . . .
int l1;                    //    . . . . l2 | r2 . . . .
int l2;                    //             ^   ^
                           //          mid-1  mid 
while(i<=j){

   int mid1 = i + (j-i)/2;
   int mid2 = left - mid1;
    l1 = (mid1 == 0)? INT_MIN : a[mid1 - 1];
    l2 = (mid2 == 0)? INT_MIN : b[mid2 - 1];       //imp 

    r1 = (mid1 == a1)? INT_MAX : a[mid1];          //imp
    r2 = (mid2 == b1)? INT_MAX : b[mid2];
    
    
    if(l1 <= r2 && l2 <= r1){
        //for even a+b median will be average of two median values
        if((a1 + b1)%2 == 0){ 
        return (max(l1, l2) + min(r1, r2))/2.0;
        }
        else{
        //for odd it will be left side of the partition as we took more in left side
        return max(l1, l2);
        }
    }
    else if(l2 > r1){
        i = mid1 +1;
    }
    else{
        j = mid1 -1;
    }  
    }
    return 0;    
}



int main(){
vector<int> a = {1,3,5,7,8};
vector<int> b = {2,4,6,7,8,9};

cout<<findMedian(a,b);

return 0;
}