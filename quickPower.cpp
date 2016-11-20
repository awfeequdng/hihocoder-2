#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat &a,mat &b){
    mat c(a.size(),vec(b[0].size()));
    for(int j=0;j<b[0].size();j++){
        for(int k=0;k<a.size();k++){
            for(int i=0;i<a[k].size();i++){
                c[k][j]=(c[k][j]+a[k][i]*b[i][j])%MOD;
            }
        }
    }
    return c;
}
mat getPower(mat &m,int &n){
    mat ans(m.size(),vec(m.size()));
    for(int i=0;i<ans.size();i++)
        ans[i][i]=1;
    while(n){
        if(n&1) ans = mul(ans,m);
        m=mul(m,m);
        n>>=1;
    }
    return ans;
}
int main(){

    for(int i=0;i<20;i++){
        int n=i;
        mat m(2,vec(2,1));
        m[1][1]=0;
        m = getPower(m,n);
        mat s(2,vec(1));
        s[0][0]=1;
        s[1][0]=0;
        mat ans = mul(m,s);
        printf("%d ",ans[1][0]);
    }
    printf("\n");
    return 0;
}