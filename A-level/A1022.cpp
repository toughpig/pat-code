#include<cstdio>
#include<map>
#include<string>
#include<iostream>
#include<vector>
#include<cstring>
#include<set>
using namespace std;

map<string,vector<int> >tit,auth,kw,pub;
map<int,vector<int> >year;
set<int> an;
void print(vector<int> v){
	int l=v.size();
	for(int i=0;i<l;i++){
		an.insert(v[i]);
	}
}

int main(){
	int N;scanf("%d",&N);
	int id;
	string temp;
	while(N--){
		int y;
		scanf("%d",&id);
		getchar();//¶Á»»ÐÐ·û 
		getline(cin,temp);
		tit[temp].push_back(id);
		getline(cin,temp);
		auth[temp].push_back(id);
		getline(cin,temp);
		int len=temp.length();
		string key;
		for(int i=0;i<=len;i++){
			if(temp[i]!=' '&&i!=len){
				key+=temp[i];
			}
			else if(key.length()>0){
				kw[key].push_back(id);
				key.clear();
			}
		}
		getline(cin,temp);
		pub[temp].push_back(id);
		scanf("%d",&y);
		year[y].push_back(id);
	}
	int M;
	scanf("%d",&M);
	getchar();
	while(M--){
		getline(cin,temp);
		cout<<temp<<endl;
		string se=temp.substr(0,1);
		temp.erase(0,3);
		int ye=-1;
		if(se=="5"){
			sscanf(temp.c_str(),"%d",&ye);
			
		}
		if(se=="1"&&tit.find(temp)!=tit.end())
			print(tit[temp]);
		if(se=="2"&&auth.find(temp)!=auth.end())
			print(auth[temp]);
		if(se=="3"&&kw.find(temp)!=kw.end())
			print(kw[temp]);
		if(se=="4"&&pub.find(temp)!=pub.end())
			print(pub[temp]);
			if(ye!=-1){
			
		if(se=="5"&&year.find(ye)!=year.end())
			print(year[ye]);
}
	int le=an.size();
	if(le==0){
		printf("Not Found\n");
	}
	else{
	for(set<int>::iterator i=an.begin();i!=an.end();i++){
		printf("%07d\n",*i);
	}
	an.clear();
}
}
	return 0;
} 
