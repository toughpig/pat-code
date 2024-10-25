#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;

string str;
string store[15][2];
int cnt=0;
string temp;

bool judge(string s){
	int len=s.size();
	for(int i=0;i<len;i++){
		if(i>len-1-i) break;
		if(s[i]!=s[len-1-i]) return false;
	}
	return true;
}

string it(string s){
	string a="\0";
	int len=s.size();
	int carry=0;
	int b;
	for(int i=0;i<len;i++){
		b=s[i]-'0'+s[len-1-i]-'0'+carry;
		char c='0'+b%10;
		carry=b/10;
		a=c+a;
	}
	if(carry==1) a='1'+a;
	return a;
}

void print(int a){
	string aa,bb,cc;
	for(int i=0;i<a;i++){
		aa=store[i][0];
		bb=store[i][1];
		printf("%s",aa.c_str());
		reverse(aa.begin(),aa.end());
		printf(" + %s = %s\n",aa.c_str(),bb.c_str());
	}
}

int main(){
	getline(cin,str);
	while(judge(str)==false){
		cnt++;
		if(cnt>10) break;
		temp=it(str);
		store[cnt-1][0]=str;
		store[cnt-1][1]=temp;
		str=temp;
	}
	if(cnt>10){
		print(cnt-1);
		printf("Not found in 10 iterations.");
	}
	else{
		print(cnt);
		printf("%s is a palindromic number.",str.c_str());
	}
	return 0;
}
