#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=26+26+11;
int a[maxn]={0};

int hashh(char ch){
	if(ch>='0'&&ch<='9') return ch-'0';
	else if(ch>='a'&&ch<='z') return ch-'a'+10;
	else if(ch>='A'&&ch<='Z') return ch-'A'+36;
}

string str1,str2;

int main(){
	cin>>str1>>str2;
	for(int i=0;i<str1.size();i++){
		int temp=hashh(str1[i]);
		a[temp]++;
	}
	for(int i=0;i<str2.size();i++){
		int temp=hashh(str2[i]);
		a[temp]--; 
	}
	int c=0,d=0;
	for(int i=0;i<maxn;i++){
		if(a[i]>0) c+=a[i];
		if(a[i]<0) d+=a[i];
	}
	if(d!=0) printf("No %d",-1*d);
	else printf("Yes %d",c);
	return 0;
}
