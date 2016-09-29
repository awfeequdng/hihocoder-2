#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=20003;
int n,cnt,num[MAXN],visit[MAXN];
vector<int> G[MAXN];
stack<int> S;
string names[MAXN];
set<string> st;

void dfs(int x){
    int h=num[x]/3600;
    num[x]=num[x]%3600;
    int m=num[x]/60;
    num[x]=num[x]%60;
    int s=num[x];
    visit[x]=1;
    cout<<names[x]<<' '<<setfill('0')<<setw(2)<<h<<':'<<setw(2)<<m<<':'<<setw(2)<<s<<endl;
    vector<int> &vec = G[x];
    rep(i,0,vec.size()){
        dfs(vec[i]);
    }
}
int main(){
    freopen("data.txt","r",stdin);
    cin>>n;
    while(n--){
        string name,times,action;
        int h,m,s;
        cin>>name>>times>>action;
        h=(times[0]-'0')*10+(times[1]-'0');
        m=(times[3]-'0')*10+(times[4]-'0');
        s=(times[6]-'0')*10+(times[7]-'0');
        if(action=="START"){
            if(st.find(name)!=st.end()){
                cout<<"Incorrect performance log"<<endl;
                // cout<<"cnt="<<cnt<<endl;
                return 0;
            }
            st.insert(name);
            if(!S.empty()) G[cnt-1].push_back(cnt);
            S.push(cnt);
            names[cnt]=name;
            // cout<<"cnt="<<cnt<<"h="<<h<<"m="<<m<<"s="<<s<<endl;
            num[cnt++]=s+m*60+h*3600;
        }else if(action=="END"){
            if(S.empty() || name!=names[S.top()]){
                cout<<"Incorrect performance log"<<endl;
                return 0;
            }
            num[S.top()]=(s+m*60+h*3600)-num[S.top()];
            if(num[S.top()]<0){
                cout<<"Incorrect performance log"<<endl;
                return 0;   
            }
            S.pop();
        }else{
            cout<<"Incorrect performance log"<<endl;
            return 0;
        }
    }
    if(!S.empty()){
        cout<<"Incorrect performance log"<<endl;
        return 0;
    }
    rep(i,0,cnt){
        if(!visit[i])
            dfs(0); 
    }
    return 0;
}