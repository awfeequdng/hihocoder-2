#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=100003;
int n,m,dat[MAXN<<2],add[MAXN<<2],reset[MAXN<<2],nn;

void init(int _n){
    nn=1;
    while(nn<_n) nn*=2;
    rep(i,0,2*nn-1)
        dat[i]=add[i]=reset[i]=0;
}
void pushDown(int k,int sz){
    if(reset[k]==0 && add[k]==0) return ;
    if(reset[k] && add[k]){
        dat[2*k+1]=dat[2*k+2]=dat[k]/2;
        reset[2*k+1]=reset[2*k+2]=reset[k];
        reset[k]=0;
        add[2*k+1]+=add[k];
        add[2*k+2]+=add[k];
        add[k]=0;
    }else if(reset[k]){
        dat[2*k+1]=dat[2*k+2]=dat[k]/2;
        reset[2*k+1]=reset[2*k+2]=reset[k];
        reset[k]=0;
    }else{
        dat[2*k+1]+=add[k]*(sz/2);
        dat[2*k+2]+=add[k]*(sz/2);
        add[2*k+1]+=add[k];
        add[2*k+2]+=add[k];
        add[k]=0;
    }
}
void updateSeg(int a,int b,int x,int k,int l,int r,int flag){//flag=1 is add,2 is reset
    if(b<=l || r<=a) return ;
    if(a<=l && r<=b){
        if(flag==1){
            dat[k]+=(r-l)*x;
            add[k]+=x;
            // reset[k]=0;
        }else{
            dat[k]=(r-l)*x;
            reset[k]=x;
            add[k]=0;
        }
    }else{
        pushDown(k,r-l);
        updateSeg(a,b,x,2*k+1,l,(l+r)/2,flag);
        updateSeg(a,b,x,2*k+2,(l+r)/2,r,flag);
        dat[k]=dat[2*k+1]+dat[2*k+2];
    }
}
int query(int a,int b,int k,int l,int r){
    if(b<=l || r<=a) return 0;
    if(a<=l && r<=b){
        return dat[k];
    }else{
        pushDown(k,r-l);
        return query(a,b,2*k+1,l,(l+r)/2)+query(a,b,2*k+2,(l+r)/2,r);
    }
}
// void out(){
//     printf("========================================\n");
//     int i=0,k=1;
//     while(i<2*nn-1){
//         rep(j,0,k) printf("%d ",dat[i++]);
//         printf("\n");
//         k*=2;
//     }
// }
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d",&n,&m);
    n++;
    init(n);
    rep(i,0,n){
        int x;
        scanf("%d",&x);
        updateSeg(i,i+1,x,0,0,nn,2);
    } 
    // out();
    rep(i,0,m){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a==0){//add
            updateSeg(b,c+1,d,0,0,nn,1);
            printf("%d\n",query(0,nn,0,0,nn));
            // out();
        }else{
            updateSeg(b,c+1,d,0,0,nn,2);
            printf("%d\n",query(0,nn,0,0,nn));
            // out();
        }
    }
    return 0;
}