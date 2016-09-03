#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main(){
	freopen("data.txt","r",stdin);
	int t,n,m,x;
	vector<int> v;
	scanf("%d",&t);
	while(t--){
		v.clear();
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			v.push_back(x);
		}
		int maxV=0;
		if(n<=m){
			printf("100\n");
			continue;
		}
		if(m==0){
			// printf("==\n");
			maxV=v[0]-1;
			for(int i=1;i<v.size();i++){
				if(v[i]-v[i-1]-1>maxV) maxV=v[i]-v[i-1]-1;
			}	
			if(100-v.back()>maxV) maxV=100-v.back();
			printf("%d\n",maxV);
			continue;
		}
		for(int i=0;i<v.size();i++){
			if(v.size()-i<m) break;
			int r = (i+m)==v.size()?100:v[i+m]-1;
			int l = (i-1)<0?1:v[i-1]+1;
			int tmp = r-l+1;
			if(tmp>maxV) maxV=tmp;
		}
		printf("%d\n",maxV);
	}
	return 0;
}