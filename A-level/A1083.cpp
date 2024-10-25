#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

struct st{
	string name,id;
	int g;
	st(string _name,string _id,int _g):name(_name),id(_id),g(_g){};
};

bool cmp(st a,st b){
	return a.g>b.g;
}
vector<st> list;
string n,idd;
int gg;
int N;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		cin>>n>>idd>>gg;
		list.push_back(st(n,idd,gg));
	}
	int low,high;
	scanf("%d %d",&low,&high);
	sort(list.begin(),list.end(),cmp);
	int cnt=0;
	for(int i=0;i<N;i++){
		if(list[i].g<=high&&list[i].g>=low){
			printf("%s %s\n",list[i].name.c_str(),list[i].id.c_str());
			cnt++;
		}
	}
	if(cnt==0)
	printf("NONE");
	return 0;
}
