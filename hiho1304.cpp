#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int n,num[4],x;

bool ok1(int a,int b,int c,int d){
    rep(i,0,6){
        rep(j,0,6){
            rep(k,0,6){
                double tmp=0;
                switch(i){
                    case 0:tmp=a+b;break;
                    case 1:tmp=a-b;break;
                    case 2:tmp=a*b;break;
                    case 3:tmp=a/(double)b;break;
                    case 4:tmp=b-a;break;
                    case 5:tmp=b/(double)a;break;
                }
                switch(j){
                    case 0:tmp+=c;break;
                    case 1:tmp-=c;break;
                    case 2:tmp*=c;break;
                    case 3:tmp/=c;break;
                    case 4:tmp=c-tmp;break;
                    case 5:tmp=c/tmp;break;
                }
                switch(k){
                    case 0:tmp+=d;break;
                    case 1:tmp-=d;break;
                    case 2:tmp*=d;break;
                    case 3:tmp/=d;break;
                    case 4:tmp=d-tmp;break;
                    case 5:tmp=d/tmp;break;
                }
                if(tmp==24){
                    // printf("first:i=%d,j=%d,k=%d\n",i,j,k);
                    return true;
                }
            }
        }
    }
    return false;
}
bool ok2(int a,int b,int c,int d){
    rep(i,0,6){
        rep(j,0,6){
            rep(k,0,6){
                double tmp1=0,tmp2=0,tmp=0;
                switch(i){
                    case 0:tmp1=a+b;break;
                    case 1:tmp1=a-b;break;
                    case 2:tmp1=a*b;break;
                    case 3:tmp1=a/(double)b;break;
                    case 4:tmp1=b-a;break;
                    case 5:tmp1=b/(double)a;break;
                }
                switch(k){
                    case 0:tmp2=c+d;break;
                    case 1:tmp2=c-d;break;
                    case 2:tmp2=c*d;break;
                    case 3:tmp2=c/(double)d;break;
                    case 4:tmp2=d-c;break;
                    case 5:tmp2=d/(double)c;break;
                }
                switch(j){
                    case 0:tmp=tmp1+tmp2;break;
                    case 1:tmp=tmp1-tmp2;break;
                    case 2:tmp=tmp1*tmp2;break;
                    case 3:tmp=tmp1/tmp2;break;
                    case 4:tmp=tmp2-tmp1;break;
                    case 5:tmp=tmp2/tmp1;break;
                }
                if(tmp==24){
                    // printf("second:i=%d,j=%d,k=%d\n",i,j,k);
                    return true;
                }
            }
        }
    }
    return false;
}
bool solve(){
    rep(a,0,4){
        rep(b,0,4){
            if(a==b) continue;
            rep(c,0,4){
                if(a==c || b==c) continue;
                rep(d,0,4){
                    if(a==d || b==d || c==d) continue;
                    if(ok1(num[a],num[b],num[c],num[d]) || ok2(num[a],num[b],num[c],num[d])){
                        // printf("%d %d %d %d\n",num[a],num[b],num[c],num[d]);
                        return true;
                    }
                    // printf("%d %d %d %d\n",num[a],num[b],num[c],num[d]);
                }
            }
        }
    }
    return false;
}
int main(){
    freopen("data.txt","r",stdin);
    cin>>n;
    while(n--){
        cin>>num[0]>>num[1]>>num[2]>>num[3];
        if(solve()) printf("Yes\n");
        else printf("No\n");
    }
    // bool x = ok(1,5,5,5);
    // printf("%d\n",x);
    return 0;
}