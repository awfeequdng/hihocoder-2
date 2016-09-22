#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

struct Node{
    int l,r;
};
const int MAXN=100003;
int n,l;
Node nodes[MAXN];
int dat[8*MAXN],nn;
vector<int> num;

void init(int _n){
    nn=1;
    while(nn<_n) nn*=2;
    rep(i,0,2*nn-1) dat[i]=-1;
}
void pushDown(int k){
    if(dat[k]==-1) return ;
    if(2*k+1>=2*nn-1) return ;
    dat[2*k+1]=dat[k];
    dat[2*k+2]=dat[k];
    dat[k]=-1;
}
void updateSeg(int a,int b,int x,int k,int l,int r){
    if(b<=l || r<=a) return ;
    if(a<=l && r<=b){
        dat[k]=x;
    }else{
        pushDown(k);
        updateSeg(a,b,x,2*k+1,l,(l+r)/2);
        updateSeg(a,b,x,2*k+2,(l+r)/2,r);
    }
}
void sum(int k,set<int>&s){
    if(dat[k]==-1){
        if(2*k+1>=2*nn-1) return ;
        sum(2*k+1,s);
        sum(2*k+2,s);
    }else{
        s.insert(dat[k]);
    }
}
void out(){
    int i=0,k=1;
    while(i<2*nn-1){
        rep(j,0,k) printf("%d ",dat[i++]);
        printf("\n");
        k*=2;
    }
}
void solve(){
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    init(num.size()-1);
    // printf("nn=%d\n",nn);
    rep(i,0,n){
        int l = lower_bound(num.begin(),num.end(),nodes[i].l)-num.begin();
        int r = lower_bound(num.begin(),num.end(),nodes[i].r)-num.begin();
        updateSeg(l,r,i,0,0,nn);
        // printf("i=%d\n",i);
        // out();
    }
    // out();

    set<int>s;
    sum(0,s);
    printf("%d\n",s.size());
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d%d",&n,&l);
    rep(i,0,n){
        scanf("%d%d",&nodes[i].l,&nodes[i].r);
        num.push_back(nodes[i].l);
        num.push_back(nodes[i].r);
    }
    solve();
    return 0;
}