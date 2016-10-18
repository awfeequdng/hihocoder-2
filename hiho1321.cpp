/*深度优先搜索求解数独*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int n=9;
int num[n][n],appear[27][9];//row,col,square

void update(int i,int j){
    appear[i][num[i][j]-1]=1;
    appear[j+9][num[i][j]-1]=1;
    int a=i/3,b=j/3;
    appear[a*3+b+18][num[i][j]-1]=1;
}
void un_update(int i,int j){
    appear[i][num[i][j]-1]=0;
    appear[j+9][num[i][j]-1]=0;
    int a=i/3,b=j/3;
    appear[a*3+b+18][num[i][j]-1]=0;
}
bool dfs(int i,int j){
    // printf("i=%d,j=%d\n",i,j);
    if(j>=n || i>=n) return true;
    bool ok=true;
    int ii=i,jj=j+1;
    if(jj==n){
        jj=0;
        ii++;
    }
    for(;ii<n;ii++){
        for(;jj<n;jj++){
            if(!num[ii][jj]){
                ok=false;
            }
            if(!ok) break;
        }
        if(!ok) break;
        jj=0;
    }
    // printf("ii=%d,jj=%d\n",ii,jj);
    rep(k,1,10){
        bool notok=false;
        if(appear[i][k-1]) notok=true;
        if(appear[j+9][k-1]) notok=true;
        int a=i/3,b=j/3;
        if(appear[a*3+b+18][k-1]) notok=true;
        if(!notok){
            // printf("--\n");
            num[i][j]=k;
            update(i,j);
            bool res = dfs(ii,jj);
            if(res){
                return true;
            }else{
                un_update(i,j);
                num[i][j]=0;
            }
        }
    }
    return false;
}
void solve(){
    bool ok=true;
    int i=0,j=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(!num[i][j]){
                ok=false;
            }
            if(!ok) break;
        }
        if(!ok) break;
    }
    
    bool res = dfs(i,j);
    // if(res) printf("true\n");
    // else printf("false\n");
    rep(i,0,n)
        rep(j,0,n)
            printf("%d%c",num[i][j],j==n-1?'\n':' ');
}
int main(){
    freopen("data.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        rep(i,0,n)
            rep(j,0,n){
                scanf("%d",&num[i][j]);
                if(num[i][j]) update(i,j);
            }
        solve();
        rep(i,0,27)
            memset(appear[i],0,9*sizeof(int));
    }
    return 0;
}