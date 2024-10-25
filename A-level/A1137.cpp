#include<cstdio>
#include<map>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;

int p,n,m,idd,gpp,gmm,gff;
string name;

map<string,int> mp;

struct node{
	string id;
	int gp,gm,gf,g;
//	node(string a,int b,int c,int d,int e):id(a),gp(b),gm(c),gf(d),g(e){};
};

node Node[10000];

vector<node> ve;

bool cmp(node a,node b){
	if(a.g!=b.g) return a.g>b.g;
	else return strcmp(a.id.c_str(),b.id.c_str())<0;
}

int main(){
	scanf("%d%d%d",&p,&n,&m);
	int cnt=0;
	for(int i=0;i<p;i++){
		cin>>name>>gpp;
		if(gpp>=200){
			mp[name]=cnt;
			Node[cnt].id=name;
			Node[cnt].gp=gpp;
			Node[cnt].gf=-1;
			Node[cnt].gm=-1;
			cnt++;
		}
	}
	for(int i=0;i<n;i++){
		cin>>name>>gmm;
		if(mp.find(name)==mp.end()) continue;
		int index=mp.find(name)->second;
		Node[index].gm=gmm;
	}
	for(int i=0;i<m;i++){
		cin>>name>>gff;
		if(mp.find(name)==mp.end()) continue;
		int index=mp.find(name)->second;
		Node[index].gf=gff;
	}
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
		int j=it->second;
		if(Node[j].gm>Node[j].gf) Node[j].g=round((double)Node[j].gm*0.4+(double)Node[j].gf*0.6);
		else Node[j].g=Node[j].gf;
		if(Node[j].g>=60)
		ve.push_back(Node[j]);
	}
	sort(ve.begin(),ve.end(),cmp);
	for(int i=0;i<ve.size();i++){
		printf("%s %d %d %d %d\n",ve[i].id.c_str(),ve[i].gp,ve[i].gm,ve[i].gf,ve[i].g);
	}
	return 0;
}
