#define ll long long
#define mod 1000000007
class Solution {
public:
    int countTexts(string s) {
        int size=s.size();
        ll dp[size+2];
         memset(dp,0,sizeof dp);
 dp[0]=1;
        dp[1]=1;
        ll ans=1;
        char temp=s[0];
        vector<ll> v;
        int k=2;
       
        for(int i=1; i<size; i++){
            if(temp==s[i]){
                // cout<<"Aman "<<endl;
                if(temp=='7'&&k>3 ||temp=='9' && k>3){
             ll p= ((dp[k-1]%mod)+ (dp[k-2]%mod)+(dp[k-3]%mod)+(dp[k-4])%mod)%mod;   
                     dp[k]=p%mod; 
                }else if(k>2){
   ll p= ((dp[k-1]%mod)+ (dp[k-2]%mod)+(dp[k-3]%mod))%mod;
               dp[k]=p%mod; 
                    // cout<<"kk id "<<dp[k]<<endl;
                    }else{
                  dp[k]=((dp[k-1]%mod)+(dp[k-2]%mod))%mod;    
                }
            


               ans=dp[k]; 

                    k++;
            }else{
                memset(dp,0,sizeof dp);
                dp[0]=1;
                dp[1]=1;
                temp=s[i];
                v.push_back(ans);
ans=1;
                k=2;
                
            }
        }
    ll t=ans;
        for(auto a:v){
            t=((t%mod)*(a%mod))%mod;
        }
        
        return t;
    }
};
