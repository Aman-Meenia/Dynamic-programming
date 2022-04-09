// RECURSION +TABULATION

#define ll long long 
class Solution {
public:
    ll dp[101][101];
    ll fun(vector<vector<int> > &v, int i, int j){
    if(j<0||j>=v[0].size()){
        return INT_MAX;
    }
   if(i==v.size()-1){
    return v[i][j];
   } 
        if(dp[i][j]!=-1) return dp[i][j];
   ll straight=v[i][j]+fun(v,i+1,j);
   ll left=v[i][j]+fun(v,i+1,j-1);
   ll right=v[i][j]+fun(v,i+1,j+1);

   return dp[i][j]= min(min(straight,left),right);


}
    int minFallingPathSum(vector<vector<int>>& v) {
        ll ans=INT_MAX;
        memset(dp,-1, sizeof dp);
        for(int i=0; i<v[0].size(); i++){
            // cout<<v[0][i]<<endl;
            ans=min(ans,fun(v,0,i));
        }
        return ans;
      
    }
};

// TABULATION


#define ll long long 
class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& v) {
        ll ans=INT_MAX;
       
        int n=v.size();
        int m=v[0].size();
   ll dp[n][m];
        
for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        if(i==0){
            dp[i][j]=v[i][j];
        }else{
            ll straight=v[i][j];
            ll left=v[i][j];
            ll right=v[i][j];
            straight+=dp[i-1][j];
            if(j>0){
left+=dp[i-1][j-1];
            }else{
                left+=INT_MAX;
            }
            if(j<m-1){
                right+=dp[i-1][j+1];
            }else{
                right+=INT_MAX;
            }
            dp[i][j]= min(min(straight,left),right);
        }
    }
}
        for(int i=0; i<n; i++){
            // cout<<dp[n-1][i]<<" ";
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
      
    }
};
