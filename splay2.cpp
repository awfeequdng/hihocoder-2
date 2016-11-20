#include <bits/stdc++.h>
using namespace std;

struct Node{
    int id,val,sum,add;
    Node *l,*r,*p;
    Node (int _id,int _val):id(_id),val(_val),sum(val),add(0),l(NULL),r(NULL),p(NULL){}
};
Node *root;
void out(){
    printf("-----------------BEGIN-----------------------\n");
    queue<Node*> q,p;
    if(!root) return ;
    q.push(root);
    while(!q.empty()){
        Node*node = q.front();q.pop();
        printf("%d-%d-%d ",node->id,node->val,node->sum);//id,val,sum,add
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
void update(Node *node){
    node->sum=node->val;
    if(node->l) node->sum+=node->l->sum;
    if(node->r) node->sum+=node->r->sum;
}
void rotateLeft(Node *node){
    Node* child = node->r,*p=node->p;
    node->r = child->l;
    if(child->l) child->l->p=node;
    child->l=node;
    node->p=child;
    child->p=p;
    update(node);
    update(child);
    if(!p){
        root=child;
    }else{
        if(p->l && p->l==node) p->l=child;
        else p->r=child;
    }
}
void rotateRight(Node *node){
    Node* child = node->l,*p=node->p;
    node->l = child->r;
    if(child->r) child->r->p=node;
    child->r=node;
    node->p=child;
    child->p=p;
    update(node);
    update(child);
    if(!p){
        root=child;
    }else{
        if(p->l && p->l==node) p->l=child;
        else p->r=child;
    }

}
void splay(Node *node,Node *root){
    Node *p,*g;
    while((p=node->p)!=root && (g=p->p)!=root){
        if(g->l && g->l==p){//左
            if(p->l && p->l==node){
                rotateRight(g);
                rotateRight(p);
            }else{
                rotateLeft(p);
                rotateRight(g);
            } 
        }else{
            if(p->l && p->l==node){
                rotateRight(p);
                rotateLeft(g);
            }else{
                rotateLeft(g);
                rotateLeft(p);
            } 
        }
    }
    if(p!=root){
        if(p->l && p->l==node) rotateRight(p);
        else rotateLeft(p);
    }
}
void search(int id){
    if(root==NULL) return ;
    Node *node=root;
    while(true){
        if(id<node->id){
            if(node->l) node=node->l;
            else break;
        }else if(id>node->id){
            if(node->r) node=node->r;
            else break;
        }else{
            break;
        }
    }
    splay(node,NULL);
}
void insert(int id,int val){
    if(root==NULL){
        root = new Node(id,val);
        return ;
    }
    search(id);
    if(root->id==id) return ;
    Node *node = new Node(id,val);
    if(id<root->id){
        node->l=root->l;
        if(root->l) root->l->p = node;
        root->l=NULL;
        node->r=root;
    }else{
        node->r=root->r;
        if(root->r) root->r->p = node;
        root->r=NULL;
        node->l=root;
    }
    root->p=node;
    update(root);
    update(node);
    root=node;
}
Node* getLess(int id){
    search(id);
    if(root->id<id) return root;
    Node*node=root->l;
    if(!node) return NULL;
    while(node->r) node=node->r;
    return node;
}
Node* getGreater(int id){
    search(id);
    if(root->id>id) return root;
    Node*node=root->r;
    if(!node) return NULL;
    while(node->l) node=node->l;
    return node;
}
void del(int a,int b){
    Node *pre=getLess(a),*next=getGreater(b);
    if(pre && next){
        splay(pre,NULL);
        splay(next,pre);
        next->l=NULL;
        update(next);
        update(pre);
    }else if(pre){
        splay(pre,NULL);
        pre->r=NULL;
        update(pre);
    }else if(next){
        splay(next,NULL);
        next->l=NULL;
        update(next);
    }else{
        root=NULL;
    }
}
int query(int a,int b){
    Node *pre=getLess(a),*next=getGreater(b),*ans;
    if(pre && next){
        splay(pre,NULL);
        splay(next,pre);
        ans = next->l;
    }else if(pre){
        splay(pre,NULL);
        ans = root->r;
    }else if(next){
        splay(next,NULL);
        ans = root->l;
    }else{
        ans = root;
    }
    if(ans) return ans->sum;
    return 0;
}
int main(){
    freopen("data.txt","r",stdin);
    int n;
    cin>>n;
    while(n--){
        char op;
        int id,val,a,b,d;
        cin>>op;
        if(op=='I'){
            cin>>id>>val;
            insert(id,val);
            // out();
        }else if(op=='Q'){
            
        }else if(op=='M'){
            cin>>a>>b>>d;
            // out();
        }else{

        }
    }
    // out();
    // Node *tmp=getGreater(1);
    // out();
    // if(tmp) printf("tmp->id=%d\n",tmp->id);
    // else printf("tmp is null\n");
    out();
    del(2,3);
    out();
    printf("%d\n",query(1,10));
    out();
    // search(5);
    // out();
    return 0;
}
