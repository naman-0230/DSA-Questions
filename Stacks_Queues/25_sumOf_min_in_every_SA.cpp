#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

vector<int> lastSmaller(vector<int> &v){
 vector<int> lastSmaller(v.size(), -1);
    stack<int> st;

    for(int i= v.size()-1 ; i>= 0 ;i--){
        while(!st.empty() && v[st.top()] > v[i]){  
            lastSmaller[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return lastSmaller;
}

vector<int> nextSmaller(vector<int> &v){
    vector<int> nextSmaller(v.size(), v.size());   
    stack<int> st;

    for(int i=0;i<v.size();i++){
        while(!st.empty() && v[st.top()] >= v[i]){        /////imp to put >====== in next smaller
            nextSmaller[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return nextSmaller;
}

int sumOfMin(vector<int> &v){
    int sumMin = 0;
    vector<int> next = nextSmaller(v);
    vector<int> last = lastSmaller(v);
    
    for(int i=0; i< v.size(); i++){
        int numberSA = (i-last[i]) * (next[i]-i);
        int contribution = v[i] * numberSA;
        sumMin += contribution;
    }
    return sumMin;
}

int main(){
    vector<int> v = {3,1,2,4};
    cout<< sumOfMin(v);
    return 0;
}