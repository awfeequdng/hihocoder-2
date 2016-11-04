#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=102;
char s[MAXN];
int dp[MAXN][MAXN];

void solve(){
    int l = strlen(s);
    for(int i=l-1;i>=0;i--){
        for(int j=0;j<l;j++){
            if(i<j){
                dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1;
                dp[i][j] = min(dp[i][j],dp[i+1][j-1]+(s[i]==s[j]?0:1));
            }
        }
    }
    printf("%d\n",dp[0][l-1]);
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%s",s);
    solve();
    return 0;
}