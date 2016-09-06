#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=502,MAXM=100002;
int n,m,need[MAXN],value[MAXN],dp[MAXM];

void solve(){
    rep(i,1,n+1){
        rep(j,0,m+1){
            if(need[i-1]<=j)
                dp[j]=max(dp[j],dp[j-need[i-1]]+value[i-1]);
        }
    }
    // rep(i,1,n+1){
        // rep(j,0,m+1){
        //     printf("dp[%d]=%d\n",j,dp[j]);
        // }
    // }
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d",&n,&m);
    rep(i,0,n)
        scanf("%d %d",&need[i],&value[i]);
    solve();
    printf("%d\n",dp[m]);
    return 0;
}