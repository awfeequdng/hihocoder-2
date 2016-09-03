#include <cstdio>
#include <vector>
using namespace std; 
#define rep(i,a,b) for(int i=a;i<b;i++)

#define MOD 1000000007
typedef long long ll;

struct Node{
	ll s,n;
};
ll l,r;
int k,num[20];
Node dp[20][10][400];

ll _pow(int x){
	ll t=1;
	while(x--){
		t*=10;
	}
	return t%MOD;
}
//记忆化搜索
Node dfs(int ii,int jj,int kk){//add denote next symbol is plus
	if(dp[ii][jj][kk].n!=-1) return dp[ii][jj][kk];
	if(ii==1){
		if(jj==kk-200){
			dp[ii][jj][kk].n=1,dp[ii][jj][kk].s=jj;
			return dp[ii][jj][kk];
		}else{
			dp[ii][jj][kk].n=0,dp[ii][jj][kk].s=0;
			return dp[ii][jj][kk];
		}
	}
	Node ans;
	ans.s=0,ans.n=0;
	for(int j=0;j<10;j++){
		Node tmp = dfs(ii-1,j,jj-kk+400);
		ans.n = ans.n+tmp.n;
		ans.s = (ans.s+((_pow(ii-1)*jj)%MOD*(tmp.n%MOD)+tmp.s)%MOD)%MOD;
	}
	return ans;
}
void init(){
	rep(i,1,19)
		rep(j,0,10)
			rep(k,0,400){
				dp[i][j][k].s=0,dp[i][j][k].n=-1;
			}
	rep(i,1,19)
		rep(j,0,10)
			rep(k,0,400)
				if(dp[i][j][k].n==-1) dp[i][j][k]=dfs(i,j,k);
	/*test*/
	// rep(i,1,4)
	// 	rep(j,0,10){
	// 		rep(k,190,220){
	// 			printf("dp[%d][%d][%d].s=%lld , dp[%d][%d][%d].n=%d\n",i,j,k-200,dp[i][j][k].s,i,j,k-200,dp[i][j][k].n);
	// 		}
	// 		printf("\n");
	// 	}
}
//[0,n]
int solve(ll n){
	int len=0;
	ll x=n; 
	while(x){
		num[len++]=x%10;
		x/=10;
	}
	int ans=0,pre=k;
	//len位
	for(int i=len-1;i>=0;i--){
		// printf("----------------------------i=%d\n",i);
		pre=k;
		bool add=true;
		int tmp=0;
		ll sum=0;
		for(int p=len-1;p>i;p--,add=!add){
			sum=sum*10+num[p];
			if(add) tmp+=num[p];
			else tmp-=num[p];
		}
		if(!add) pre=tmp-k;
		else pre=k-tmp;
		// printf("tmp=%d\n",tmp);
		for(int j=0;j<num[i];j++){
			if(i==len-1 && j==0) continue;
			// printf("i+1=%d,j=%d,pre=%d,dp[i+1][j][pre].s=%lld\n",i+1,j,pre,dp[i+1][j][pre+200].s);
			Node node=dp[i+1][j][pre+200];
			ans=(ans+(node.s+(_pow(i+1)*(sum%MOD)%MOD*(node.n%MOD)%MOD))%MOD)%MOD;
		}
	}
	//其他位
	for(int i=1;i<len;i++){
		for(int j=1;j<10;j++){
			Node node=dp[i][j][k+200];
			ans=(ans+node.s)%MOD;
		}
	}
	// determine n itself
	bool add=true;
	int tmp=0;
	for(int i=len-1;i>=0;i--,add=!add){
		if(add) tmp+=num[i];
		else tmp-=num[i];
	}
	if(tmp==k) ans=(n%MOD+ans)%MOD;
	return ans;
}

/*三位数中以0开头的数和二位数中不以0开头的数不能算作同一类数*/

int main(){
	freopen("data.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	scanf("%lld %lld %d",&l,&r,&k);
	// printf("l=%lld,r=%lld,k=%d\n",l,r,k);
	init();
	int b = solve(r);
	int a =	l==0?0:solve(l-1);
	// printf("a=%d,b=%d\n",a,b);
	printf("%d\n",(b-a+MOD)%MOD);
	// printf("[0,100]=%d\n",solve(100));
	// printf("[0,121]=%d\n",solve(121));
	// printf("%lld\n",dp[2][0][-1+200].s);
	// printf("dp[3][1][200].n=%lld,dp[3][1][200].s=%lld\n",dp[3][1][200].n,dp[3][1][200].s);
	return 0;
}