<<<<<<< HEAD
#include <cstdio>
#include <cstring>
#include <iostream>
=======
/* trie树 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
>>>>>>> 3a750285d93a15108dc456afcaa30704cb53fd2f
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

struct Node{
<<<<<<< HEAD
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
=======
	int order,type;//0,1,2 not match,allow,deny
	Node *l,*r;
	Node(int _type=0,int _order=0):type(_type),order(_order),l(NULL),r(NULL){}
};
Node *root;
int n,m;

//index表示t的后多少位匹配
void insert(unsigned int t,int type,int order,int index=32){
	Node *node = root;
	if(!index){
		if(node->type==0){
			node->type = type;
			node->order = order;
		}
		return ;
	}
	for(int i=0;i<32;i++){
		int x = (t>>(31-i))&1;
		if(!x){
			if(node->l==NULL) node->l = new Node();
			node = node->l;
		}else{
			if(node->r==NULL) node->r = new Node();
			node = node->r;
		}
		if(index==i+1){
			//不覆盖以前
			if(node->type==0){
				node->type = type;
				node->order = order;
			}
			return ;
		}
	}
}
bool search(unsigned int t){
	int ans=-1,minI=1000000;
	Node *node = root;
	if(node->type){
		ans = node->type;
		minI = node->order;
	}
	for(int i=0;i<32;i++){
		int x = (t>>(31-i))&1;
		if(!x){
			node = node->l;
		}else{
			node = node->r;
		}
		if(node==NULL){
			if(ans==-1) return true;
			return ans==1?true:false;
		}else{
			if(node->type && node->order<minI){
				ans = node->type;
				minI = node->order;	
			}
		}
	}
	if(ans==-1) return true;
	return ans==1?true:false;
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d%d\n",&n,&m);
	root = new Node();
	char op[6],cc;
	unsigned int a,b,c,d;
	int type,mask;
	rep(i,0,n){
		scanf("%s",op);
		type = strcmp(op,"allow")==0?1:2;
		scanf("%d.%d.%d.%d",&a,&b,&c,&d);
		cc = getchar();
		if(cc=='/'){
			scanf("%d\n",&mask);
		}
		unsigned int t = d+(c<<8)+(b<<16)+(a<<24);	
		insert(t,type,i+1);
		if(cc=='/') insert(t,type,i+1,mask);
	}
	rep(i,0,m){
		scanf("%d.%d.%d.%d",&a,&b,&c,&d);
		unsigned int t = d+(c<<8)+(b<<16)+(a<<24);	
		printf("%s\n",search(t)?"YES":"NO");
	}
	return 0;
>>>>>>> 3a750285d93a15108dc456afcaa30704cb53fd2f
}