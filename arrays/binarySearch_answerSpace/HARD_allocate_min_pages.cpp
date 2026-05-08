#include<iostream>
#include<vector>
using namespace std;

int countStudents(vector<int>&v , int students, int mid){
    int count = 1;                          ////IMP AS NOT DOING BOOL ISPOSSIBLE 
    int sum = 0; 
    for(int i=0; i<v.size(); i++){
      sum += v[i];

      if(sum > mid){  
        count++;
        sum = v[i];
      }
    }
 return count;

}

int maxArray(vector<int> &v){
    int maxArray = 0;
    for(int i=0; i<v.size(); i++){
    maxArray = max(maxArray, v[i]);
    }
    return maxArray;
}
int sumArray(vector<int> &v){
    int sumArray = 0;
    for(int i=0; i<v.size(); i++){
    sumArray += v[i];
    }
    return sumArray;
}

int min_Ofmax_pages(vector<int> &v, int students){

    int low = maxArray(v);
    int high = sumArray(v);
    int ans = high;

    while(low <= high){
    int mid = low + (high - low)/2;

    int no_of_students = countStudents(v, students, mid);

    if(no_of_students == students){
        ans = mid;
        high = mid - 1;
    }
    else if(no_of_students > students){
        low = mid + 1;
    }
    else{
        high = mid - 1;
    }
 
    }
    return ans;
}

int main(){
vector<int>v = {25,46,28,49,24};
int students = 4;
cout<< min_Ofmax_pages(v, students);

return 0;
}