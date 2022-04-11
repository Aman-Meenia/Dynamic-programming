// RECURSION + MEMOIZATION

class Solution {
public:
int dp[201][201];
    int fun(vector<vector<int> > &v, int i, int j){
        if(i>=v.size()) return 0;
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int ans=INT_MAX;
        for(int k=0; k<v.size(); k++){
            if(k==j){
                // continue;
            }else{
            ans=min(ans,fun(v,i+1,k));
            }
      
        }
       if(ans==INT_MAX) ans=0;
        return dp[i][j]=v[i][j]+ans;
    }
    int minFallingPathSum(vector<vector<int>>& v) {
     int ans=INT_MAX;
        for(int i=0; i<201; i++){
            for(int j=0; j<201; j++){
                dp[i][j]=INT_MAX;
            }
        }
        // memset(dp,-1,sizeof dp);
        for(int i=0; i<v.size(); i++){
          vector<bool> check(v.size(),true);
            int p=fun(v,0,i);
            ans=min(ans,p);
            // cout<<"ans is "<<ans<<endl;
        }
      
        return ans;  
    }
};
