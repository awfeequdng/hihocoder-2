#include <cstdio>
#include <vector>
using namespace std;

const int MAXN=2001;
int n,m;
pair<int,int> num[MAXN];

int main(){
	freopen("data.txt","r",stdin);
	scanf("%d %d",&n,&m);
	int t,last=1;
	scanf("%d",&t);
	num[1].first=0,num[1].second=t-1;
	for(int i=2;i<=n;i++){
		scanf("%d",&t);
		if(num[last].first==0){
			if(num[i-1].second+t<=m-1){
				num[i].first=num[i-1].second+1;
				num[i].second=num[i-1].second+t;
			}else{//从last开始
				int s=0;
				while(s<t){
					s+=num[last].second-num[last].first+1;
					last++;
				}
				num[i].first=0;
				num[i].second=t-1;
			}
		}else{
			if(num[i-1].second+t<num[last].first){
				num[i].first=num[i-1].second+1;
				num[i].second=num[i-1].second+t;
			}else{
				if(num[i-1].second+t<=m-1){
					int s=0;
					while(s<t){
						s+=num[last].second-num[last].first+1;
						last++;
					}
					num[i].first=num[i-1].second+1;
					num[i].second=num[i-1].second+t;	
				}else{
					while(num[last].first!=0) 
						last++;
					int s=0;
					while(last<i && s<t){
						s+=num[last].second-num[last].first+1;
						last++;
					}
					num[i].first=0;
					num[i].second=t-1;	
				}
			}
		}
	}
	for(int i=last;i<=n;i++)
		printf("%d %d\n",i,num[i].first);
	
	return 0;
}