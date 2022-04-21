// RECURION + MEMOIZATION
class Solution {
public:
    
    int dp[21][10001];
    int targetsum(vector<int> &v, int target , int i){
       
      
        if(i<0){
            if(target==0){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        if(v[i]<=target){
            return dp[i][target]=targetsum(v,target-v[i],i-1)+targetsum(v,target,i-1);
        }else{
            return dp[i][target]=targetsum(v,target,i-1);
        }   
        
    }
     
    int findTargetSumWays(vector<int>& v, int target) {
        int sum=0;
        for(auto a:v){
            sum+=a;
        }
        if(target>sum||target+sum<0){
            return 0;
        }
        if((target+sum)%2!=0){
            return 0;
        }
        int size=v.size();
         target=(target+sum)/2;
        memset(dp, -1 ,sizeof dp);
        return targetsum(v,target,size-1);
        
        
        
    }
};




// TABULATION 

class Solution {
public:
   int findTargetSumWays(vector<int>& v, int target) {
        int sum=0;
        for(auto a:v){
            sum+=a;
        }
        if(target>sum||target+sum<0){
            return 0;
        }
        if((target+sum)%2!=0){
            return 0;
        }
        int size=v.size();
         target=(target+sum)/2;
        
        int dp[size+1][target+1];
          for(int i=0; i<target+1; i++){
           dp[0][i]=0;
       }
       for(int i=0; i<size+1; i++){
           dp[i][0]=1;
       }
        for(int i=1; i<size+1; i++){
            for(int j=0; j<target+1; j++){
                if(v[i-1]<=j){
          dp[i][j]=dp[i-1][j-v[i-1]]+dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
   
        return dp[size][target];
        
        
        
    }
};

