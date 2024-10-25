#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

string str,temp;
char d;
int n;

void solve(string s,int a){
	if(a==1){
		cout<<s;
		return;
	}
	temp="\0";
	char ch=s[0];
	int num=0;
	int cnt=0;
	int len=s.size();
	while(cnt<len){
		for(num=cnt+1;num<len;num++){
			if(s[cnt]!=s[num]){
				break;
			}
		}
		temp+=s[cnt];
		temp+=(char)('0'+num-cnt);
		cnt=num;
	}
	solve(temp,a-1);
}

int main(){
	scanf("%c%d",&d,&n);
	str="\0";
	str=d+str;
	solve(str,n);
	return 0;
}
