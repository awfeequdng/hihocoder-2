#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000

struct Edge{
	int e,l;
	Edge(int ee,int ll):e(ee),l(ll){}
};
bool operator<(Edge a,Edge b){
	return a.l>b.l;
}
const int MAXN=100003;
int n,x[MAXN],y[MAXN],visit[MAXN],dist[MAXN];

void dijkstra(){
	for(int i=1;i<n;i++)
		dist[i]=INF;
	priority_queue<Edge> pq;
	pq.push(Edge(0,0));
	dist[0]=0;
	while(!pq.empty()){
		Edge e = pq.top();pq.pop();
		if(visit[e.e]) continue;
		visit[e.e]=1;
		for(int i=0;i<n;i++){
			if(!visit[i]){
				int len = min(abs(x[e.e]-x[i]),abs(y[e.e]-y[i]));
				if(dist[e.e]+len<dist[i]){
					dist[i]=dist[e.e]+len;
					pq.push(Edge(i,dist[i]));
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("dist[%d]=%d\n",i,dist[i]);
	}
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&x[i],&y[i]);
	dijkstra();
	printf("%d\n",dist[n-1]);
	return 0;
}