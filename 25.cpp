// RECURSION + MEMOIZATION

#define ll long long
class Solution {
public:
    ll dp[501][501];
    ll fun(string &s1, string &s2, int n, int m){
        if(m<0){
            return n+1;
        }
        if(n<0){
            return m+1;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        ll ans1=INT_MAX;
        ll ans2=INT_MAX;
        ll ans3=INT_MAX;
             ll ans4=INT_MAX;
        if(s1[n]==s2[m]){
            ans1=fun(s1,s2,n-1,m-1);
        }else{
        ans2=1+fun(s1,s2,n-1,m);
        ans3=1+fun(s1,s2,n,m-1);
        ans4=1+fun(s1,s2,n-1,m-1);
        }
        ans4=min(ans3,ans4);
        
        return dp[n][m]=min(ans1,min(ans2,ans4));
    }
    
    
    
    int minDistance(string s1,string s2) {
        
        int n=s1.size();
        int m=s2.size();
      
   memset(dp,-1,sizeof dp);
    return fun(s1,s2,n-1,m-1);

    }
};




// TABULATION



#define ll long long
class Solution {
public:

    int minDistance(string s1,string s2) {
        
        int n=s1.size();
        int m=s2.size();
        if(n==0){
            return m;
        }

        
int dp[n+1][m+1];
for(int i=0; i<n+1; i++){
dp[i][0]=i;
}
for(int j=0; j<m+1; j++){
    dp[0][j]=j;
}
for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
if(s1[i-1]==s2[j-1]){
    dp[i][j]=dp[i-1][j-1];
    }else{
        int t=min(dp[i-1][j-1],dp[i-1][j]);
        dp[i][j]=1+min(t,dp[i][j-1]);
    }
}
}
        return dp[n][m];
    }
};
