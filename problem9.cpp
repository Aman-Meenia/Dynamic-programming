// RECURSION + MEMOIZATION
class Solution {
public:
    int dp[101][101];
    int fun(int i, int j){
        if(i==0 &&j ==0){
            return 1;
        }
        if(i<0 ||j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
       int up=fun(i-1,j);
        
        int left=fun(i,j-1);
        return dp[i][j]=up+left;
    }
    
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof dp);
        return fun(m-1, n-1);
        
    }
};



// TABULATION 

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0&&j==0){
                    dp[i][j]=1;
                }else{
            int up=0;
                int left =0;
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
        return dp[m-1][n-1];
    }
};
