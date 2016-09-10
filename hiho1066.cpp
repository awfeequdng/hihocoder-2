#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int MAXN=200003;
int n,par[MAXN],_rank[MAXN],cnt;
map<string,int> m;

void init(){
    rep(i,0,MAXN){
        par[i]=i;
        _rank[i]=0;
    }
}
int find(int x){
    if(x==par[x]) return x;
    return par[x]=find(par[x]);
}
void _union(int a,int b){
    // cout<<"_union方法里："<<"a="<<a<<",b="<<b<<endl;
    int x=find(a),y=find(b);
    // cout<<"_union方法里："<<"x="<<x<<",y="<<y<<endl;
    if(x==y) return ;
    if(_rank[x]<_rank[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(_rank[x]==_rank[y]) _rank[x]++;
    }
}
bool same(int x,int y){
    return find(x)==find(y);
}

int main(){
    freopen("data.txt","r",stdin);
    cin>>n;
    init();
    rep(i,0,n){
        int op;
        string name1,name2;
        cin>>op>>name1>>name2;
        // cout<<op<<" "<<name1<<" "<<name2<<endl;
        if(op==1){//查
            int a=-1,b=-1;
            if(m.find(name1)!=m.end()) a=m[name1];
            if(m.find(name2)!=m.end()) b=m[name2];
            // cout<<"a="<<a<<",b="<<b<<endl;
            if(a==-1 || b==-1){
                cout<<"no"<<endl;
            }else{
                if(same(a,b)) cout<<"yes"<<endl;
                else cout<<"no"<<endl;
            }
        }else{
            if(m.find(name1)==m.end()) m[name1]=cnt++;
            if(m.find(name2)==m.end()) m[name2]=cnt++;
            _union(m[name1],m[name2]);
            // cout<<"合并："<<m[name1]<<","<<m[name2]<<endl;
        }
    }
    // cout<<"输出:"<<endl;
    // rep(i,0,cnt){
    //     cout<<"i="<<i<<"par[i]="<<par[i]<<endl;
    // }
    return 0;
}