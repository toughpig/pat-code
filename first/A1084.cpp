#include<cstdio>
#include<unordered_set>
#include<string>
#include<iostream>
using namespace std;
unordered_set<char> s;
int main(){
	string a,b;
	cin>>a>>b;
	for(int i=0;i<b.size();i++){
		if(b[i]>='a'&&b[i]<='z')
			b[i]-=32;
		s.insert(b[i]);
	}
	for(int j=0;j<a.size();j++){
		if(a[j]>='a'&&a[j]<='z')
			a[j]-=32;
		if(s.find(a[j])!=s.end())
			continue;
		else{
			printf("%c",a[j]);
			s.insert(a[j]);
		}
	}
	return 0;
}
