#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=102,MAXM=200002;
int n,m,cost[MAXN][MAXN],dp[MAXN][MAXM];

void solve(){
	for(int i=0;i<n;i++)
		dp[i][0]=0;
	for(int j=1;j<MAXM;j++){
		for(int i=0;i<n;i++){
			int MAXV=-1;
			for(int k=0;k<n;k++){
				if(cost[k][i]+j>=MAXM) continue;
				if(dp[k][cost[k][i]+j]>MAXV) MAXV=dp[k][cost[k][i]+j];
			}
			dp[i][j]=MAXV+1;
		}
	}
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&cost[i][j]);
	solve();
	if(m>=MAXM){
		
	}else{
		int ans=-1;
		for(int k=0;k<n;k++){
			if(dp[k][m]>ans) ans=dp[k][m];
		}
		printf("%d\n",ans);
	}
	return 0;
}