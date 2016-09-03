#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 2000000

const int MAXN=102;
int n,m,si,sj,di[4]={0,-1,0,1},dj[4]={-1,0,1,0},visit[MAXN][MAXN],layer[MAXN][MAXN];
char G[MAXN][MAXN];

void bfs(){
	for(int i=0;i<MAXN;i++)
		for(int j=0;j<MAXN;j++)
			layer[i][j]=INF;
	queue<pair<int,int> > q;
	q.push(make_pair(si,sj));
	visit[si][sj]=1;
	layer[si][sj]=0;
	while(!q.empty()){
		int ii=q.front().first,jj=q.front().second;q.pop();
		for(int i=0;i<4;i++){
			int x=ii+di[i],y=jj+dj[i];
			if(x>=0 && x<n && y>=0 && y<m && !visit[x][y]){
				if(G[x][y]=='.'){
					visit[x][y]=1;
					layer[x][y]=layer[ii][jj]+1;
					q.push(make_pair(x,y));
				}else if(G[x][y]=='S'){
					visit[x][y]=1;
					layer[x][y]=layer[ii][jj]+1;
				}
			}
		}
	}
}
int solve(){
	bfs();
	int minV=INF;
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		printf("%d%c",layer[i][j],);
	// 	}
	// }
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(G[i][j]=='S' && layer[i][j]!=INF){
				for(int d=0;d<4;d++){
					int x=i+di[d],y=j+dj[d];
					if(x>=0 && x<n && y>=0 && y<m && G[x][y]=='S' && layer[x][y]!=INF){
						int tmp;
						tmp=layer[i][j]+layer[x][y];
						if(tmp<minV) minV=tmp;
					}
				}
			}
		}
	}
	return minV;
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d %d\n",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%c",&G[i][j]);
			if(G[i][j]=='H'){
				si=i,sj=j;
			}
		}
		getchar();
	}
	int t=solve();
	if(t==INF) printf("Hi and Ho will not have lunch.\n");
	else printf("%d\n",t);
	return 0;
}