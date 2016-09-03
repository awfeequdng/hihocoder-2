#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

struct Node{
	bool end;
	Node* child[26];
	Node*pre;
	Node(bool _end=false):end(_end){
		memset(child,0,sizeof(child));
		pre=NULL;
	}
};
const int MAXM=1000002;
int n;
char article[MAXM],word[MAXM];
Node* root;

void insert(char*c){
	Node*p=root;
	while(*c){
		if((p->child)[*c-'a']==NULL){
			(p->child)[*c-'a'] = new Node();
		}
		p=(p->child)[*c-'a'];
		c++;
	}
	p->end=true;
}
void build(){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node*node=q.front();q.pop();
		for(int i=0;i<26;i++){
			if(node->child[i]!=NULL){
				if(node==root){
					node->child[i]->pre=root;
				}else{
					Node*tmp=node->pre;
					while(tmp!=NULL && tmp->child[i]==NULL){
						tmp=tmp->pre;
					}
					if(tmp==NULL){
						node->child[i]->pre=root;
					}else{
						node->child[i]->pre=tmp->child[i];
					}
				}
				q.push(node->child[i]);
			}
		}
	}
}
bool query(char*s){
	Node*local=root;
	while(*s){
		// printf("local==root?%d\n",local==root);
		if(local->child[*s-'a']!=NULL){
			local=local->child[*s-'a'];
			if(local->end) return true;
		}else{
			if(local->pre!=NULL){
				local=local->pre;
				if(local->end) return true;
			}else{
				local=root;
			}
		}
		s++;
	}
	return false;
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d\n",&n);
	root = new Node();
	rep(i,0,n){
		scanf("%s",word);
		insert(word);
	}
	build();
	scanf("%s",article);
	printf("%s\n",query(article)?"YES":"NO");
	return 0;
}