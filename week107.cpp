#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;

void toLitter(string &s){
	for(int i=0;i<s.size();i++)
		if(s[i]>='A' && s[i]<='Z')
			s[i]+=32;
}
int main(){
	freopen("data.txt","r",stdin);
	string line,s;
	while(getline(cin,line)){
		bool first=true,first_sentence=true;
		stringstream ss(line);
		while(ss>>s){
			if(s==","){
				cout<<',';
			}else if(s=="."){
				cout<<'.';
				first_sentence=true;
			}else{
				toLitter(s);
				if(first){
					first=false;
				}else{
					cout<<' ';
				}
				if(first_sentence){
					s[0]-=32;
					first_sentence=false;
				}
				cout<<s;
				if(s[s.size()-1]=='.'){
					first_sentence=true;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}