/* SBTree */
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val,sz;
    Node *l,*r,*p;
    Node(int _val):val(_val),sz(1),l(NULL),r(NULL),p(NULL){}
};
Node*root;
void out(){
    printf("-----------------BEGIN-----------------------\n");
    queue<Node*> q,p;
    if(!root) return ;
    q.push(root);
    while(!q.empty()){
        Node*node = q.front();q.pop();
        printf("%d-%d ",node->val,node->sz);//id,val,sum,add
        if(node->l) p.push(node->l);
        if(node->r) p.push(node->r);
        if(q.empty()){
            printf("\n");
            while(!p.empty()){
                q.push(p.front());p.pop();
            }
        }
    }
    printf("-----------------END-----------------------\n");
}
Node* _search(Node*root,int num){
    if(num<root->val){
        if(!root->l) return root;
        if(root->l->val==num) return root;
        return _search(root->l,num);
    }else{
        if(!root->r) return root;
        if(root->r->val==num) return root;
        return _search(root->r,num);
    }
}
Node* search(int num){
    if(!root || root->val==num) return NULL;
    return _search(root,num);
}
void rotateRight(Node *node){
    Node *chd=node->l,*p=node->p;
    node->l=chd->r;
    if(chd->r) chd->r->p=node;
    chd->r=node;
    node->p=chd;
    if(!p) root=chd;
    else if(p->l && p->l==node) p->l=chd;
    else p->r=chd;
}
void rotateLeft(Node *node){
    Node *chd=node->r,*p=node->p;
    node->r=chd->l;
    if(chd->l) chd->l->p=node;
    chd->l=node;
    node->p=chd;
    if(!p) root=chd;
    else if(p->l && p->l==node) p->l=chd;
    else p->r=chd;
}
void maintain(Node* node){
    printf("node->val=%d\n",node->val);
    node->sz=1;
    if(node->l) node->sz+=node->l->sz;
    if(node->r) node->sz+=node->r->sz;
    int l=0,r=0;
    if(node->l) l=node->l->sz;
    if(node->r) r=node->r->sz;
    Node *p = node->p;
    if(l-r>1){
        printf("rotateRight\n");
        rotateRight(node);
    }else if(r-l>1){
        printf("rotateLeft\n");
        rotateLeft(node);
    }
    if(p) maintain(p);
}
void insert(int num){
    if(!root){
        root = new Node(num);
        return ;
    }
    Node *node = search(num);
    if(node->l && node->l->val==num)
        return ;
    if(node->r && node->r->val==num)
        return ;
    Node *tmp = new Node(num);
    if(num<node->val)
        node->l = tmp;
    else
        node->r = tmp;
    tmp->p = node;
    maintain(node);
}

int main(){
    freopen("data.txt","r",stdin);
    freopen("out.txt","w",stdout);
    insert(5);
    out();
    insert(3);
    out();
    insert(9);
    out();
    insert(2);
    out();
    insert(4);
    out();
    insert(1);
    out();
    return 0;
}