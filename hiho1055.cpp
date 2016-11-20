#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=103;
int n,m,dp[MAXN][MAXN],visit[MAXN],value[MAXN],cal[MAXN];
vector<int> G[MAXN];

void solve(int x){
    dp[x][0]=0,dp[x][1]=value[x];
    vector<int>&v=G[x];
        // dp[x][k]=value[x];
    rep(i,0,v.size()){
        rep(k,2,m+1){
            if(cal[i]){
                rep(j,0,k+1){
                    if(k<j) continue;
                    dp[x][k]=max(dp[x][k],dp[x][k-j]+dp[i][j]);
                }
            }
        }
    }
    cal[x]=1;
}
void postOrder(int x){
    vector<int>&v=G[x];
    visit[x]=1;
    rep(i,0,v.size()){
        if(!visit[i])
            postOrder(i);
    }
    solve(x);
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d%d",&n,&m);
    rep(i,0,n-1)
        scanf("%d",&value[i]);
    rep(i,0,n-1){
        int u,v;
        scanf("%d %d",&u,&v);
        u--,v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    postOrder(0);
    printf("%d\n",dp[0][m]);
    return 0;
}