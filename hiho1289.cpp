/* trie树 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

struct Node{
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
}