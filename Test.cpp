<<<<<<< HEAD
=======
/*  测试从新电脑提交    */
>>>>>>> 3a750285d93a15108dc456afcaa30704cb53fd2f
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=3;

int main(){
    freopen("data.txt","r",stdin);
    int num[] = {4,1,2,3};
    while(next_permutation(num,num+4)){
        rep(i,0,4)
            printf("%d ",num[i]);
        printf("\n");
    }
    return 0;
}
