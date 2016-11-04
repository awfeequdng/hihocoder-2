#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define MOD 1000000007

const int MAXN=102;
int n,dp[MAXN][2];

int _pow(int x){
    int ans = 1;
    while(x--){
        ans = (ans*2)%MOD;
    }
    return ans;
}
void solve(){
    dp[1][0]=dp[1][1]=0;
    dp[2][0]=0,dp[2][1]=1;
    for(int i=3;i<=n;i++){
        dp[i][0] = (dp[i-1][0]+dp[i-1][1])%MOD;
        dp[i][1] = (dp[i-1][0]+_pow(i-2))%MOD;
        // printf("i=%d,%d,%d\n",i,dp[i][0],dp[i][1]);
    }
    // printf("%d\n",(dp[n][0])%MOD);
    // printf("%d\n",(dp[n][1])%MOD);
    printf("%d\n",(dp[n][0]+dp[n][1])%MOD);
}
int main(){
    // freopen("data.txt","r",stdin);
    cin>>n;
    solve();
    return 0;
}