#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;
struct list{
	string name;
	string pass;
	list(string a,string b):name(a),pass(b){};
};
vector<list> v;
int main(){
	int N;
	scanf("%d",&N);
	int cnt=0;
	string na,pa;
	for(int j=0;j<N;j++){
		cin>>na>>pa;
		int flag=false;
		for(int i=0;i<pa.size();i++){
			if(pa[i]=='1'){
				pa[i]='@';
				flag=true;
			}
			if(pa[i]=='0'){
				pa[i]='%';
				flag=true;
			}
			if(pa[i]=='l'){
				pa[i]='L';
				flag=true;
			}
			if(pa[i]=='O'){
				pa[i]='o';
				flag=true;
			}
		}
		if(flag){
			v.push_back(list(na,pa));
			cnt++;
		}
	}
	if(cnt>0){
		printf("%d\n",cnt);
		for(int i=0;i<v.size();i++){
			printf("%s %s\n",v[i].name.c_str(),v[i].pass.c_str());
		}
	}
	else{
		if(N==1)
			printf("There is 1 account and no account is modified");
		else
			printf("There are %d accounts and no account is modified",N);
	}
	
} 
