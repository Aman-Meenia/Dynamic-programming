// RCURSION + MEMOIZATION



class Solution {
public:
    int dp[1001][1001];

int longestcommonsubsquence(string &s, string 
                            &s2, int n, int m){
    if(n<0||m<0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
if(s[n]==s2[m]){
    return dp[n][m]=1+longestcommonsubsquence(s,s2,n-1,m-1);
}else{
    return dp[n][m]=max(longestcommonsubsquence(s,s2,n-1,m),longestcommonsubsquence(s,s2,n,m-1));
}


}
    
    int longestCommonSubsequence(string s, string s2) {
        memset(dp,-1,sizeof dp);
        int n=s.size();
        int m=s2.size();
        return longestcommonsubsquence(s,s2,n-1,m-1);
    }
};



// TABULATION


class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
       
        int n=s1.size();
        int m=s2.size();
        
        int **array=new int*[n+1];
        for(int i=0; i<n+1; i++){
            array[i]=new int[m+1];
        }
        
        for(int i=0; i<n+1; i++){
            array[i][0]=0;
        }
        for(int i=0; i<m+1; i++){
            array[0][i]=0;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                
                if(s1[i-1]==s2[j-1]){
                    array[i][j]=1+array[i-1][j-1];
                }else{
                    array[i][j]=max(array[i-1][j],array[i][j-1]);
                }
                
            }
        }
        return array[n][m];
        
    }
};
