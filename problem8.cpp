
// Recursive code

void fun(vector<int> &v, int i){
    if(i==0){
        retrun v[0];
    }else if(i<0){
        return 0;
    }
    return max(v[i]+fun(v,i-2),fun(v,i-1));
}

// memoized code

int fun(vector<int> &v, int i,vector<int> &dp){
    if(i==0){
        return v[i];
    }else if(i<0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    return dp[i]=max(v[i]+fun(v,i-2,dp),fun(v,i-1,dp));
}
int maximumNonAdjacentSum(vector<int> &v){
    int size=v.size();
    vector<int> dp(size,-1);
 return fun(v,size-1,dp);
}
// tabulation


int maximumNonAdjacentSum(vector<int> &v){
    int size=v.size();
    vector<int> dp(size,-1);
    dp[0]=v[0];
    for(int i=1; i<size; i++){
        int take=v[i];
        if(i>1){
           take+=dp[i-2]; 
        }
        int nottake=dp[i-1];
        dp[i]=max(take,nottake);
        
    }
 return dp[size-1];
}
