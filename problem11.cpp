// RECURSION+MEMOIZATION

#define ll long long 
class Solution {
public:
    ll dp[201][201];
    ll minimumpathsum(vector<vector<int> > &v, int i, int j){
    if(i==0&&j==0){
        return v[0][0];
    }
    if(i<0||i>=v.size()||j<0||j>=v[0].size()){
        return INT_MAX;
    }
if(dp[i][j]!=-1) return dp[i][j];
    ll left=v[i][j]+minimumpathsum(v,i,j-1);
    ll right=v[i][j]+minimumpathsum(v,i-1,j);

    return dp[i][j]=min(left,right);

}
    int minPathSum(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        memset(dp, -1, sizeof dp);
     int ans=minimumpathsum(v,n-1,m-1); 
        return ans;
        
    }
};


// TABULATION



#define ll long long
class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        ll dp[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
            if(i==0&&j==0){
                dp[i][j]=v[i][j];
            }else{
          ll up=v[i][j];
                if(i>0){
                    up+=dp[i-1][j];
                }else{
                    up+=INT_MAX;
                }
                ll left=v[i][j];
                if(j>0){
                    left+=dp[i][j-1];
                }else{
                    left+=INT_MAX;
                }
                dp[i][j]=min(left,up);
            }
            }
        }
        return dp[n-1][m-1];
    }
};
