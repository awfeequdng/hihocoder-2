/*
 * 构造状态时要自己构造好无后效性的状态方程
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=103;
int n,m,num[MAXN][MAXN];

void solve(){
    
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d%d",&n,&m);
    rep(i,0,n){
        getchar();
        rep(j,0,m){
            char c;
            scanf("%c",&c);
            num[i][j]=c=='.'?0:1;
        }
    }
    solve();
    printf("%d\n",);
    return 0;
}