#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=1003;
int n,m,q,w[MAXN],dp[MAXN][1<<11];

int getNum(int s){
    int cnt=0;
    while(s){
        if(s&1) cnt++;
        s=s>>1;
    }
    return cnt;
}
void bin(int s){
    for(int i=m;i>0;i--){
        printf("%d",(s>>(i-1))&1);
    }
}
void solve(){
    rep(i,1,n+1){
        rep(j,0,1<<m){
            if(getNum(j)>q){
                dp[i][j]=0;
                continue;
            }
            int x=getNum(j>>1);
            // printf("x=%d\n",x);
            if(x==q){
                dp[i][j]=dp[i-1][j>>1];
            }else{
                dp[i][j]=max(dp[i-1][j>>1],dp[i-1][(j>>1)+(1<<(m-1))]);
                // printf("选择\n");
            }
            if(j&1)
                dp[i][j]+=w[i-1];
            // printf("i=%d,j=",i);
            // bin(j);
            // printf(",dp[i][j]=%d\n",dp[i][j]);
        }
    }
    // rep(i,1,n+1){
    //     rep(j,0,1<<m){
    //         printf("i=%d,j=",i);
    //         bin(j);
    //         printf(",dp[i][j]=%d\n",dp[i][j]);
    //     }
    // }
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&q);
    rep(i,0,n)
        scanf("%d",&w[i]);
    solve();
    int ans=-1;
    rep(j,0,1<<m){
        if(dp[n][j]>ans) ans=dp[n][j];
    }
    printf("%d\n",ans);
    // printf("getNum(3)=%d\n",getNum(3));
    return 0;
}