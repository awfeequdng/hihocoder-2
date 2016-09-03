#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
#define INF 1000000000

struct edge{
	int e,l;
	edge(){}
	edge(int ee,int ll):e(ee),l(ll){}
};
bool operator >(edge a,edge b){
	return a.l<b.l;
}
const int MAXN=100003;
int n,m,s,t,dp[MAXN];
vector<edge> G[MAXN];
map<int,int> ma[MAXN];

void dijkstra(){
	priority_queue<edge,vector<edge>,greater<edge> > q;
	q.push(edge(s,0));
	dp[s]=0;
	while(!q.empty()){
		int e = q.top().e,l = q.top().l;q.pop();
		if(dp[e]<l) continue;
		vector<edge>& v=G[e];
		for(int i=0;i<v.size();i++){
			if(dp[v[i].e]>dp[e]+v[i].l){
				dp[v[i].e]=dp[e]+v[i].l;
				q.push(v[i]);
			}
		}
	}
}
int solve(){
	for(int i=0;i<n;i++){
		dp[i]=INF;
		map<int,int>& m = ma[i];
		for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
			G[i].push_back(edge(it->first,it->second));
		}
	}		
	dijkstra();
	return dp[t];
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d%d%d%d",&n,&m,&s,&t);
	s--,t--;
	for(int i=0;i<m;i++){
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		u--,v--;
		if(ma[u].find(v)==ma[u].end() || ma[u][v]>l){
			ma[v][u]=ma[u][v]=l;
		}
	}
	printf("%d\n",solve());

	return 0;
}