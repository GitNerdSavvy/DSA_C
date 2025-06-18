#include<bits/stdc++.h>
using namespace std;
vector<int> prevGreat(int *arr,int n){
    stack<int>st;
    vector<int>ans(n);
    ans[0]=-1;
    st.push(arr[0]);
    for(int i=1;i<n;i++){
        while(!st.empty() && st.top()<=arr[i]) st.pop();
        
        if(st.empty()) ans[i]=-1;
        else ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}
int main(){
    int arr[8] = {3,1,2,5,4,6,2,3};
    // int arr[8] = {100,80,60,81,70,60,75,85};
    vector<int>ans = prevGreat(arr,8);
    for(int i=0;i<8;i++){
        cout<<ans[i]<<" ";
    }
}