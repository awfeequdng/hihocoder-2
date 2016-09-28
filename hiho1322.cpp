#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=502;
int t,n,m,par[MAXN],height[MAXN];
void init(){
    rep(i,0,n){
        par[i]=i;
        height[i]=0;
    }
}
int find(int x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
void unite(int x,int y){
    int a=find(x),b=find(y);
    if(a==b) return ;
    if(height[a]<height[b]){
        par[a]=b;
    }else{
        par[b]=a;
        if(height[a]==height[b]) height[a]++;
    }
}
bool same(int a,int b){
    return find(a)==find(b);
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        bool isTree=true;
        scanf("%d%d",&n,&m);
        init();
        rep(i,0,m){
            int u,v;
            scanf("%d %d",&u,&v);
            u--,v--;
            if(same(u,v)){
                isTree=false;
            }
            unite(u,v);
        }
        if(!isTree) printf("NO\n");
        else{
            if(m==n-1) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}