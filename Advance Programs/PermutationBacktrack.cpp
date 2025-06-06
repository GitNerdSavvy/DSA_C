#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>res;
void permute(vector<int>&arr,int i,int n){
    if(i==n){
        res.push_back(arr);
        return;
    }
    for(int j=i;j<=n;j++){
        swap(arr[i],arr[j]);
        permute(arr,i+1,n);
        swap(arr[i],arr[j]);
    }
    
}
vector<vector<int>> permutation1(vector<int>&arr){
    res.clear();
    permute(arr,0,arr.size()-1);
    return res;
}
int main(){
   vector<int>arr;
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
    int val;
    cin>>val;
    arr.push_back(val);
   }

    vector<vector<int>>ans= permutation1(arr);
    for(auto &it :ans){
        for(int num:it){
            cout<<num<<" ";
        }
        cout<<"\n";
    }
    return 0;
}