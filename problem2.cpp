#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set> 
#define ll long long 
#define mod 1000000007
#define pb push_back
#define fi first
#define bg .begin();
#define en .end();
#define se second
#define mp make_pair
using namespace std;

// RECURSIVE CODE
 
// int ans=0;
// void fun(vector<int> &v, int i , int target){
// if(target==0){
//     ans++;
//     return ;
// }
// if(i>v.size()-1){
// return ;
// }
// if(v[i]<=target){
   
// fun(v,i,target-v[i]);

// fun(v,i+1,target);
// }else{
// fun(v,i+1,target);
// }
 
 
// }
 
 
int main( ){
    #ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif
   
 int n;
   cin>> n;
int target;
cin>>target;
 
vector<int> v(n);
for(int i=0; i<n; i++){
    cin>>v[i];
}
// fun(v,0,target);
// cout<<ans<<endl;

// TABULATION 
vector<vector<int> > dp(109,vector<int> (1000009));
for(int i=0; i<target+1; i++){
dp[0][i]=0;
}
for(int i=0; i<n+1; i++){
dp[i][0]=1;
}
for(int i=1; i<n+1; i++){
    for(int j=1; j<target+1; j++){
 
if(v[i-1]<=j){
    dp[i][j]=(dp[i][j-v[i-1]]%mod+dp[i-1][j]%mod)%mod;
    }else{
        dp[i][j]=dp[i-1][j];
    }
}
}
 
cout<<dp[n][target]<<endl;
 
 
 
}#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set> 
#define ll long long 
#define mod 1000000007
#define pb push_back
#define fi first
#define bg .begin();
#define en .end();
#define se second
#define mp make_pair
using namespace std;

// RECURSIVE CODE
 
// int ans=0;
// void fun(vector<int> &v, int i , int target){
// if(target==0){
//     ans++;
//     return ;
// }
// if(i>v.size()-1){
// return ;
// }
// if(v[i]<=target){
   
// fun(v,i,target-v[i]);

// fun(v,i+1,target);
// }else{
// fun(v,i+1,target);
// }
 
 
// }
 
 
int main( ){
    #ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif
   
 int n;
   cin>> n;
int target;
cin>>target;
 
vector<int> v(n);
for(int i=0; i<n; i++){
    cin>>v[i];
}
// fun(v,0,target);
// cout<<ans<<endl;

// TABULATION 
vector<vector<int> > dp(109,vector<int> (1000009));
for(int i=0; i<target+1; i++){
dp[0][i]=0;
}
for(int i=0; i<n+1; i++){
dp[i][0]=1;
}
for(int i=1; i<n+1; i++){
    for(int j=1; j<target+1; j++){
 
if(v[i-1]<=j){
    dp[i][j]=(dp[i][j-v[i-1]]%mod+dp[i-1][j]%mod)%mod;
    }else{
        dp[i][j]=dp[i-1][j];
    }
}
}
 
cout<<dp[n][target]<<endl;
 
 
 
}
