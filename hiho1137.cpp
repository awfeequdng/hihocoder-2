//男女分开+滚动数组
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN=102,maxB=1002;
int n,x,y,b,value[MAXN],sal[MAXN];
char sex[MAXN];
int dpM[MAXN][maxB],dpF[MAXN][maxB];//dpM[i][j]，i表示还剩多少男生，j表示还剩多少salary，dp[i][j]表示完成后状态的最大价值
int male[MAXN],female[MAXN],m,f;

void solveMale(){
	for(int k=1;k<=1;k++){
		for(int i=0;i<=x;i++){
			for(int j=0;j<=b;j++){
				if(j+sal[male[k]]>b) dpM[i][j]=dpM[i][j];
				else dpM[i][j]=max(dpM[i][j],dpM[i+1][]+value[male[k]]);
			}
		}
	}
}

void solve(){
	solveMale();
	printf("输出男生：\n");
	for(int i=0;i<=x;i++){
		for(int j=0;j<=b;j++){
			printf("剩余男生名额%d,剩余薪水%d,价值%d\n",i,j,dpM[i][j]);
		}
	}
}

int main(){
	freopen("data.txt","r",stdin);
	scanf("%d %d %d %d\n",&n,&x,&y,&b);
	for(int i=1;i<=n;i++){
		scanf("%c %d %d\n",&sex[i],&value[i],&sal[i]);
		if(sex[i]=='M') male[++m]=i;
		if(sex[i]=='F') female[++f]=i;
	}
	solve();	
	return 0;
}