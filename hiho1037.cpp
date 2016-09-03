#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=202;
int n,dp[MAXN][MAXN],num[MAXN][MAXN];

void solve(){
	dp[1][1]=num[1][1];
	dp[2][1]=num[1][1]+num[2][1];
	dp[2][2]=num[1][1]+num[2][2];
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(j==1) dp[i][j]=dp[i-1][j]+num[i][j];
			else if(j==i) dp[i][j]=dp[i-1][j-1]+num[i][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+num[i][j];
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=i;j++){
	// 		printf("%d ",dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			scanf("%d",&num[i][j]);
		}
	}
	if(n==0) printf("0\n");
	else if(n==1) printf("%d\n",num[1][1]);
	else{
		solve();
		int maxV=-1;
		for(int i=1;i<=n;i++)
			maxV=max(maxV,dp[n][i]);
		printf("%d\n",maxV);
	}
	return 0;
}