#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MOD 142857

const int MAXN=100002,MAXM=500002;
vector<int> G[MAXN];
int n,m,k,add[MAXN];
vector<int> v;

int dfs(int index){
	if(add[index]!=1) return add[index];
	vector<int>&v = G[index];
	for(int i=0;i<v.size();i++){
		add[index]+=dfs(v[i]);
		if(add[index]>=MOD) add[index]%=MOD;
	}
	return add[index];
}
int solve(){
	for(int i=0;i<n;i++)
		add[i]=1;
	for(int i=0;i<n;i++){
		if(add[i]==1) dfs(i);
	}
	// for(int i=0;i<n;i++)
		// printf("add[%d]=%d\n",i,add[i]);
	int sum=0;
	for(int i=0;i<v.size();i++){
		sum+=add[v[i]];
		if(sum>=MOD) sum%=MOD;	
	}
	return sum;
}

int main(){
	freopen("data.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++){
		int t;
		scanf("%d",&t);
		v.push_back(--t);
	}
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
	}
	printf("%d\n",solve());
	// solve();

	return 0;
}