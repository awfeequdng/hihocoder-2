#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int n,m,L,l,r,t,b;
 
int solve(){
	int ww=r-l,hh=b-t;
	r=m-r,b=n-b;
	int w=max(l,r),h=max(t,b),ans=0;
	// printf("hh=%d,ww=%d\n",hh,ww);
	// printf("w=%d,h=%d\n",w,h);
	rep(i,0,n+1){
		rep(j,0,m+1){
			if(2*(i+j)<=L){
				int sub=0;
				if(i-h<=0 || j-w<=0){
					sub=0;
				}else{
					int _h=i-h,_w=j-w;
					if(_h>=hh && _w>=ww){
						sub=hh*ww;
					}else{
						sub=_h*_w;
					}
					// printf("_h=%d,_w=%d\n",_h,_w);
					// _h = (_h>hh)?hh:_h,_w=(_w>ww)?ww:_w;
					// printf("_h=%d,_w=%d\n",_h,_w);
					// sub=_h*_w;
				}
				int tmp = i*j-sub;
				// printf("i=%d,j=%d,tmp=%d,sub=%d\n",i,j,tmp,sub);
				if(tmp>ans) ans=tmp;
			}
		}
	}
	return ans;
}
int main(int argc, char const *argv[]){
	freopen("data.txt","r",stdin);
	scanf("%d%d%d%d%d%d%d",&n,&m,&L,&l,&r,&t,&b);
	printf("%d\n",solve());
	return 0;
}