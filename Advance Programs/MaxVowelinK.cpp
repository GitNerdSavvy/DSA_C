#include<bits/stdc++.h>
using namespace std;
bool vow(char ch){

    return ch =='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}
int solve(string s,int k){
    int l=0,h=0,t=0,ans=0;
    int n=s.length();
    while(h<n){
        if(vow(s[h])) t++;
        if(h-l == k){
            if(vow(s[l])) t--;
            l++;
        }
        h++;
        ans=max(ans,t);
        if(ans==k) return ans;
    }
    return ans;
}
int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    cout<<solve(str,k);
}