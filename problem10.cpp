// RECURSION + MEMOIZATION
class Solution {
public:
    int dp[101][101];
int fun(vector<vector<int> > &v, int i, int j){
    
    if(i==0&&j==0&&v[i][j]!=1){
        return 1;
    }
    if(i<0||j<0) return 0;
    if(v[i][j]==1) return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int left=fun(v,i,j-1);
    int up=fun(v,i-1,j);
    return dp[i][j]=left+up;
    
}
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        memset(dp,-1,sizeof dp);
        return fun(v, n-1 , m-1);
    }
};

// TABULATION 
class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
      int dp[n][m];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
               if(i==0&&j==0&&v[i][j]==0){
        dp[i][j]=1;
    }  else if(v[i][j]==1) {
                   dp[i][j]=0;
               }  else{
                   int left=0;
                   int up=0;
                   if(i>0){
                       up=dp[i-1][j];
                   }
                   if(j>0){
                       left=dp[i][j-1];
                   }
                   dp[i][j]=left+up;
                }
                
                
            }
        }  
        
        
        return dp[n-1][m-1];
    }
};
