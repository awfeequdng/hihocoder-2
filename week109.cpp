#include <cstdio>
#include <vector>
using namespace std;

struct Node{
	int index,p,q;
	vector<int> child;
	Node(){}
	Node(int _index,int _p,int _q):index(_index),p(_p),q(_q){}
};
const int MAXN=10005;
Node nodes[MAXN];
int n;

int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		nodes[i].index=i;
		scanf("%d %d",&nodes[i].p,&nodes[i].q);
	}
	
	
	return 0;
}