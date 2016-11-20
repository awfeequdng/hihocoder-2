#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

char s[103];

bool is_regular(int colon,char *s){
    if(s[0]==0){
        return false;
    }

    if(s[0]=='0' || s[0]=='1'){
        int j = 1;
        while(s[j]!=0 && s[j]=='*') j++;
        if(s[j]==0) return colon==0;
        return is_regular(colon,&s[j]);
    }else if(s[0]=='('){
        return is_regular(colon+1,++s);   
    }else if(s[0]==')'){
        if(colon==0) return false;
        //remove *
        int j = 1;
        while(s[j]!=0 && s[j]=='*') j++;
        if(s[j]==0) return colon==1;
        return is_regular(colon-1,&s[j]); 
    }else if(s[0]=='|'){
        if(s[1]==0 || s[1]=='|') return false;
        return is_regular(colon,&s[1]);
    }else{
        return false;
    }
}
int main(){
    freopen("data.txt","r",stdin);
    while(~scanf("%s",s)){
        if(is_regular(0,s)){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    return 0;
}