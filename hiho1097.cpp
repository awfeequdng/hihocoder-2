#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define INF INT_MAX

const int MAXN=1003;
int n,G[MAXN][MAXN],d[MAXN],visit[MAXN];

void solve(){
    int ans=0;
    rep(i,0,n)
        d[i]=INF;
    d[0]=0;
    while(true){
        int minV=INF,minI=-1;
        rep(i,0,n){
            if(!visit[i] && d[i]<minV){
                minV=d[i],minI=i;
            }
        }
        if(minI==-1) break;
        ans+=d[minI];
        visit[minI]=1;
        rep(j,0,n){
            if(!visit[j]){
                d[j]=min(d[j],G[minI][j]);
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&n);
    rep(i,0,n)
        rep(j,0,n)
            scanf("%d",&G[i][j]);
    solve();
    return 0;
}