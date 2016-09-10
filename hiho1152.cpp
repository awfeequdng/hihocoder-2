#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int n,cnt[26];
string str;
set<string> s;

bool ok(int x){
    if(x==1 || x==2 || x==3 || x==5 || x==8 || x==13 || x==21)
        return true;
    return false;
}
void solve(){
    rep(i,0,n){
        int j=i;
        memset(cnt,0,sizeof(cnt));
        int tmp=0;
        while(j<n){
            if(cnt[str[j]-'a']==0){
                tmp++;
            }
            cnt[str[j]-'a']++;
            if(ok(tmp)){
                s.insert(str.substr(i,j-i+1));
            }
            j++;
        }
    }
    for(set<string>::iterator it=s.begin();it!=s.end();it++){
        cout<<*it<<endl;
    }
}
int main(){
    freopen("data.txt","r",stdin);
    cin>>str;
    n=str.size();
    solve();

    return 0;
}