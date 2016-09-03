#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

typedef long long ll;
const int MAXN=100003;
struct op{
	int t,l,r;
}ops[MAXN];
struct Node{
	int val;
	Node*left,*right,*par;
	Node(int _val=0):val(_val),left(NULL),right(NULL),par(NULL){}
};
int N,M,s[MAXN],m[MAXN],rr[MAXN];
Node*root;
void rotate(Node*node,bool isLeft){
	if(isLeft){
		Node*p=node->par;//可能是NULL
		Node*r=node->right;//不可能是NULL
		if(r->left) r->left->par=node;
		node->right=r->left;
		r->left=node;
		node->par=r;
		if(p==NULL){
			root=r;
			r->par=NULL;
		}else{
			if(p->left && p->left==node){
				p->left=r;
				r->par=p;
			}else{
				p->left=r;
				r->par=p;
			}
		}
	}else{
		Node*p=node->par;//可能是NULL
		Node*l=node->left;//不可能是NULL
		if(l->right) l->right->par=node;
		node->left=l->right;
		l->right=node;
		node->par=l;
		if(p==NULL){
			root=l;
			l->par=NULL;
		}else{
			if(p->left && p->left==node){
				p->left=l;
				l->par=p;
			}else{
				p->left=l;
				l->par=p;
			}
		}
	}
}
//将node伸展到根节点
void splay(Node*node){
	Node *p,*g;
	while((p=node->par) && (g=p->par)){
		if(g->left && g->left==p){
			if(p->left && p->left==node){
				//LL
				rotate(g,false);
				rotate(p,false);
			}else{
				//LR
				rotate(p,true);
				rotate(g,false);
			}
		}else{
			if(p->left && p->left==node){
				//RL
				rotate(p,false);
				rotate(g,true);
			}else{
				//RR
				rotate(g,true);
				rotate(p,true);
			}
		}
	}
	if(p){
		if(p->left && p->left==node) rotate(p,false);
		else rotate(p,true);
	}
}
bool search(int num){
	if(root->val==num)	return true;
	Node* node=root;
	int has=0;
	while(true){
		Node*p=NULL;
		if(num<node->val){
			p=node->left;
			has=1;
		}else{
			p=node->right;
			has=2;
		}
		if(!p){
			has=0;
			break;
		}else if(p->val==num){
			break;
		}else{
			node=p;
		}
	}
	//伸展
	if(has==0){
		splay(node);
		return false;
	}else if(has==1){
		splay(node->left);
	}else{
		splay(node->right);
	}
	return true;
}
void insert(int num){
	if(!root){
		root = new Node(num);
		return ;
	}
	bool has = search(num);
	Node *node = new Node(num);
	if(!has){
		if(num<root->val){
			node->left=root->left;
			if(root->left) root->left->par=node;
			root->left=NULL;
			node->right=root;
			root->par=node;
			root=node;
		}else{
			node->right=root->right;
			if(root->right) root->right->par=node;
			root->right=NULL;
			node->left=root;
			root->par=node;
			root=node;
		}
	}
}
ll solve(){
	ll ans=0;
	rep(i,1,N+1){
		root=NULL;
		rep(j,0,M){
			if(i>=ops[j].l && i<=ops[j].r){
				
			}
		}
	}
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&N);
	rep(i,1,N+1)
		scanf("%d%d%d",&s[i],&m[i],&rr[i]);
	scanf("%d",&M);
	rep(i,0,M)
		scanf("%d%d%d",&ops[i].t,&ops[i].l,&ops[i].r);
	printf("%lld\n",solve());
	return 0;
}