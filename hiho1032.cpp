/*最长回文子串*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN=1000003;
int maxRight=0,pos=0;
int rl[MAXN*2];
char s[MAXN],p[MAXN*2];

int solve(){
	int sl=strlen(s);
	for(int i=0;i<sl;i++){
		p[(i<<1)+1]=s[i];
	}
	//计算
	int pl=sl*2+1,maxV=-1;
	maxRight=-1,pos=-1;
	for(int i=0;i<pl;i++){
		if(i>=maxRight)
			rl[i]=1;
		else
			rl[i]=min(rl[2*pos-i],maxRight-i);
		//扩展
		int left=i-rl[i],right=i+rl[i];
		while(left>=0 && right<pl && p[left]==p[right]){
			left--,right++,rl[i]++;
		}
		if(i+rl[i]-1>maxRight){
			maxRight=i+rl[i]-1;
			pos=i;
		}
		maxV=max(maxV,rl[i]);
	}
	return maxV-1;
}

int main(){
	freopen("data.txt","r",stdin);
	int n;
	scanf("%d\n",&n);
	for(int i=0;i<MAXN*2;i++)
		p[i]='$';
	while(n--){
		scanf("%s",s);
		printf("%d\n",solve());
	}
	return 0;
}