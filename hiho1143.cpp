//矩阵快速幂求菲波那切数列
#include <bits/stdc++.h>
using namespace std;
#define MOD 19999997
typedef long long ll;

typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat&a,mat&b){
    mat c(a.size(),vec(b[0].size()));
    for(int k=0;k<b[0].size();k++){
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                c[i][k]=(c[i][k]+a[i][j]*b[j][k])%MOD;
            }
        }
    }
    return c;
}
mat getPower(mat&a,int n){
    mat c(a.size(),vec(a[0].size()));
    for(int i=0;i<c.size();i++)
        c[i][i]=1;
    while(n){
        if(n&1) c = mul(c,a);
        a=mul(a,a);
        n>>=1;
    }
    return c;
}
int main(){
    freopen("data.txt","r",stdin);
    // for(int k=0;k<20;k++){
        int n;
        scanf("%d",&n);
        n++;
        // n++;
        mat s(1,vec(2));
        s[0][0]=1,s[0][1]=0;
        mat a(2,vec(2,1));
        a[1][1]=0;
        a = getPower(a,n);
        mat ans = mul(s,a);
        printf("%lld\n",ans[0][1]);
        
    // }
    return 0;
}