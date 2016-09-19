#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

char visit[26],num[5][5];

string solve(string s){
    string a="";
    rep(i,0,s.size()){
        char c = s[i]=='J'?'I':s[i];
        if(!visit[c-'A']){
            a+=c;
            visit[c-'A']=1;
        }
    }
    return a;
}
int main(){
    // freopen("data.txt","r",stdin);
    string s;
    cin>>s;
    s = solve(s);
    int x=0,y=0;
    visit['J'-'A']=1;
    rep(i,0,5){
        rep(j,0,5){
            if(x<s.size()) num[i][j]=s[x++];
            else{
                while(visit[y]) y++;
                num[i][j]=y+'A';
                visit[y]=1;
            }
            printf("%c",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}