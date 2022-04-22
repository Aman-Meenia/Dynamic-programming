//  RECURSION + MEMOIZATION 
class Solution {
public:
    int dp[1001][1001];
    int fun(string &s1,string &s2,int n, int m){
        if(m<0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        int ans=0;
        if(s1[n]==s2[m]){
         ans=fun(s1,s2,n-1,m-1);   
        }
        ans+=fun(s1,s2,n-1,m);
        return dp[n][m]=ans;
        
        
    }
    int numDistinct(string s1, string s2) {
        memset(dp,-1,sizeof dp);
        int n=s1.size();
        int m=s2.size();
      return fun(s1,s2,n,m);  
    }
};



// TABULATION 



#define ll unsigned long long
class Solution {
public:

    int numDistinct(string s1, string s2) {
        // memset(dp,-1,sizeof dp);
        int n=s1.size();
        int m=s2.size();
        ll dp[n+1][m+1];
         for(int j=0; j<m+1; j++){
            dp[0][j]=0;
        }
//          when the string s2 ends we get our ans
        for(int i=0; i<n+1; i++){
            dp[i][0]=1;
        }
       
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
      
      return dp[n][m];  
    }
};
