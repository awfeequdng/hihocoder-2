#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)


typedef long long ll;
const ll INF = 900000000000000000;
const int MAXM=103;
int q,n,m,k,t,a[MAXM],b[MAXM];
ll dp[MAXM][10004];


void solve(){
    ll ans=0;
    rep(kk,0,n){
        fill(dp[0],dp[0]+k+1,INF);
        dp[0][0]=0;
        for(int i=1;i<=m;i++){
            for(int j=0;j<=k;j++){
                if(b[i-1]==0) dp[i][j] = dp[i-1][j];
                else if(j<b[i-1]) dp[i][j] = min(dp[i-1][j],dp[i][0]+a[i-1]);
                else dp[i][j] = min(dp[i-1][j],dp[i][j-b[i-1]]+a[i-1]);
            }
        }
        if(dp[m][k]>=INF){
            printf("No Answer\n");
            return ;
        }
        ans+=dp[m][k];
        // printf("%lld\n",dp[m][k]);
        rep(i,0,m){
            b[i]/=t;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d%d",&n,&m,&k,&t);
        rep(i,0,m) scanf("%d",&a[i]);
        rep(i,0,m) scanf("%d",&b[i]);
        solve();
    }
    return 0;
}