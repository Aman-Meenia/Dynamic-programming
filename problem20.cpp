// RECURSION + MEMOIZATION

#include<bits/stdc++.h>
#define ll long long
int dp[20][10001];
ll minimumcoin(vector<int> &v , int target, int i){

if(target==0){
    return 0;
}
    if(i<0) return INT_MAX;
if(dp[i][target]!=-1){
	return dp[i][target];
}
    if(v[i]<=target){
        return dp[i][target]=min(1+minimumcoin(v,target-v[i],i),minimumcoin(v,target,i-1));
    }else{
        return dp[i][target]= minimumcoin(v,target,i-1);
    }





}
int minimumElements(vector<int> &v, int target)
{
	int size=v.size();
	memset(dp,-1,sizeof dp);
int ans=minimumcoin(v,target,size-1);
	if(ans==INT_MAX){
		return -1;
	}
return ans;
    // Write your code here.
}





// TABULATION



#include<bits/stdc++.h>
#define ll long long

int minimumElements(vector<int> &v, int target)
{
	int size=v.size();
	ll dp[size+1][target+1];
	for(int i=0; i<size+1; i++){
		dp[i][0]=0;
	}
	for(int i=0; i<target+1; i++){
		dp[0][i]=INT_MAX;
	}
	
	for(int i=1; i<size+1; i++){
		for(int j=1; j<target+1; j++){
			if(v[i-1]<=j){
				dp[i][j]=min(1+dp[i][j-v[i-1]],dp[i-1][j]);
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	if(dp[size][target]>=INT_MAX){
		return -1;
	}

return  dp[size][target];
    // Write your code here.
}

