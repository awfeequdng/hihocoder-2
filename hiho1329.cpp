#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

struct Node{
    int val;
    Node*l,*r,*p;
    Node(int _val):val(_val),l(NULL),r(NULL),p(NULL){}
};
Node*root=NULL;
void rotateLeft(Node*x){
    Node*p=x->p;
    Node*r=x->r;//r must be exist
    x->r = r->l;
    if(r->l) r->l->p=x;
    r->l=x;
    x->p=r;
    r->p=p;
    if(p){
        if(p->l && p->l==x) p->l=r;
        else p->r=r;
    }else{
        root = r;
    }
}
void rotateRight(Node*x){
    Node*p=x->p;
    Node*l=x->l;//r must be exist
    x->l = l->r;
    if(l->r) l->r->p=x;
    l->r=x;
    x->p=l;
    l->p=p;
    if(p){
        if(p->l && p->l==x) p->l=l;
        else p->r=l;
    }else{
        root = l;
    }
}

/* 将x伸展为y的子节点 */
void splay(Node*x,Node*y){
    Node *p,*g;
    p=x->p;
    while(p!=y && (g=p->p)!=y){
        if(g->l &&g->l==p){
            if(p->l && p->l==x){
                //左左
                rotateRight(g);
                rotateRight(p);
            }else{
                //左右
                rotateLeft(p);
                rotateRight(g);
            }
        }else{
            if(p->l && p->l==x){
                //右左
                rotateRight(p);
                rotateLeft(g);
            }else{
                //右右
                rotateLeft(g);
                rotateLeft(p);
            }
        }
        p=x->p;
    }
    if(p!=y){
        if(p->l && p->l==x){
            rotateRight(p);
        }else{
            rotateLeft(p);
        }
    }
}
Node* _search(Node*root,int num){
    Node* tmp;
    if(num < root->val){
        tmp=root->l;
    }else{
        tmp=root->r;
    }
    if(tmp==NULL || num==tmp->val){
        return root;
    }else{
        return _search(tmp,num);
    }
}
//返回num的父亲结点，若不存在也返回父亲结点
void search(int num){
    if(root==NULL || root->val==num) return ;
    Node* p = _search(root,num);
    // printf("num=%d,p->val=%d\n",num,p->val);
    //伸展
    if(p->l && p->l->val==num)
        splay(p->l,NULL);
    else if(p->r && p->r->val==num)
        splay(p->r,NULL);
    else{
        splay(p,NULL);
        // printf("\tsplay(p)\n");
    }
}
void insert(int num){
    if(root==NULL){
        root = new Node(num);
        return ;
    }
    search(num);
    // printf("num=%d,root->val=%d\n",num,root->val);
    Node*node = new Node(num);
    if(num<root->val){
        node->l=root->l;
        if(root->l) root->l->p=node;
        root->l=NULL;
        node->r=root;
        root->p=node;
        root=node;
    }else if(num>root->val){
        // printf("\tnum is > root\n");
        node->r=root->r;
        if(root->r) root->r->p=node;
        root->r=NULL;
        node->l=root;
        root->p=node;
        root=node;
    }else{
        return ;
    }
}
void del(int num){
    search(num);
    if(root->val!=num) return ;
    if(!root->l && !root->r){
        root=NULL;
    }else if(root->l){
        // printf("left is not null\n");
        // printf("root->val=%d\n",root->val);
        Node*node=root->l;
        while(node->r){
            node=node->r;
            // printf("node->r\n");
        }
        root->val=node->val;
        Node*p=node->p;
        if(p->l && p->l==node){
            p->l=node->l;
            if(node->l) node->l->p=p;
        }else{
            p->r=node->l;
            if(node->l) node->l->p=p;
        }
        delete node;
    }else{
        Node*node=root->r;
        while(node->l){
            node=node->l;
        }
        root->val=node->val;
        Node*p=node->p;
        if(p->l && p->l==node){
            p->l=node->r;
            if(node->r) node->r->p=p;
        }else{
            p->r=node->r;
            if(node->r) node->r->p=p;
        }
        delete node;
    }
}
int getMax(int k){
    search(k);
    if(root->val>=k) return root->val;
    Node*r=root->r;
    while(r->l){
        r=r->l;
    }
    return r->val;
}
int getMin(int k){
    search(k);
    if(root->val<=k) return root->val;
    Node*l=root->l;
    while(l->r){
        l=l->r;
    }
    return l->val;
}
Node* small(int k){
    search(k);
    if(root->val<k) return root;
    Node*l=root->l;
    if(l==NULL) return NULL;
    while(l->r){
        l=l->r;
    }
    return l;   
}
Node* big(int k){
    search(k);
    if(root->val>k) return root;
    Node*r=root->r;
    if(r==NULL) return NULL;
    while(r->l){
        r=r->l;
    }
    return r;   
}

void delSeg(int a,int b){
    Node* pre=small(a),*next=big(b);
    if(!pre && !next){
        root = NULL;
        return ;
    }else if(pre && !next){
        splay(pre,NULL);
        root->r=NULL;
    }else if(!pre && next){
        splay(next,NULL);
        root->l=NULL;
    }else{
        splay(pre,NULL);
        splay(next,root);
        next->l=NULL;
    }
}
void out(){
    printf("----------------------------------------\n");
    queue<Node*> q,p;
    q.push(root);
    while(!q.empty()){
        Node*node = q.front();q.pop();
        printf("%d ",node->val);
        if(node->l) p.push(node->l);
        if(node->r) p.push(node->r);
        if(q.empty()){
            printf("\n");
            while(!p.empty()){
                q.push(p.front());p.pop();
            }
        }
    }
}
int main(){
    freopen("data.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        char op;
        int a,b;
        cin>>op;
        if(op=='I'){
            cin>>a;
            insert(a);
            // out();
            // printf("op=insert,a=%d\n",a);
        }else if(op=='Q'){
            cin>>a;
            printf("%d\n",getMin(a));
            // printf("op=query,a=%d\n",a);
        }else{
            cin>>a>>b;
            delSeg(a,b);
            // printf("op=delete,a=%d,b=%d\n",a,b);
        }
    }
    return 0;
}