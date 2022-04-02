// RECURSIVE +MEMOIZATION


#include<bits/stdc++.h>
int dp[100000+1];
int fun(vector<int> &v, int i ){
    if(i==0) return 0;
    if(dp[i]!=-1){
        return dp[i];
    }
    int left=abs(v[i-1]-v[i])+fun(v,i-1);
    int right=INT_MAX;
    if(i>=2){
    right=abs(v[i-2]-v[i])+fun(v,i-2);
} 
return dp[i]=min(left,right);
}
int frogJump(int n, vector<int> &v)
{
    int size=v.size();
memset(dp,-1,sizeof dp);
return fun(v,size-1);
}



// TABULATION

#include<bits/stdc++.h>
int frogJump(int n, vector<int> &v)
{

int size=v.size();
int dp[size+1];
dp[0]=0;

for(int i=1; i<size; i++){
    int left=dp[i-1]+abs(v[i]-v[i-1]);
    int right=INT_MAX;
    if(i>1){
         right=dp[i-2]+abs(v[i]-v[i-2]);   
    }
dp[i]=min(left,right);
}
return dp[size-1];
}
