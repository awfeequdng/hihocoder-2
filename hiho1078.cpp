/* 线段树区间更新 */
#include <bits/stdc++.h>
using namespace std;
#define INF 100000
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=1000003;
int n,q,dat[MAXN<<2],layer[MAXN<<2];

void init(int _n){
    n=1;
    while(n<_n) n*=2;
    rep(i,0,2*n-1){
        dat[i]=0;
        layer[i]=-1;
    }
}
void pushDown(int k){
    if(layer[k]==-1) return ;
    if(2*k+1>=2*n-1){
        layer[k]=-1;
    }else{
        dat[2*k+1]=dat[2*k+2]=dat[k]/2;
        layer[2*k+1]=layer[2*k+2]=layer[k];
        layer[k]=-1;
    }
}
void updateSeg(int a,int b,int x,int k,int l,int r){
    // printf("a=%d,b=%d,x=%d,k=%d,l=%d,r=%d\n",a,b,x,k,l,r);
    if(b<=l || r<=a) return ;
    if(a<=l && r<=b){
        // printf("==\n");
        dat[k]=x*(r-l);
        layer[k]=x;
    }
    else{
        pushDown(k);
        updateSeg(a,b,x,2*k+1,l,(l+r)/2);
        updateSeg(a,b,x,2*k+2,(l+r)/2,r);
        dat[k]=dat[2*k+1]+dat[2*k+2];
    }
}
int query(int a,int b,int k,int l,int r){
    if(b<=l || r<=a) return 0;
    if(a<=l && r<=b){
        return dat[k];
    }
    pushDown(k);
    return query(a,b,2*k+1,l,(l+r)/2)+query(a,b,2*k+2,(l+r)/2,r);
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&n);
    int nn=n,x;
    init(n);
    rep(i,0,nn){
        scanf("%d",&x);
        updateSeg(i,i+1,x,0,0,n);
    }
    // printf("--------------------\n");
    scanf("%d",&q);
    while(q--){
        int t,l,r;
        scanf("%d",&t);
        if(t==0){
            scanf("%d%d",&l,&r);
            printf("%d\n",query(l-1,r,0,0,n));
        }else{
            int p;
            scanf("%d%d%d",&l,&r,&p);
            updateSeg(l-1,r,p,0,0,n);
        }   
    }
    // out();
    return 0;
}