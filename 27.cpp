// RECURSION + MEMOIZATION


class Solution {
public:
    int dp[2001][2001];
int matching(string &s1 ,string &s2, int n, int m){
    if(n<0&&m<0){
        return true;
    }
    if(n<0&&m>=0){
        return false;
    }
    if(m<0&&n>=0){
        for(int i=0; i<=n; i++){
            if(s1[i]!='*'){
                return false;
            }
        }
        return true;
    }
if(dp[n][m]!=-1){
    return dp[n][m];
}
if(s1[n]==s2[m] || s1[n]=='?'){
    return dp[n][m]=matching(s1,s2,n-1,m-1);
}else if(s1[n]=='*'){
    return dp[n][m]=matching(s1,s2,n-1,m)||matching(s1,s2,n,m-1);
}

return dp[n][m]=false;


}


    bool isMatch(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        memset(dp, -1, sizeof dp);
        return matching(s2,s1,m-1,n-1);
    }
};




//  TABULATION 





class Solution {
public:
  

    bool isMatch( string s2,string s1) {
        int n=s1.size();
        int m=s2.size();
        // memset(dp, -1, sizeof dp);
        // return matching(s2,s1,m-1,n-1);
        
  vector<vector<int> > dp(n+1,vector<int>(m+1,false));
     dp[0][0]=true;
        for(int i=1; i<m+1; i++){
            dp[0][i]=false;
        }

       for(int i=1; i<n+1; i++){
           bool flag=true;
           for(int j=1; j<=i; j++){
               if(s1[j-1]!='*'){
                   flag=false;
                   break;
               }
           }
           dp[i][0]=flag;
       }
        
        
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
               
                if(s1[i-1]==s2[j-1] || s1[i-1]=='?'){
dp[i][j]=dp[i-1][j-1];
}else if(s1[i-1]=='*'){
 dp[i][j]=dp[i-1][j]||dp[i][j-1];
}else{

dp[i][j]=false;
                }    
            }
        }
        
        
        
        
        return dp[n][m];
        
    }
};
