#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=202;
char num[MAXN][MAXN],s[3][3],top[10],left[10],bottom[10],right[10],tmp[10];
int n,m;

bool ok(){
	if(!strcmp(tmp,top)) return true;
	if(!strcmp(tmp,left)) return true;
	if(!strcmp(tmp,right)) return true;
	if(!strcmp(tmp,bottom)) return true;
	return false;
}
void solve(){
	for(int i=0;i<9;i++){
		bottom[8-i]=top[i];
		right[8-i]=left[i];
	}
	bottom[9]=top[9]=left[9]=right[9]=tmp[9]=0;
	//测试输出
	// for(int i=0;i<n;i++)
	// 	printf("%s\n",num[i]);
	// printf("=======================\n");
	// printf("top=%s\n",top);
	// printf("bottom=%s\n",bottom);
	// printf("left=%s\n",left);
	// printf("right=%s\n",right);



	for(int i=0;i+2<n;i++){
		for(int j=0;j+2<m;j++){
			for(int ii=0;ii<3;ii++)
				for(int jj=0;jj<3;jj++)
					tmp[ii*3+jj]=num[ii+i][jj+j];
			// printf("tmp=%s\n",tmp);
			if(ok()){
				printf("%d %d\n",i+2,j+2);
			}		
		}
	}
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d%d\n",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",num[i]);
	scanf("%c",&num[201][201]);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf("%c",&s[i][j]);
			top[i*3+j]=s[i][j];
		}
		scanf("%c",&num[201][201]);
	}
	for(int j=0;j<3;j++)
		for(int i=2;i>=0;i--)
			left[j*3+(2-i)]=s[i][j];
	solve();
	return 0;
}