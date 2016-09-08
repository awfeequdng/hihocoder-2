#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=20002;
int xx,yy,zz;
char s[MAXN];

void swap(int &x,int &y){
	int t=x;
	x=y;
	y=t;
}
void order(int&x,int&y,int&z){
	if(y<x) swap(x,y);
	if(z<x) swap(x,z);
	if(z<y) swap(y,z);
}
int solve(){
	char cc;
	int r=0,y=0,b=0,cnt=0,maxV=0;
	int c,d,e,l=strlen(s);
	rep(i,0,l){
		char cc=s[i];
		cnt++;
		if(cnt>maxV) maxV=cnt;
		if(cc=='R') r++;
		else if(cc=='Y') y++;
		else if(cc=='B') b++;
		c=abs(r-y);
		d=abs(r-b);
		e=abs(b-y);
		order(c,d,e);
		if(c==xx&&d==yy&&e==zz){
			cnt=0,r=0,y=0,b=0;
		}
	}
	return maxV;
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d%d%d\n",&xx,&yy,&zz);
	order(xx,yy,zz);
	scanf("%s",s);
	printf("%d\n",solve());
	return 0;
}