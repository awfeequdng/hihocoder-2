#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=3;
int num[9],op[9],tmp[9];

bool fill(){
    if(op[0]+op[1]+op[2]==15 && op[3]+op[4]+op[5]==15 && op[6]+op[7]+op[8]==15){
        if(op[0]+op[3]+op[6]==15 && op[1]+op[4]+op[7]==15 && op[2]+op[5]+op[8]==15){
            if(op[0]+op[4]+op[8]==15 && op[2]+op[4]+op[6]==15){
                return true;
            }else{  
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}
void solve(){
    rep(i,1,10) op[i-1]=i;
    int ans = 0;
    do{
        bool is_continue = false;
        rep(i,0,9) 
            if(num[i] && num[i]!=op[i]) is_continue = true;
        if(is_continue) continue;
        if(fill()){
            ans++;
            if(ans==1) memcpy(tmp,op,sizeof(int)*9);
            else break;
        }
    }while(next_permutation(op,op+9));

    if(ans==1){
        rep(i,0,9)
            printf("%d%c",tmp[i],(i+1)%3==0?'\n':' ');
    }
    else printf("Too Many\n");
}
int main(){
    freopen("data.txt","r",stdin);
    rep(i,0,9)
        scanf("%d",&num[i]);
    solve();
    return 0;
}