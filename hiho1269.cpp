#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

typedef long long ll;
const int MAXN=100003;
int n,num[MAXN],tmp[MAXN];
ll q;

bool ok(int mid){
    priority_queue<int> pq;
    int i=0,index=1;
    ll ans=0;
    while(i<mid){
        pq.push(num[i++]);
    }
    while(!pq.empty()){
        int t=pq.top();pq.pop();
        if(i<n){
            pq.push(num[i++]);
        }
        ans+=t*index;
        index++;
    }
    return ans<=q;
}
void solve(){
    ll ans = 0;
    // rep(i,0,n)
    //     ans+=num[i]*(i+1);
    // if(ans<=q){
    //     printf("0\n");
    //     return ;
    // }
    memcpy(tmp,num,4*n);
    sort(tmp,tmp+n);
    ans=0;
    rep(i,0,n)
        ans+=tmp[i]*(n-i);
    if(ans>q){
        printf("-1\n");
        return ;
    }
    int l=0,r=n;
    while(r-l>1){
        int mid = (l+r)/2;
        if(ok(mid)) r=mid;
        else l=mid;
    }
    printf("%d\n",r);   
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %lld",&n,&q);
    rep(i,0,n)
        scanf("%d",&num[i]);
    solve();
    return 0;
}