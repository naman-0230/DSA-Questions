#include <iostream>
using namespace std;
int main()
{   
    int n;
    cout<< "enter no. of elements"<<endl;
    cin >> n;
    
    int arr[n], arr1[n];
    cout<< "enter array numbers";
    for(int i=0; i<n ;i++)
    cin>> arr[i];

    arr1[0]=arr[0];
    int i ,j=0;

    for(int i=1; i<n;i++){
            if(arr1[j]!=arr[i])
            { 
                j++;
                arr1[j]= arr[i];
            }
            
        }

    for(int i=0; i<j+1; i++){
            cout<< arr1[i]<<" ";

        }
        

   return 0;
}