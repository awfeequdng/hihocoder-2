#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 2000000000
const int MAXN=100003;
int n,G[MAXN][MAXN],x[MAXN],y[MAXN],visit[MAXN],dist[MAXN];

void dijkstra(){
	dist[0]=0;
	for(int i=1;i<n;i++)
		dist[i]=INF;
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
			if(!visit[i] && dist[i]>dist[minI]+G[minI][i]){
				dist[i]=dist[minI]+G[minI][i];
			}
		}
	}
}
int solve(){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			G[i][j]=G[j][i]=min(abs(x[i]-x[j],y[i]-y[j]));
		}
	}
	dijkstra();
	return dist[n-1];
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&x[i],&y[i]);
	printf("%d\n",solve());
	return 0;
}