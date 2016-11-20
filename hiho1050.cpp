#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=100003;
int n,visit[MAXN],dist[MAXN];
vector<int> G[MAXN];

void postOrder(int v){
    
}
void solve(){

}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&n);
    rep(i,0,n-1){
        int u,v;
        scanf("%d %d",&u,&v);
        u--,v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    solve();
    return 0;
}