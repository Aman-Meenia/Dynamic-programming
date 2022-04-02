
// RECURSIVE CODE

class Solution {
public:
    
   int fun(int i){
        if(i==0){
            return 1;
        }
        if(i==1){
            return 1;
        }
        return fun(i-1)+fun(i-2);
        
    }
    int climbStairs(int n) {
        return fun(n);
    }
};


// MEMOIZED CODE

class Solution {
public:
    int dp[46];
   int fun(int i){
        if(i==0){
            return 1;
        }
        if(i==1){
            return 1;
        }
       if(dp[i]!=-1) return dp[i];
       
        return dp[i]= fun(i-1)+fun(i-2);
        
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof dp);
        return fun(n);
    }
};


// TABULATION

class Solution {
public:
    
    int climbStairs(int n) {
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=n; i++ ){
            dp[i]=dp[i-1]+dp[i-2];
        }
        // memset(dp,-1,sizeof dp);
        
        return dp[n];
    }
};
