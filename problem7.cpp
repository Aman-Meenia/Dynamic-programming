// RECURSIVE CODE + MEMOIZATION

#include<bits/stdc++.h>
using namespace std;

int dp[100000+1];
int fun(vector<int> &v, int i ,int k){
    if(i==0) return 0;
    if(dp[i]!=-1){
        return dp[i];
    }
    int minsteps=INT_MAX;
for(int j=1; j<=k; j++){
    if(i-j>=0){
int jump=fun(v,i-j,k)+abs(v[i]-v[i-j]);
minsteps=min(minsteps,jump);
    }
}
return dp[i]=minsteps;
}


int main( ){
    #ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif
   
   int size;
   cin>>size;

int k;
cin>> k;
  vector<int> v(size);
for(int i=0; i<size; i++){
    cin>>v[i];
}
memset(dp,-1,sizeof dp);

cout<<fun(v,size-1,k)<<endl;

}



// TABULATION



#include<bits/stdc++.h>
using namespace std;
int main( ){
    #ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif
   
   int size;
   cin>>size;
vector<int> v(size);
int k;
cin>> k;
for(int i=0; i<size; i++){
    cin>>v[i];
}
vector<int> dp(size);
dp[0]=0;


for(int i=1; i<size; i++){
int minsteps=INT_MAX;
    for(int j=1; j<=k ;j++){

        if(i-j>=0){

            int jump=dp[i-j]+abs(v[i]-v[i-j]);
            minsteps=min(jump,minsteps);
            
        }
    }
    dp[i]=minsteps;
}
cout<<dp[size-1]<<endl;





 
}

