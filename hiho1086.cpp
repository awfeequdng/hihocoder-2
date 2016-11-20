#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=20002;
map<string,int> ma;
string order[MAXN];

int main(){
    freopen("data.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    rep(i,0,n){
        string u;
        cin>>u;
        if(ma.find(u)==m.end()){
            printf("Internet\n");
            //add
            if(ma.size()==m){
                
            }else{
                ma[u]=i;
                order[i]=u;    
            }
        }else{
            printf("Cache\n");
            ma[u]=i;
            order[i]=u;
        }
    }
    return 0;
}