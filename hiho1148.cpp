#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

char month[][20]={"January", "February", "March", "April", "May", "June", "July", 
                "August", "September", "October", "November" , "December"};
int y1,m1,d1,y2,m2,d2;
char s1[20],s2[20];

int _find(char *s){
    rep(i,0,12)
        if(!strcmp(month[i],s)) return i+1;
}
int solve(){
    int ans=0,s=y1+1,e=y2;
    if(m1<=2) s=y1;
    if(m2==1 || (m2==2 && d2<29)) e=y2-1;
    int i=s;
    while(i<=e){
        if(i%400==0) break;
        i++;
    }
    if(i<=e){
        ans+=(e-i)/400+1;
    }
    //second
    int sum=0,sub=0;
    i=s;
    while(i<=e){
        if(i%4==0 && i%100!=0) break;
        i++;
    }
    if(i<=e){
        sum = (e-i)/4+1;
        int j=i;
        e=i+(e-i)/4*4;
        while(j<=e){
            if(j%4==0 && j%100==0) break;
            j+=4;   
        }
        if(j<=e){
            sub = (e-j)/100+1;
            sum = sum-sub;
        }
        ans+=sum;
    }
    return ans;
}
int main(){
    freopen("data.txt","r",stdin);
    int t;
    scanf("%d",&t);
    rep(i,1,t+1){
        printf("Case #%d: ",i);
        scanf("%s %d,%d",s1,&d1,&y1);
        scanf("%s %d,%d",s2,&d2,&y2);
        m1=_find(s1),m2=_find(s2);
        printf("%d\n",solve());
    }
    return 0;
}