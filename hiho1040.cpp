#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

struct Point{
	int x,y;
	Point(){}
	Point(int xx,int yy):x(xx),y(yy){}
};
bool operator<(Point a,Point b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
bool operator==(Point a,Point b){
	return a.x==b.x && a.y==b.y;
}
struct Node{
	Point l,r;
	Node(){}
	Node(Point ll,Point rr){
		if(ll<rr){
			l=ll,r=rr;
		}else{
			l=rr,r=ll;
		}
	}
};
bool operator<(Node a,Node b){
	if(a.l==b.l) return a.r<b.r;
	return a.l<b.l;
}
Node nodes[4];
bool solve(){
	sort(nodes,nodes+4);
	// rep(i,0,4){
	// 	printf("x1=%d,y1=%d,x2=%d,y2=%d\n",nodes[i].l.x,nodes[i].l.y,nodes[i].r.x,nodes[i].r.y);
	// }
	Node &a=nodes[0],&b=nodes[1],&c=nodes[2],&d=nodes[3];
	if(a.l==b.l && a.r==c.l && d.l==b.r && d.r==c.r){
		
	}else{
		return false;
	}
}
int main(){
	freopen("data.txt","r",stdin);
	int t;
	scanf("%d",&t);
	// printf("t=%d\n",t);
	while(t--){
		rep(i,0,4){
			int x1,x2,y1,y2;
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			nodes[i] = Node(Point(x1,y1),Point(x2,y2));
		}
		printf("%s\n",solve()?"YES":"NO");
	}
	return 0;
}