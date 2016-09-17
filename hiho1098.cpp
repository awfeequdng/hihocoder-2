#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define INF INT_MAX

struct edge{
    int s,e,l;
};
bool operator<(edge a,edge b){
    return a.l<b.l;
}
const int MAXN=100003,MAXM=1000003;
int n,m,par[MAXN],_rank[MAXN];
edge nodes[MAXM];

void init(){
    rep(i,0,n)
        par[i]=i;
}
int find(int x){
    if(x==par[x]) return x;
    return par[x]=find(par[x]);
}
void unite(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return ;
    if(_rank[x]<_rank[y]) par[x]=y;
    else{
        par[y]=x;
        if(_rank[x]==_rank[y]) _rank[x]++;
    }
}
bool same(int a,int b){
    return find(a)==find(b);
}
void solve(){
    init();
    sort(nodes,nodes+m);
    int ans=0;
    rep(i,0,m){
        int a=nodes[i].s,b=nodes[i].e;
        // printf("a=%d,b=%d,l=%d\n",a,b,nodes[i].l);
        if(!same(a,b)){
            ans+=nodes[i].l;
            unite(a,b);
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d",&n,&m);
    rep(i,0,m)
        scanf("%d %d %d",&nodes[i].s,&nodes[i].e,&nodes[i].l);
    solve();
    return 0;
}