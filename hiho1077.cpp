#include <bits/stdc++.h>
using namespace std;
#define INF 100000
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=1000003;
int n,q,dat[MAXN<<2];

void init(int _n){
    n=1;
    while(n<_n) n*=2;
    rep(i,0,2*n-1) dat[i]=INF;
}
void update(int k,int a){
    dat[k]=a;
    while(k>0){
        k=(k-1)/2;
        dat[k]=min(dat[2*k+1],dat[2*k+2]);
    }
}
int query(int a,int b,int k,int l,int r){
    if(b<=l || r<=a) return INF;
    if(a<=l && r<=b) return dat[k];
    return min(query(a,b,2*k+1,l,(l+r)/2),query(a,b,2*k+2,(l+r)/2,r));
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&n);
    int nn=n,x;
    init(n);
    rep(i,0,nn){
        scanf("%d",&x);
        update(n-1+i,x);
    }
    // rep(i,0,2*n-1)
    //     printf("i=%d,dat[i]=%d\n",i,dat[i]);
    scanf("%d",&q);
    while(q--){
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        l--;
        if(t==0){
            printf("%d\n",query(l,r,0,0,n));
        }else{
            update(l+n-1,r);
        }   
    }
    return 0;
}