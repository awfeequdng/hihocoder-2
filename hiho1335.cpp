#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=10003;
int G[MAXN][MAXN],visit[MAXN];
map<string,int> email;
vector<string> m;
int n;

void dfs(int t,set<int>& s){
    s.insert(t);
    visit[t]=1;
    rep(i,0,n){
        if(!visit[i] && G[t][i]) dfs(i,s);
    }
}
void solve(){
    set<int> s;
    rep(i,0,n){
        if(!visit[i]){
            dfs(i,s);
            //out s
            bool first=true;
            for(set<int>::iterator it=s.begin();it!=s.end();it++){
                if(!first) cout<<' ';
                first=false;
                int tmp=*it;
                cout<<m[tmp];
            }
            cout<<endl;
            s.clear();
        }
    }
}
int main(){
    freopen("data.txt","r",stdin);
    cin>>n;
    rep(i,0,n){
        string s;
        int t;
        cin>>s>>t;
        int index = m.size();
        m.push_back(s);
        while(t--){
            cin>>s;
            if(email.find(s)==email.end()){
                email[s]=index;
            }else{
                G[index][email[s]]=G[email[s]][index]=1;
            }
        }
    }    
    solve();
    return 0;
}