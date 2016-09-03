#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 200000000

const int MAXN=1003;
int n,m,visit[MAXN],dist[MAXN][MAXN],G[MAXN][MAXN];

void floyd(){
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)	
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			dist[j][i]=dist[i][j]=INF;
	for(int i=0;i<m;i++){
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		u--,v--;
		if(!G[u][v]) G[u][v]=G[v][u]=l;
		else G[u][v]=G[v][u]=min(G[u][v],l);
		dist[u][v]=dist[v][u]=G[u][v];
	}
	floyd();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			printf("%d%c",dist[i][j],j==n-1?'\n':' ');
	
	return 0;
}