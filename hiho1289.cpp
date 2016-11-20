#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

struct Node{
    int type;//0,1,2 not match,allow,deny
    int index;//次序
    Node *l,*r;
    Node(int _type=0):type(_type),l(NULL),r(NULL){}
};
Node *root;
const int MAXN=100003;
int n,m;

void push(int t,int type,int index,int order){
    if(index==32 && root->type==0){
        root->type=type;
        root->index=order;
        return ;
    }
    Node *node = root;
    for(int i=31;i>=0;i--){
        int x = (t>>i)&1;
        if(x==0){
            if(node->l==NULL) node->l = new Node();
            node=node->l;
        }else{
            if(node->r==NULL) node->r = new Node();
            node=node->r;
        }
        //不覆盖以前的
        if(i==index && node->type==0){
            node->type=type;
            node->index=order;
            return ;
        }
    }
}
bool search(int t){
    int ans=-1,minV=MAXN;
    Node *node = root;
    if(root->type){
        ans=root->type;
        minV=root->index;
    }
    for(int i=31;i>=0;i--){
        int x = (t>>i)&1;
        if(x==0){
            node=node->l;
        }else{
            node=node->r;
        }
        if(node==NULL){
            return ans<2;
        }else if(node->type!=0){
            if(node->index<minV){
                minV=node->index;
                ans=node->type;
            }
        }
    }
    return ans<2;
}
int main(){
    freopen("data.txt","r",stdin);
    root = new Node();
    scanf("%d%d\n",&n,&m);
    char op[6];
    int a,b,c,d,mask;
    rep(i,0,n){
        scanf("%s",op);
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        char cc = getchar();
        if(cc!='\n'){
            scanf("%d\n",&mask);
        }
        int t = d+(c<<8)+(b<<16)+(a<<24);
        int type = strcmp(op,"allow")==0?1:2;
        push(t,type,0,i+1);
        push(t,type,32-mask,i+1);
    }
    rep(i,0,m){
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        int t = d+(c<<8)+(b<<16)+(a<<24);
        if(search(t)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}