
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

class Solution {
public:
int dp[101];
    int fun(vector<int> &v, int i){
        if(i==0){
            return v[i];
        }
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
//         we have two option if we rob the nth house we cannot ron the n-1 because we cannot rob two continous house that's why we move to n-2 house
//         if we not rob nth house then we rob n-1 house
        return dp[i]=max(v[i]+fun(v,i-2),fun(v,i-1));
    }
    int rob(vector<int>& v) {
      
        memset(dp,-1,sizeof dp);
        int size=v.size();
          
        return fun(v,size-1);
    }
};
// tabulation


  int rob(vector<int>& v){
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
