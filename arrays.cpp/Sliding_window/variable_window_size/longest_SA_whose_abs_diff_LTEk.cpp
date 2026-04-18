#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int lengthSA(vector<int> &v , int k){
deque<int> dqmax;
deque<int> dqmin;
int j=0;  
int length = 0, max_length = 0;

for(int i = 0; i< v.size(); i++){

    while(!dqmax.empty() && v[dqmax.back()] <= v[i]){
        dqmax.pop_back();
    }
    while(!dqmin.empty() && v[dqmin.back()] >= v[i]){
        dqmin.pop_back();
    }
    dqmin.push_back(i);
    dqmax.push_back(i);
    
    while( (v[dqmax.front()] - v[dqmin.front()]) > k){         // while(!dqmax.empty() && !dqmin.empty() && (v[dqmax.front()] - v[dqmin.front()]) > k){   when you put this in first
        
        if(!dqmax.empty() && j== dqmax.front()){         // important to avoid dq.erase
            dqmax.pop_front();
         }
         if(!dqmin.empty() && j==dqmin.front()){
            dqmin.pop_front();
         }
        j++;
    }

   length = i-j+1;
   max_length = max(max_length, length);


}

 return max_length;
}

int main (){
  vector<int> v ={1,2,4,6,4,9};
 int k=4;
 
 cout<<lengthSA(v,k);
    return 0;
}
