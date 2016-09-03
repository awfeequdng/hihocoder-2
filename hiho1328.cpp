#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=102;
int n,m,k,a,b,c,d,dp[MAXN*MAXN][MAXN*MAXN],G[MAXN*MAXN][MAXN*MAXN],cnt;
char num[MAXN][MAXN];
vector<int> v;//钥匙

int solve(){
	//建图
	cnt=n*m;
	for(int i=0;i<cnt;i++){
		for(int j=0;j<cnt;j++){
			
		}
	}
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d%d%d%d%d%d%d\n",&n,&m,&k,&a,&b,&c,&d);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			scanf("%c",&num[i][j]);
		getchar();
	}
	for(int i=0;i<k;i++){
		int ii,jj;
		scanf("%d%d",&ii,&jj);
		v.push_back(ii*m+jj);
	}
	printf("%d\n",solve());
	solve();
	/**
	最短路算法
	图论
	最近公共祖先
	网络流
	
	*/
	return 0;
}