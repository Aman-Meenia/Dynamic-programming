// RECURSION + MEMOIZATION



#include<bits/stdc++.h>
int dp[1001][1001];
bool fun(vector<int> &v, int i , int target){
	if(target ==0){
		return true;
	}
	if(i==0){
		if(target==v[0]) return true;
		return false;
	}
	if(dp[i][target]!=-1) return dp[i][target];
	if(v[i]<=target){
		return dp[i][target]=fun(v,i-1,target-v[i])||fun(v,i-1,target);
	}else{
		return dp[i][target]=fun(v,i-1,target);
	}
}

int minSubsetSumDifference(vector<int>& v, int n)
{
int sum=0;
	for(auto a:v){
		sum+=a;
	}
	int target=sum/2;
	for(int i=target; i>=0; i--){
		memset(dp,-1,sizeof dp);
		if(fun(v,n-1,i)){
			int t=sum-i;
			return abs(t-i);
		}
	}
	
	return -1;
	
}







// TABULATION


int minSubsetSumDifference(vector<int>& v, int n)
{
int sum=0;
	for(auto a:v){
		sum+=a;
	}
	int target=sum/2;
	
	int dp[n+1][target+1];
	for(int i=0; i<target+1; i++){
		dp[0][i]=0;
	}
	for(int i=0; i<n+1; i++){
		dp[i][0]=1;
	}
	for(int i=1; i<n+1; i++){
		for(int j=1; j<target+1;j++){
			if(v[i-1]<=j){
				dp[i][j]=dp[i-1][j-v[i-1]]||dp[i-1][j];
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	for(int i=target; i>=0; i--){
if(dp[n][i]==1){
	int t=sum-i;
	return abs(t-i);
}
		
	}
	
	return -1;
	
	
}

