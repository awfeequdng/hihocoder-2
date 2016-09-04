#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=102;
int n,m,order[MAXN],visit[MAXN],graph[MAXN][MAXN];
vector<int> G[MAXN];

void build(){
    memset(visit,0,sizeof(visit));
    queue<int> q;
    q.push(0);
    visit[0]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        rep(i,0,n){
            if(!visit[i] && graph[x][i]){
                G[x].push_back(i);
                q.push(i);
                visit[i]=1;
            }
        }
    }
}
bool solve(int s,int &next){
    vector<int>&v=G[s];
    int cnt=0;
    int * visited = new int[v.size()];
    memset(visited,0,sizeof(int)*v.size());
    bool isExit=false;
    while(cnt<v.size() && !isExit){
        isExit=true;
        rep(i,0,v.size()){
            int x=v[i];
            int old=next;
            if(!visited[i] && order[x]<=next){
                bool ok;
                visited[i]=1;
                if(order[x]==next){
                    ok = solve(x,++next);
                }else{
                    ok = solve(x,next);
                }
                if(ok){
                    isExit=false;
                    cnt++;
                    break;
                }else{
                    visited[i]=0;
                    next=old;
                }
            }
        }
    }
    delete []visited;
    return cnt==v.size();
}
int main(){
    freopen("data.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,n){
            G[i].clear();
            memset(graph[i],0,sizeof(graph[i]));
        }
        rep(i,0,n-1){
            int a,b;
            scanf("%d %d",&a,&b);
            a--,b--;
            graph[a][b]=graph[b][a]=1;
        }
        scanf("%d",&m);
        memset(order,0,sizeof(order));
        rep(i,1,m+1){
            int x;
            scanf("%d",&x);
            x--;
            order[x]=i;
        }
        build();
        int next=1;
        if(order[0]>1){
            printf("NO\n");
        }else{
            if(order[0]==0) next=1;
            else next=2;
            // rep(i,0,n){
            //     printf("输出%d\n",i);
            //     vector<int>&v=G[i];
            //     rep(j,0,v.size())
            //         printf("%d ",v[j]);
            //     printf("\n");
            // }
            // printf("输出order\n");
            // rep(i,0,n)
            //     printf("%d%c",order[i],i==n-1?'\n':' ');
            // printf("next=%d\n",next);
            printf("%s\n",solve(0,next)?"YES":"NO");
        }
    }
    return 0;
}