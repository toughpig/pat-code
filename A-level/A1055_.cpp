#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

struct node{
	string name;
	int age;
	int poss;
	node(string a,int b,int c):name(a),age(b),poss(c){};
};

vector<node> cand;

int n,k;
string str;
int ag,po;
int m,minn,maxn;

void solve(int m,int minn,int maxn){
	int cnt=0;
	int index=0;
	while(cnt<m&&index<n){
		if(cand[index].age>=minn&&cand[index].age<=maxn){
			cnt++;
			printf("%s %d %d\n",cand[index].name.c_str(),cand[index].age,cand[index].poss); 
		}
		index++;
	}
	if(cnt==0) printf("None\n");
}

bool cmp(node a,node b){
	if(a.poss!=b.poss) return a.poss>b.poss;
	else{
		if(a.age!=b.age) return a.age<b.age;
		else return strcmp(a.name.c_str(),b.name.c_str())<0;
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		cin>>str>>ag>>po;
		cand.push_back(node(str,ag,po));
	}
	sort(cand.begin(),cand.end(),cmp);
	for(int i=0;i<k;i++){
		scanf("%d%d%d",&m,&minn,&maxn);
		printf("Case #%d:\n",i+1);
		solve(m,minn,maxn);
	}
	return 0;
}
