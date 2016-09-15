//水题
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=1003;
int n,num[MAXN];

void solve(){
    int i=n-1;
    while(i-1>=0 && num[i]>num[i-1]){
        i--;
    }
    if(i==0){
        printf("%d\n",num[0]);
    }else{
        for(int j=0;j<=i-1;j++){
            printf("%d%c",num[j],j==i-1?'\n':' ');
        }
    }
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&n);
    rep(i,0,n)
        scanf("%d",&num[i]);
    solve();
    return 0;
}