#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

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
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d%d%d\n",&xx,&yy,&zz);
	order(xx,yy,zz);
	char cc;
	int r=0,y=0,b=0,cnt=0,maxV=0;
	int c,d,e;
	while(scanf("%c",&cc)==1){
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
	printf("%d\n",maxV);
	return 0;
}