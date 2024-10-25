#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;

double score;
int n,temp;
string name,school;

struct node{
	string id;
	double score;
	string school;
};

struct sch{
	int mem;
	double sc;
	string ss;
};

map<string,int> mp;

int cnt=0;

vector<sch> Node;

bool cmp(sch a,sch b){
	if(floor(a.sc)!=floor(b.sc)) return a.sc>b.sc;
	else if(a.mem!=b.mem) return a.mem<b.mem;
	else return strcmp(a.ss.c_str(),b.ss.c_str())<0;
}

string low(string s){
	for(int i=0;i<s.size();i++){
		s[i]=tolower(s[i]);
	}
	return s;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>name>>score>>school;
		school=low(school);
		if(name[0]=='B') score/=1.5;
		else if(name[0]=='T') score*=1.5;
		if(mp.find(school)==mp.end()){
			mp[school]=cnt;
			Node.push_back(sch{1,score,school});
			cnt++;
		}
		else{
			Node[mp[school]].sc+=score;
			Node[mp[school]].mem++;
		}
	}
	sort(Node.begin(),Node.end(),cmp);
	cnt=1;
	int rank=1;
	printf("%d\n",Node.size());
	for(int i=0;i<Node.size();i++){
		if(i==0){
			rank=cnt;
			printf("%d %s %d %d\n",cnt,Node[i].ss.c_str(),(int)(Node[i].sc),Node[i].mem);
			cnt++;
			continue;
		}
		else if(floor(Node[i].sc)==floor(Node[i-1].sc)){
			printf("%d %s %d %d\n",rank,Node[i].ss.c_str(),(int)(Node[i].sc),Node[i].mem);
			cnt++;
		}
		else{
			printf("%d %s %d %d\n",cnt,Node[i].ss.c_str(),(int)(Node[i].sc),Node[i].mem);
			rank=cnt;
			cnt++;	
		}
	}
	return 0;
}
