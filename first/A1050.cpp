#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
int main(){
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);
	for(int i=0;i<str1.size();i++){
		const char ch=str1[i];
		if(str2.find(ch)==string::npos)
			printf("%c",str1[i]);
	}
	return 0;
}
