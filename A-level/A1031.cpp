#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main(){
	string str;
	cin>>str;
	int len=str.length();
	int x=(len+2)/3;
	int y=len-2*x+2;
	for(int i=0;i<x-1;i++){
		printf("%c",str[i]);
		for(int j=0;j<y-2;j++)
			printf(" ");
		printf("%c\n",str[len-1-i]);
	} 
	for(int i=x-1;i<x-1+y;i++)
		printf("%c",str[i]);
	return 0;
} 
