#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=100003;
char s[MAXN];
int n;
void solve(){
    n=strlen(s);
    sort(s,s+n);
    vector<char> v;
    v.push_back(s[0]);
    s[0]='.';
    while(v.size()<n){
        int i=0;
        while(i<n && (s[i]=='.' || s[i]==v.back())){
            i++;
        }
        if(i==n) break;
        v.push_back(s[i]);
        s[i]='.';
    }
    if(v.size()==n){
        rep(i,0,n)
            printf("%c",v[i]);
        printf("\n");
    }else{
        printf("INVALID\n");
    }
}
int main(){
    freopen("data.txt","r",stdin);
    scanf("%s",s);
    solve();    
    return 0;
}