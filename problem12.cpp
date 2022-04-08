// RECURSION + MEMOIZATION 
#define ll long long
class Solution {
public:
    ll dp[201][201];
    ll minimumpathsum(vector<vector<int> > &v, int i, int j){
    if(i==v.size()-1){
        return v[i][j];
    }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
    ll straight=v[i][j]+minimumpathsum(v,i+1,j);
    ll right=v[i][j]+minimumpathsum(v,i+1,j+1);
    return dp[i][j]=min(straight,right);

}
    int minimumTotal(vector<vector<int>>& v) {
        memset(dp,-1,sizeof(dp));
        return minimumpathsum(v,0,0);
    }
};

// TABUlATION
#define ll long long
class Solution {
public:

    int minimumTotal(vector<vector<int>>& v) {
        int n=v.size();
int dp[n][n];
        for(int i=0; i<n; i++){
            dp[n-1][i]=v[n-1][i];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int straight=v[i][j]+dp[i+1][j];
                int right=v[i][j]+dp[i+1][j+1];
                dp[i][j]=min(straight,right);
            }
        }
       
        return dp[0][0];
        
    }
};
