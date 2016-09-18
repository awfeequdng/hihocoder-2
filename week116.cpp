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
void bfs(int s,vector<int>&vec){
    memset(visit,0,sizeof(visit));
    queue<int> q;
    q.push(s);
    vec.push_back(s);
    visit[s]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        rep(i,0,n){
            if(!visit[i] && G[x][i]){
                vec.push_back(i);
                q.push(i);
                visit[i]=1;
            }
        }
    }
}
void solve(){
    int ans=0;
    while(true){
        memset(visit,0,sizeof(visit));
        int d = dfs(0,n-1,INF);
        if(d==0) break;
        ans+=d;
    }
    vector<int> vec;
    bfs(0,vec);
    printf("%d %d\n",ans,vec.size());
    sort(vec.begin(),vec.end());
    rep(i,0,vec.size())
        printf("%d%c",vec[i]+1,i==vec.size()-1?'\n':' ');
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d",&n,&m);
    while(m--){
        int u,v,c;
        scanf("%d %d %d",&u,&v,&c);
        u--,v--;
        G[u][v]+=c;
    }
    solve();
    return 0;
}