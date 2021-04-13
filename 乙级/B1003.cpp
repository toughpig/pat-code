//еп╤о (A*n)+P+(A*k)+T+(A*(k*n))
#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

string str;
int n;

void judge(string s){
	int cntp=0,cntt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='P'&&s[i]!='A'&&s[i]!='T'){
			printf("NO\n");
			return;
		}
		if(s[i]=='P') cntp++;
		if(s[i]=='T') cntt++;
	}
	if(cntt!=1||cntp!=1){
		printf("NO\n");
		return;
	}
	int aa=0,pa=0,ta=0;
	int i;
	for(i=0;i<s.size();i++){
		if(s[i]=='A') aa++;
		else break;
	}
	if(i>=s.size()||s[i++]!='P'){
		printf("NO\n");
		return;
	}
	for(;i<s.size();i++){
		if(s[i]=='A') pa++;
		else break;
	}
	if(i>=s.size()||s[i++]!='T'){
		printf("NO\n");
		return;
	}
	for(;i<s.size();i++){
		if(s[i]=='A') ta++;
	}
	if(pa==0||aa*pa!=ta){
		printf("NO\n");
		return;
	}
	printf("YES\n");
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		str.clear();
		cin>>str;
		judge(str);
	}
	return 0;
} 
