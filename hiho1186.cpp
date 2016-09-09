#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int main(){
    freopen("data.txt","r",stdin);
    int p,q;
    scanf("%d%d",&p,&q);
    vector<int> v1,v2;
    int i;
    for(i=1;i<=min(p,q);i++){
        if(p%i==0) v1.push_back(i);
        if(q%i==0) v2.push_back(i);
    }    
    while(i<=p){
        if(p%i==0) v1.push_back(i);
        i++;
    }
    while(i<=q){
        if(q%i==0) v2.push_back(i);
        i++;
    }
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            printf("%d %d\n",v1[i],v2[j]);
        }    
    }
    return 0;   
}