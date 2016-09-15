#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=52,MAXM=3003;
int q,n,A[MAXN],B[MAXN],dp[MAXN][4][MAXM];

void solve(){
    for(int j=0;j<=3;j++){
        for(int k=0;k<=MAXM;k++){
            if(k==0) dp[0][j][k]=0;
            else dp[0][j][k]=-INF;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=3;j++){
            for(int k=0;k<=MAXM;k++){
                if(j==0) dp[i][j][k]=dp[i-1][j][k];
                else{
                    if(A[i-1]>k) dp[i][j][k]=dp[i-1][j][k];
                    else dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-1][k-A[i-1]]+B[i-1]);
                }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=3;j++){
    //         for(int k=0;k<=3*90+1;k++){
    //             printf("i=%d,j=%d,k=%d,dp[i][j][k]=%d\n",i,j,k,dp[i][j][k]);
    //         }
    //     }
    // }
    int ans=-1;
    for(int k=0;k<=MAXM;k++){
        if(k%50==0){
            if(dp[n][3][k]>ans) ans=dp[n][3][k];
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("data.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        rep(i,0,n){
            double x;
            scanf("%lf %d",&x,&B[i]);
            A[i]=x*10;
        }
        solve();
    }
    return 0;
}