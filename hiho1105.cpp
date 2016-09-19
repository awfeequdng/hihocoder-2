#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=100003;
int n,heap[MAXN],cnt;

void insert(int x){
    int i = cnt++;
    while(i>0){
        if(heap[(i-1)/2]>=x) break;
        heap[i]=heap[(i-1)/2];
        i = (i-1)/2;
    }
    heap[i]=x;
}
int pop(){
    int ans=heap[0];
    int x = heap[--cnt];
    int i=0;
    while(2*i+1<cnt){
        int a=2*i+1,b=2*i+2;
        if(b<cnt && heap[b]>heap[a]) a=b;
        if(heap[a]<=x) break;
        heap[i]=heap[a];
        i=a;
    }
    heap[i]=x;
    return ans;
}

int main(){
    freopen("data.txt","r",stdin);
    scanf("%d",&n);
    rep(i,0,n){
        getchar();
        char op; 
        int x;
        scanf("%c",&op);
        if(op=='A'){
            scanf("%d",&x);
            // printf("x=%d\n",x);
            insert(x);
        }else{
            printf("%d\n",pop());
        }
    }
    // rep(i,0,n){
    //     printf("%d%c",heap[i],i==n-1?'\n':' ');
    // }
    return 0;
}