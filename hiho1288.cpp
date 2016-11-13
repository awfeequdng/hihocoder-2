/* 二分搜索 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=1003;
int t,n,p,w,h,num[MAXN];

bool ok(int s){
    int line = w/s,ans=0;
    rep(i,0,n){
        ans+=(num[i]+line-1)/line;
    }
    return ans<=p*(h/s);
}
void solve(){
    int l=1,r=w+1;
    while(true){
        if(r-l<=1) break;
        int mid = (l+r)/2;
        if(ok(mid)){
            l=mid;
        }else{
            r=mid;
        }
    }
    printf("%d\n",l);
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&t);
    rep(i,0,t){
        scanf("%d%d%d%d",&n,&p,&w,&h);
        rep(j,0,n)
            scanf("%d",&num[j]);
        solve();
    }
    return 0;
}