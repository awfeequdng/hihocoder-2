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
	return (a.x==b.x && a.y==b.y);
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
Node nodes[4];
bool inter(int i,int j){
	Node a=nodes[i],b=nodes[j];
	return (a.l==b.l || a.r==b.r || a.l==b.r || a.r==b.l);
}
bool vertical(int i,int j){
	Node a=nodes[i],b=nodes[j];
	return (a.r.y-a.l.y)*(b.r.y-b.l.y)+(a.r.x-a.l.x)*(b.r.x-b.l.x)==0;
}
bool solve(){
	int cnt=0;
	rep(i,0,4){
		rep(j,i+1,4){
			if(inter(i,j)){
				if(vertical(i,j))	
					cnt++;
				else 
					return false;
			}
		}
	}
	// printf("cnt=%d\n",cnt);
	return cnt==4;
}
int main(){
	freopen("data.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		bool ok=true;
		rep(i,0,4){
			int x1,x2,y1,y2;
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			if(x1==x2 && y1==y2){
				ok=false;
			}
			nodes[i] = Node(Point(x1,y1),Point(x2,y2));
		}
		if(!ok)
			printf("NO\n");
		else
			printf("%s\n",solve()?"YES":"NO");
	}
	return 0;
}