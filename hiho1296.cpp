#include <cstdio>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int n,k;

int solve(int n){
    if(n==1) return 0;
    if(n<=k){
        return (solve(n-1)+k)%n;
    }else{
        int ans = solve(n-n/k);
        if(ans<n%k) return ans+n-n%k;
        return ans-n%k+(ans-n%k)/(k-1);
    }
    return 1;
}
int main(){
    freopen("data.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        printf("%d\n",solve(n));
    }
    return 0;
}