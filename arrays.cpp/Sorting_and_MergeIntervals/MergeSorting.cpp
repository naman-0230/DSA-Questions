#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &v, int start, int mid , int end){
    vector<int> temp;
    int i=start;
    int j= mid+1;
 
 while(i<=mid && j<=end){
    if(v[i]<=v[j]){
       temp.push_back(v[i]);
       i++;                               // for main elements
    }
    else{
        temp.push_back(v[j]);
        j++;
    }
 }

  while(i<=mid){
    temp.push_back(v[i]);
    i++;                             // for remaining element
  }

  while(j<=end){
    temp.push_back(v[j]);
    j++;
  }

  for(i=0; i<temp.size(); i++){         // reflecting original vector at each step
    v[start+i]= temp[i];
  }
}


 void MergeSort(vector<int> &v, int start, int end){
       if(start<end){
        int mid = start + (end-start)/2;

        MergeSort(v, start, mid);          //left half divide
        MergeSort(v, mid+1, end);          // right side divide 

     merge(v, start, mid, end);
       }
    }


int main(){

   int n;
cout<<"enter number of elements";
cin>>n;
vector<int> arr(n);
cout<<"enter the elements;";
for(int i=0; i<n; i++){
cin>>arr[i];
}

MergeSort(arr, 0, n-1);

for(int i=0; i<n; i++){
cout<< arr[i];
}

return 0;
}