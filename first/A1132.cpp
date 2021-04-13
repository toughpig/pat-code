#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long ll;

string str,a,b;
int n;

ll toint(string a){
	ll sum=0;
	int i=0;
	while(i<a.size()){
		sum=sum*10+a[i]-'0';
		i++;
	}
	return sum;
}

void judge(string s){
	int len=s.size();
	string a=s.substr(0,len/2);
	string b=s.substr(len/2,len/2);
	ll aa=toint(a);
	ll bb=toint(b);
	ll cc=toint(s);
	if(fabs((double)cc/(double)(aa*bb)-round((double)cc/(double)(aa*bb)))<1e-16) printf("Yes\n");
	else printf("No\n");
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>str;
		judge(str);
	}	
	
	return 0;
} 
