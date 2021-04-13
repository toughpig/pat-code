#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

vector<string> ve;

int cal(string s){
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='0')
			return cnt;
		else
			cnt++;
	}
	return cnt;
}
int head(string s){
	int a;
	sscanf(s.c_str(),"%d",&a);
	return a;
}
int ishead(int a){
	if(a==ve.size()-1||ve[a].size()>ve[a+1].size()) return -1;
	string a1=ve[a];
	string a2=ve[a+1];
	for(int i=0;i<ve[a].size();i++){
		if(ve[a][i]!=ve[a+1][i])
			return i;
	}
	return ve[a].size();
}
bool headbelow(int a){
	int k=ishead(a-1);
	for(int i=0;i<k;i++){
		if(i+k<ve[a].size()){
			if(ve[a][i]>ve[a][k+i])
				return true;
			}
		else{
			break;
		}
		
	}
	return false;
}
bool cmp(string a,string b){
	return strcmp(a.c_str(),b.c_str())<=0;
}
int main(){
	int N;
	int first=-1;
	scanf("%d",&N);
	int maxn=-1;
	int headmaxn=9999999;
	for(int i=0;i<N;i++){
		string temp;
		cin>>temp;
		if(maxn<cal(temp)||maxn==cal(temp)&&head(temp)<headmaxn){
			headmaxn=head(temp);
			maxn=cal(temp);
			first=i;
		}
		ve.push_back(temp);	
	}
	printf("%d",head(ve[first]));
	ve.erase(ve.begin()+first);
	sort(ve.begin(),ve.end(),cmp);
	while(!ve.empty()){
		int i=0;
		while(1){
		if(ishead(i)==ve[i].size()){//ǰ׺ 
			if(headbelow(i+1)){
				i++;
			}
			else
			break;
		}
		else
		break;
	}
		printf("%s",ve[i].c_str());
		ve.erase(ve.begin()+i);
	}
	return 0;
}
