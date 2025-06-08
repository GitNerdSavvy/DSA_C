#include<bits/stdc++.h>
using namespace std;
int solve(string s){
    int l=0,r=0,n=s.length(),ans=0;
    unordered_map<char,int>ump{{'a',0},{'b',0},{'c',0}};
    while(r<n){
        ump[s[r]]++;
        while(ump['a']>0 && ump['b']>0 && ump['c']>0){
            ans+=n-r;
            ump[s[l++]]--;
        }
        r++;
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<solve(s);
}