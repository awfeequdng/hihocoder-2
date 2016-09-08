#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=10003;
int t,n,m;
vector<int> G[MAXN];
int color[MAXN];

bool bfs(int xx){
    queue<int> q;
    q.push(xx);
    color[xx]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        vector<int>& v=G[x];
        rep(i,0,v.size()){
            if(color[v[i]]==color[x])
                return false;
            if(color[v[i]]==0){
                color[v[i]]=color[x]==1?2:1;
                q.push(v[i]);
            }
        }
    }
    return true;
}
bool solve(){
    memset(color,0,sizeof(color));
    rep(i,0,n){
        if(!color[i]){
            bool ok = bfs(i);
            if(!ok) return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[]){
    freopen("data.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        rep(i,0,n) G[i].clear();
        rep(i,0,m){
            int u,v;
            scanf("%d%d",&u,&v);
            u--,v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        printf("%s\n",solve()?"Correct":"Wrong");
    }
    return 0;
}