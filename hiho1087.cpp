#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=13;
int n,m,G[MAXN][MAXN],dp[1<<MAXN][MAXN];

bool all_one(int s){
    rep(i,0,n){
        if(!((s>>i)&1)) return false;
    }
    return true;
}
int solve(int s,int t){
    // printf("s=%d,t=%d\n",s,t);
    if(dp[s][t]!=-1) return dp[s][t];
    if(all_one(s)){
        // printf("-------------s=%d,t=%d\n",s,t);
        return dp[s][t] = G[t][0];
    }
    int ans = 0;
    rep(i,0,n){
        if(((s>>i)&1)==0 && G[t][i]){
            ans+=solve((1<<i)|s,i);
        }
    }

    return dp[s][t] = ans;
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d%d",&n,&m);
    rep(i,0,m){
        int a,b;
        scanf("%d%d",&a,&b);
        G[--a][--b]=1;
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(1,0));
    return 0;
}