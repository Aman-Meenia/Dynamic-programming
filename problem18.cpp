// RECURSION + TABULATION


#include<bits/stdc++.h>
int dp[1001][1001];
int fun(vector<int> &v, int i, int target){
	if(target==0){
		return 1;
	}
	if(i==0){
		if(target==v[0]) return 1;
		return 0;
	}
	if(dp[i][target]!=-1){
		return dp[i][target];
	}
	if(v[i]<=target){
		return dp[i][target]=fun(v,i-1,target-v[i])+fun(v,i-1,target);
	}else{
		return dp[i][target]=fun(v,i-1,target);
	}
}


int findWays(vector<int> &v, int tar)
{
	int size=v.size();
	memset(dp,-1,sizeof dp);
	return fun(v,size-1,tar);
    // Write your code here.
}


// TABULATION


#include<bits/stdc++.h>



int findWays(vector<int> &v, int target)
{
	int size=v.size();
int dp[size+1][target+1];
	
	int n=size;
	for(int i=0; i<target+1; i++){
		dp[0][i]=0;
	}
	for(int i=0; i<n+1; i++){
		dp[i][0]=1;
	}
	for(int i=1; i<n+1; i++){
		for(int j=0; j<target+1; j++){
			if(v[i-1]<=j){
				dp[i][j]=dp[i-1][j-v[i-1]]+dp[i-1][j];
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	
	
	return dp[n][target];
	

  
}
