#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define INF 1000000000

typedef long long ll;
const int MAXN=503;
int G[MAXN][MAXN];
int n,m,visit[MAXN];

int dfs(int s,int t,int f){
    if(s==t) return f;
    visit[s]=1;
    rep(i,0,n){
        if(!visit[i] && G[s][i]){
            int d = dfs(i,t,min(f,G[s][i]));
            if(d>0){
                G[s][i]-=d;
                G[i][s]+=d;
                return d;
            }
        }
    }
    return 0;
}
int solve(){
    int ans=0;
    while(true){
        memset(visit,0,sizeof(visit));
        int d = dfs(0,n-1,INF);
        if(d==0) break;
        ans+=d;
    }
    return ans;
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d",&n,&m);
    while(m--){
        int u,v,c;
        scanf("%d %d %d",&u,&v,&c);
        u--,v--;
        // G[u][v]=max(G[u][v],c);
        G[u][v]+=c;
    }
    printf("%d\n",solve());
    return 0;
}