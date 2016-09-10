#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

struct Node{
    char val;
    Node*l,*r;
    Node(char _val='#'):val(_val){}
};
const int MAXN=27;
char pre[MAXN],in[MAXN];
int l;
Node *root;

Node* build(int l1,int r1,int l2,int r2){
    if(l1>r1) return NULL;
    Node*node = new Node(pre[l1]);
    int index=l2;
    while(in[index]!=pre[l1]) index++;
    node->l = build(l1+1,l1+index-l2,l2,index-1);
    node->r = build(l1+index-l2+1,r1,index+1,r2);
    return node;
}
void post(Node*root){
    if(root->l) post(root->l);
    if(root->r) post(root->r);
    printf("%c",root->val);
}
void solve(){
    root = build(0,l-1,0,l-1);
    post(root);
}

int main(){
    freopen("data.txt","r",stdin);
    scanf("%s",pre);
    scanf("%s",in);
    l=strlen(pre);
    solve();
    return 0;
}