// RECURSION + MEMOIZATION


class Solution {
public:
    int dp[301][5001];
    int totalways(vector<int> &v, int target , int i){
    if(i<0){
        if(target==0){
            return 1;
        }
        return 0;
    }    
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
       if(v[i]<=target) {
           return dp[i][target]=totalways(v, target-v[i] ,i)+totalways(v,target,i-1);
       }
        return dp[i][target]=totalways(v,target,i-1);
        
        
    }
    
    
    int change(int target, vector<int>& v) {
        int size=v.size();
        memset(dp,-1,sizeof dp);
        return totalways(v,target,size-1);
    }
};




// TABULATION



class Solution {
public:

    
    int change(int target, vector<int>& v) {
        int size=v.size();
        // memset(dp,-1,sizeof dp);
        int dp[size+1][target+1];
        
        for(int i=0; i<target+1; i++){
            dp[0][i]=0;
        }
        
        for(int i=0; i<size+1; i++){
            dp[i][0]=1;
        }
        for(int i=1; i<size+1; i++){
            for(int j=1; j<target+1; j++){
                if(v[i-1]<=j){
                    dp[i][j]=dp[i][j-v[i-1]]+dp[i-1][j];
                }else{
dp[i][j]=dp[i-1][j];
                    }
            }
        }
        
return dp[size][target];
    }
};

