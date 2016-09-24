#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int x;
int count(int x){
    int t=0;
    while(x){
        t+=(x&1);
        x>>=1;
    }
    return t;
}
void out(int x){
    int hour=x>>6,minute=x&63;
    if(hour>=24 || minute>=60) return ;
    printf("%02d:%02d\n",hour,minute);
}
int main(){
    // freopen("data.txt","r",stdin);
    scanf("%d",&x);
    rep(i,0,1<<12){
        if(count(i)==x){
            out(i);
        }
    }
    return 0;
}