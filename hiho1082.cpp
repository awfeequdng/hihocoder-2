#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define REPLACE "fjxmlhx"

char s[202];
const char TARGET[]="marshtomp";

bool isEqual(int t){
	for(int i=0;i<9;i++){
		char a=s[i+t]>='a'?s[i+t]:s[i+t]+32;
		if(a!=TARGET[i]) return false;
	}
	return true;
}
int main(){
	freopen("data.txt","r",stdin);
	while(gets(s)!=NULL){
		// printf("==s=%s==\n",s);
		int l = strlen(s);
		for(int i=0;i<l;i++){
			if(i+8>=l){
				printf("%c",s[i]);
			}else{
				if(isEqual(i)){
					printf("%s",REPLACE);
					i+=8;
				}else{
					printf("%c",s[i]);	
				}
			}
		}
		printf("\n");
	}
	return 0;
}