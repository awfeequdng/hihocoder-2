#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

struct edge{
    int e,l;
    edge(){}
    edge(int ee,int ll):e(ee),l(ll){}
};
bool operator<(edge a,edge b){
    return a.l>b.l;
}
const int MAXN=100003;
int n,m,visit[MAXN];
vector<edge> G[MAXN];

void solve(){
    int ans=0;
    priority_queue<edge> pq;
    pq.push(edge(0,0));
    while(!pq.empty()){
        edge e=pq.top();pq.pop();
        if(!visit[e.e]){
            ans+=e.l;
            // printf("e.e=%e.e.l=%d\n",e.e,e.l);
            visit[e.e]=1;
            vector<edge>&vec=G[e.e];
            rep(i,0,vec.size()){
                edge ed = vec[i];
                pq.push(ed);
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d%d",&n,&m);
    while(m--){
        int u,v,l;
        scanf("%d%d%d",&u,&v,&l);
        u--,v--;
        G[u].push_back(edge(v,l));
        G[v].push_back(edge(u,l));
    }
    solve();
    return 0;
}