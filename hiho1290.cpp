<<<<<<< HEAD
/*
 * 构造状态时要自己构造好无后效性的状态方程
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=103;
int n,m,num[MAXN][MAXN];

void solve(){
    
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d%d",&n,&m);
    rep(i,0,n){
        getchar();
        rep(j,0,m){
            char c;
            scanf("%c",&c);
            num[i][j]=c=='.'?0:1;
        }
    }
    solve();
    printf("%d\n",);
    return 0;
=======
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define INF 100000
const int MAXN = 105;
int n,m,num[MAXN][MAXN],dp[MAXN][MAXN][2];

void solve(){
	dp[0][0][0] = 0;
	dp[0][0][1] = num[0][1];
	for(int i=1;i<n;i++){
		dp[i][0][0] = INF;
		dp[i][0][1] = dp[i-1][0][1] + 1 - num[i][0];
	}
	for(int j=1;j<m;j++){
		dp[0][j][0] = dp[0][j-1][0] + 1 - num[0][j];
		dp[0][j][1] = INF;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			dp[i][j][0] = min(dp[i][j-1][0],dp[i][j-1][1]+num[i+1][j-1])+1-num[i][j];
			dp[i][j][1] = min(dp[i-1][j][1],dp[i-1][j][0]+num[i-1][j+1])+1-num[i][j];
		}
	}
	printf("%d\n",min(dp[n-1][m-1][0],dp[n-1][m-1][1]));
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,0,n){
		getchar();
		rep(j,0,m){
			char c;
			scanf("%c",&c);
			num[i][j]=c=='.'?1:0;
		}
	}
	solve();
	return 0;
>>>>>>> 3a750285d93a15108dc456afcaa30704cb53fd2f
}