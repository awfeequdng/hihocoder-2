#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int num[26][8],visit[26][8];
int t,y[3];
char x[3];
int di[8]={-1,-2,-2,-1,1,2,2,1},dj[8]={-2,-1,1,2,2,1,-1,-2};

void bfs(int n,int m){
    queue<pair<int,int> > q,p;
    q.push(make_pair(n,m));
    visit[n][m]=1;
    int dist=1;
    while(!q.empty()){
        int i=q.front().first,j=q.front().second;q.pop();
        rep(k,0,8){
            int ii=i+di[k],jj=j+dj[k];
            if(ii>=0 && ii<26 && jj>=0 && jj<8 && !visit[ii][jj]){
                p.push(make_pair(ii,jj));
                visit[ii][jj]=1;
                num[ii][jj]+=dist;
            }
        }
        if(q.empty()){
            while(!p.empty()){
                q.push(p.front());p.pop();
            }
            dist++;
        }
    }
}
void solve(){
    rep(i,0,26){
        memset(num[i],0,sizeof(num[i]));
    }
    rep(p,0,3){
        rep(i,0,26){
            memset(visit[i],0,sizeof(visit[i]));
        }
        bfs(x[p]-'A',y[p]-1);
    }
    int ans=INT_MAX;
    rep(i,0,26)
        rep(j,0,8)
            if(num[i][j]<ans) ans=num[i][j];
    printf("%d\n",ans);
}
int main(){
    freopen("data.txt","r",stdin);
    cin>>t;
    while(t--){
        cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2];
        solve();
    }
    return 0;
}