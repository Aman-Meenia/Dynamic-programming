class Solution {
public:
    int dp[501][501];
    int fun(vector<int> &v, int low, int high, bool turn){
    if(low>high) return 0;
     
if(dp[low][high]!=-1) return dp[low][high];
    if(turn==0){
        
// Alice turn
//         it will choose first or last elemnt and take maximum of that 
        return dp[low][high]=max(v[low]+fun(v,low+1,high,!turn),v[high]+fun(v,low,high-1,!turn));
    }else{
        // Bob turn
//         it will choose first or last element and take maximum of that and subtract that from it .so that it take minimum answer

        return dp[low][high]=min((-v[low])+fun(v,low+1,high,!turn),(-v[high])+fun(v,low,high-1,!turn));
    }

}
    bool stoneGame(vector<int>& v) {
        memset(dp,-1,sizeof dp);
        if(fun(v,0,v.size()-1,0)>0){
            return true;
        }else{
            return false;
        }

    }
};
