#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;

map<char,int> mp;
const int maxn=10+26+1;
bool rep[maxn];
bool vis[maxn];

int hashh(char ch){
	if(ch>='0'&&ch<='9') return ch-'0';
	else{
		if(ch>='a'&&ch<='z') return ch-'a'+10;
		else return 36;
	}
}

string str;
int n;

int getlen(int a){
	int cnt=1;
	char temp=str[a];
	for(int i=a+1;i<str.size();i++){
		if(str[i]==temp) cnt++;
		else break;
	}
	return cnt;
}

int main(){
	fill(rep,rep+maxn,true);
	scanf("%d\n",&n);
	getline(cin,str);
	int index=0;
	int len=str.size();
	int k,d;
	fill(vis,vis+maxn,false);
	for(;index<len;){
		k=getlen(index);
		d=hashh(str[index]);
		if(k%n!=0) rep[d]=false;
		index+=k;
	}
	for(index=0;;){
		if(index>=str.size()) break;
		char temp=str[index];
		k=getlen(index);
		d=hashh(str[index]);
		if(rep[d]){
			if(vis[d]==false){
				printf("%c",str[index]);
				vis[d]=true;
			}
			int step=k/n;
			str.erase(index,k-step);
			index+=step;
		}
		else{
			index+=k;
		}
	}
	printf("\n");
	cout<<str;
	return 0;
}
