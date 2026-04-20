#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

class findK{
    public: 

    int k;
    findK(int k){         //imp constructor logic
        this->k = k;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    void addnum(int num){
     pq.push(num);
    
     if(pq.size()>k){
      pq.pop();
     }
    }
    int kfinder(){
        if(pq.size()<k){
         return -1;
        }
        else{
            return pq.top();
        }
    }


};
int main (){
 findK kl(3);   //constructor logic
 
kl.addnum(6);
kl.addnum(2);
cout<<kl.kfinder()<<endl;             // sometimes they ask for addnum to directly return value 
kl.addnum(6);                         // so need to combine functions
kl.addnum(1);
kl.addnum(10);
cout<<kl.kfinder()<<endl;
kl.addnum(0);
cout<<kl.kfinder();
return 0;
}
