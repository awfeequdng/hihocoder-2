#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=102;
char s[MAXN];
int t,l;

int insert(vector<char> s){
	int score=0;
	vector<char> v;
	bool first=true;
	for(int i=0;i<s.size();i++){
		if(i>0 && s[i]==s[i-1]){
			if(first){
				v.pop_back();
				score+=2;
				first=false;
			}else{
				score++;
			}
		}else{
			v.push_back(s[i]);
			first=true;
		}
	}
	if(!score)	return 0;
	return score+insert(v);
}
int cal(int index){
	//A
	vector<char> va;
	for(int i=0;i<index;i++)
		va.push_back(s[i]);
	va.push_back('A');
	for(int i=index;i<l;i++)
		va.push_back(s[i]);
	int a=insert(va);
	//B
	vector<char> vb;
	for(int i=0;i<index;i++)
		vb.push_back(s[i]);
	vb.push_back('B');
	for(int i=index;i<l;i++)
		vb.push_back(s[i]);
	int b=insert(vb);
	//C
	vector<char> vc;
	for(int i=0;i<index;i++)
		vc.push_back(s[i]);
	vc.push_back('C');
	for(int i=index;i<l;i++)
		vc.push_back(s[i]);
	int c=insert(vc);
	//return 
	if(b>a) a=b;
	if(c>a) a=c;
	return a;
}
int solve(){
	int maxV=-1;
	for(int i=0;i<=l;i++){
		int tmp = cal(i);
		if(tmp>maxV) maxV=tmp;
	}
	return maxV;
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		l=strlen(s);
		printf("%d\n",solve());
	}
	return 0;
}