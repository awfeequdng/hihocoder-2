#include <bits/stdc++.h>
using namespace std; 
#define rep(i,a,b) for(int i=a;i<b;i++)

struct Node{
    int x;
    int type;//0,1,2,3,4  X <=,<,=,>,>=
};
const int MAXN=53;
int n;
Node nodes[MAXN];

void solve(){
    int ans=-1;
    for(double i=-0.5;i<=1000.5;i+=0.5){
        int tmp=0;
        for(int j=0;j<n;j++){
            switch(nodes[j].type){
                case 0:tmp+=(i<=nodes[j].x);break;
                case 1:tmp+=(i<nodes[j].x);break;
                case 2:tmp+=(i==nodes[j].x);break;
                case 3:tmp+=(i>nodes[j].x);break;
                case 4:tmp+=(i>=nodes[j].x);break;
            }
        }
        if(tmp>ans) ans=tmp;
    }
    printf("%d\n",ans);
}
int main(){
    freopen("data.txt","r",stdin);
    // scanf("%d",&n);
    cin>>n;
    rep(i,0,n){
        char C;
        cin>>C;
        string op;
        cin>>op>>nodes[i].x;
        if(op=="<=") nodes[i].type=0;
        if(op=="<") nodes[i].type=1;
        if(op=="=") nodes[i].type=2;
        if(op==">") nodes[i].type=3;
        if(op==">=") nodes[i].type=4;      
    }
    solve();
    return 0;
}