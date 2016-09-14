/* 堆(h)的作用是保持二叉树的结构，防止二叉树退化 */
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=100002;
struct Node{
    int k,h;
    Node *l,*r,*p;
    Node(){}
    Node(int kk):k(kk){
        h=(int)((rand()/(double)RAND_MAX)*MAXN);//[0,n]
        l=NULL,r=NULL,p=NULL;
    }
};
int n;
Node *root;
bool _insert(Node*root,Node*node){
    if(root->k == node->k) return false;
    if(node->k<root->k){
        if(root->l==NULL){
            root->l=node;
            node->p=root;
            return true;
        }else{
            return _insert(root->l,node);
        }
    }else{
        if(root->r==NULL){
            root->r=node;
            node->p=root;
            return true;
        }else{
            return _insert(root->r,node);
        }
    }
}
void rotate(Node* node){
    Node*p=node->p,*g;
    while(p!=root && p->h>node->h){
        g=p->p;
        if(p->l && p->l==node){
            p->l = node->r;
            if(node->r) node->r->p=p;
            node->r=p;
            p->p=node;
            node->p=g;
        }else{
            p->r = node->l;
            if(node->l) node->l->p=p;
            node->l=p;
            p->p=node;
            node->p=g;
        }
        if(g->l && g->l==p) g->l=node;
        else g->r=node;
        p = node->p;
    }
    if(p->h>node->h){
        if(p->l && p->l==node){
            p->l = node->r;
            if(node->r) node->r->p=p;
            node->r=p;
            p->p=node;
            node->p=g;
        }else{
            p->r = node->l;
            if(node->l) node->l->p=p;
            node->l=p;
            p->p=node;
            node->p=g;
        }
        root = node;
    }
}
void insert(int x){
    Node *node = new Node(x);
    if(root==NULL){
        root = node;
    }else{
        if(!_insert(root,node)) return ;
        rotate(node);
    }
}
// void inOrder(Node*root){
//     if(root->l) inOrder(root->l);
//     printf("%d ",root->k);
//     if(root->r) inOrder(root->r);
// }
int search(int x){
    Node*node=root;
    while(true){
        if(node->k==x) return x;
        if(x<node->k){
            if(node->l){
                node=node->l;
            }else{
                break;
            }
        }else{
            if(node->r){
                node=node->r;
            }else{
                return node->k;
            }
        }
    }
    Node *p = node->p;
    while(true){
        if(p->r && p->r==node) return p->k;
        node=p;
        p=p->p;
    }
    return -1;
}
int main(){
    freopen("data.txt","r",stdin);
    srand(time(NULL));
    scanf("%d",&n);
    rep(i,0,n){
        getchar();
        char op;
        int x;
        scanf("%c %d",&op,&x);
        if(op=='I'){
            insert(x);
        }else{
            printf("%d\n",search(x));
        }
    }
    // inOrder(root);
    return 0;
}