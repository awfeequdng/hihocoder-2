#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define INF 100000000

struct Node{
	int index,val,sal;
}; 
const int MAXN=102,MAXM=1003;
int n,x,y,b,xx,yy;//xx是实际男生数量
Node male[MAXN],female[MAXN];
int mdp[MAXN][MAXM][MAXN],fdp[MAXN][MAXM][MAXN];
bool scm[MAXN][MAXM][MAXN],scf[MAXN][MAXM][MAXN];

void solve(){
	rep(j,0,b+1)
		rep(k,1,x+1)
			mdp[0][j][k]=-INF;
	rep(i,1,xx+1){
		rep(j,0,b+1){
			rep(k,0,x+1){
				if(k>i){
					mdp[i][j][k]=-INF;
					continue;
				}
				if(k==0 || male[i-1].sal>j) mdp[i][j][k]=mdp[i-1][j][k];
				else{
					int tmp=mdp[i-1][j-male[i-1].sal][k-1]+male[i-1].val;
					if(tmp>=mdp[i-1][j][k]){
						mdp[i][j][k]=tmp;
						scm[i][j][k]=true;
					}else{
						mdp[i][j][k]=mdp[i-1][j][k];
					}
				}
			}
		}
	}
	//female
	rep(j,0,b+1)
		rep(k,1,y+1)
			fdp[0][j][k]=-INF;
	rep(i,1,yy+1){
		rep(j,0,b+1){
			rep(k,0,y+1){
				if(k>i){
					fdp[i][j][k]=-INF;
					continue;
				}
				if(k==0 || female[i-1].sal>j) fdp[i][j][k]=fdp[i-1][j][k];
				else{
					int tmp=fdp[i-1][j-female[i-1].sal][k-1]+female[i-1].val;
					if(tmp>=fdp[i-1][j][k]){
						fdp[i][j][k]=tmp;
						scf[i][j][k]=true;
					}else{
						fdp[i][j][k]=fdp[i-1][j][k];
					}
				}
			}
		}
	}
	int maxV=-1,cus=0,_j1,_j2;
	rep(j1,0,b+1){
		rep(j2,0,b+1){
			if(j1+j2<=b){
				if(mdp[xx][j1][x]+fdp[yy][j2][y]>maxV){
					maxV=mdp[xx][j1][x]+fdp[yy][j2][y];
					cus=j1+j2;
					_j1=j1,_j2=j2;
				}else if(mdp[xx][j1][x]+fdp[yy][j2][y]==maxV){
					if(j1+j2<cus){
						cus=j1+j2;
						_j1=j1,_j2=j2;
					}
				}
			}
		}
	}
	if(maxV==-1){
		printf("0 0\n");
		return ;
	}
	printf("%d %d\n",maxV,cus);
	priority_queue<int,vector<int>,greater<int> > pq;
	int m=xx,j=_j1,k=x;
	while(m && k){
		if(scm[m][j][k]){
			pq.push(male[m-1].index);
			j-=male[m-1].sal;
			k--;
		}
		m--;
	}
	m=yy,j=_j2,k=y;
	while(m && k){
		if(scf[m][j][k]){
			pq.push(female[m-1].index);
			j-=female[m-1].sal;
			k--;
		}
		m--;
	}
	bool first=true;
	while(!pq.empty()){
		if(!first) printf(" ");
		first=false;
		printf("%d",pq.top());pq.pop();
	}
	printf("\n");
}

int main(){
	freopen("data.txt","r",stdin);
	scanf("%d %d %d %d\n",&n,&x,&y,&b);
	rep(i,0,n){
		char c;
		int a,b;
		scanf("%c %d %d\n",&c,&a,&b);
		if(c=='M'){
			male[xx].val=a,male[xx].sal=b,male[xx].index=i+1;
			xx++;
		}else{
			female[yy].val=a,female[yy].sal=b,female[yy].index=i+1;
			yy++;
		}
	}
	solve();
	return 0;
}