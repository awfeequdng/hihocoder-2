/*数位DP*/
#include <cstdio>

int dp[7][10];//dp[i][j]表示长度为i，最高位为j的数字中符合题意的个数

void solve(){
	//dp[1][j]
	for(int j=0;j<10;j++)
		dp[1][j]=1;
	dp[1][4]=0;
	for(int i=2;i<=6;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				if(!((j==6&&k==2) || k==4 || j==4)){
					dp[i][j]+=dp[i-1][k];
				}
			}
		}
	}
}
int getBit(int t){
	if(!t) return 1;
	int ans=0;
	while(t){
		t/=10;
		ans++;
	}
	return ans;
}
int _pow(int t){
	int ans=1;
	while(t--){
		ans*=10;
	}
	return ans;
}
//[0,n)
int get(int n,const int len){
	int num[len+1];
	int t=n,k=1;
	if(!t) num[1]=0;
	while(t){
		num[k++]=t%10;
		t/=10;
	}
	int ans=0;
	for(int i=len;i>=1;i--){
		for(int j=0;j<num[i];j++){
			if(j!=4 && (i==len || (!(num[i+1]==6&&j==2)))){
				// printf("i=%d,j=%d\n",i,j);
				ans+=dp[i][j];
			}
		}
		if(num[i]==4 || (i!=len && num[i+1]==6&&num[i]==2)) return ans;
	}
	//自身
	for(int i=len;i>1;i--){
		if(num[i]==4 || (num[i]==6 && num[i-1]==2)) return ans;
	}
	if(num[1]==4) return ans;
	return ans+1;
}
int main(){
	freopen("data.txt","r",stdin);
	solve();
	int n,m;
	scanf("%d %d",&n,&m);
	while(n || m){
		n--;
		int a,b;//a,b分别是n,m的位数
		a=getBit(n),b=getBit(m);
		// printf("%d\n",get(m,b));
		// printf("%d\n",get(n,a));
		printf("%d\n",get(m,b)-get(n,a));
		scanf("%d %d",&n,&m);
	}
	return 0;
}