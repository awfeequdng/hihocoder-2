#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]){
    int*num = new int[3];
    num[0]=0;
    num[1]=2;
    num[2]=4;
    /*
		* 1
		+ 2
    */
    
    printf("%d\n",*(num+1));			

    return 0;
}