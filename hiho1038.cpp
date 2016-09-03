#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=502,MAXM=100003;
int n,m,need[MAXN],value[MAXN],dp[MAXM];

void solve(){
	for(int i=1;i<=n;i++){
		for(int j=m;j>=0;j--){
			if(need[i]>j) dp[j]=dp[j];
			else dp[j]=max(dp[j],dp[j-need[i]]+value[i]);
		}
	}
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&need[i],&value[i]);
	solve();
	printf("%d\n",dp[m]);
	return 0;
}