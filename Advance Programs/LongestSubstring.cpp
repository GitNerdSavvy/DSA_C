#include<bits/stdc++.h>
using namespace std;
int lengthSubstring(string s){
    int n=s.length();
    int l=0,ans=0;
    vector<int>c(255,-1);
    for(int r=0;r<n;r++){
        if(c[s[r]] >= l){
            l=c[s[r]]+1;
        }
        c[s[r]] =r;
        ans=max(ans,r-l+1);
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<lengthSubstring(s);
}