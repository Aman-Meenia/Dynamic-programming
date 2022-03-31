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

// int ans=0;
// void fun(vector<int> &v, int i , int target,ll sum){
// if(sum==target){
//     ans++;
//     return ;
// }
 
// if(sum>target){
//     return ;
// }
// for(int i=0; i<v.size(); i++){
// fun(v,i+1,target,sum+v[i]);
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
// ll sum=0;
// fun(v,0,target,sum);
// cout<<ans<<endl;




sort(v.begin(),v.end());
vector<int> dp(target+1);
dp[0]=1;

for(int i=1; i<target+1; i++){
    for(int j=0; j<n; j++){
if(v[j]<=i){

dp[i]=(dp[i]%mod+dp[i-v[j]]%mod)%mod;

    }else{
        break;
    }
}
 
}
 
cout<<dp[target]<<endl;

 
 }
 
 
 
 
 
 
