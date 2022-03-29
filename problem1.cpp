#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set> 
#define ll long long 
#define mod 1000000007
using namespace std;


// recursive code 
ll ans=0;
void totalways(int n, int target){
if(n==target){
    ans++;
    ans=ans%1000000007;
    return ;
}
if(n>target){
    return ;
}
for(int i=1; i<=6; i++){
   totalways(n+i,target);
}
}


// dp code

void totalwaysdp(int target){
vector<ll> dp(target+1,0);
dp[0]=1;
dp[1]=1;

    for(int i=2; i<=target; i++){
        for(int k=1; k<=6; k++){
            if(i>=k){
                 dp[i]=dp[i]%mod;
              dp[i]+=dp[i-k]%mod;
              
            }
        }
    }
    cout<<dp[target]%mod<<endl;
}


int main( ){
    #ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif
int n;
cin>>n;

 
totalwaysdp(n);

totalways(0,n);
cout<<ans<<endl;






}
