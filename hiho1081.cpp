#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 2000000000

struct edge{
	int e;
	int l;
}
const int MAXN=1003;
int n,m,s,tvisit[MAXN],dist[MAXN];
vector<edge> G[MAXN];

void dijkstra(){
	for(int i=0;i<n;i++)  dist[i]=INF;
	dist[s]=0;
	while(true){
		int minI=-1,minV=INF;
		for(int i=0;i<n;i++){
			if(!visit[i] && dist[i]<minV){
				minV=dist[i];
				minI=i;
			}
		}
		if(minI==-1) break;
		visit[minI]=1;
		for(int i=0;i<n;i++){
			if(!visit[i] && G[minI][i] && dist[i]>dist[minI]+G[minI][i]){
				dist[i]=dist[minI]+G[minI][i];
			}
		}
	}
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d%d%d%d",&n,&m,&s,&t);
	s--,t--;
	for(int i=0;i<m;i++){
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		u--,v--;
		if(!G[u][v]) G[u][v]=G[v][u]=l;
		else G[u][v]=G[v][u]=min(G[u][v],l);
	}
	dijkstra();
	printf("%d\n",dist[t]);
	return 0;
}