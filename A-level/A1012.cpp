#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int id,c,m,e,a;
	pair<char,int> rank;
	node(int _a,int _id,int _c,int _m,int _e,pair<char,int> _rank):a(_a),id(_id),c(_c),m(_m),e(_e),rank(_rank){};
};
map<int,int> mp;
vector<node> ve;
int N,M;
int idd,cc,mm,ee;
bool cmp(node aa,node bb){
	return aa.a>bb.a;
}
bool cmp1(node aa,node bb){
	return aa.c>bb.c;
}
bool cmp2(node aa,node bb){
	return aa.m>bb.m;
}
bool cmp3(node aa,node bb){
	return aa.e>bb.e;
}
void solve(char ch){
	if(ch=='A')
	for(int i=0;i<ve.size();i++){
		if(i==0&&ve[i].rank.second>1){
			ve[i].rank.second=1;
			ve[i].rank.first=ch;
			continue;
		}
		if(ve[i].a==ve[i-1].a&&ve[i].rank.second>ve[i-1].rank.second){
			ve[i].rank.second=ve[i-1].rank.second;
			ve[i].rank.first=ch;
		}
		else if(ve[i].a!=ve[i-1].a&&ve[i].rank.second>i+1){
			ve[i].rank.second=i+1;
			ve[i].rank.first=ch;
		}	
	}
	else if(ch=='C')
	for(int i=0;i<ve.size();i++){
		if(i==0&&ve[i].rank.second>1){
			ve[i].rank.second=1;
			ve[i].rank.first=ch;
			continue;
		}
		if(ve[i].c==ve[i-1].c&&ve[i].rank.second>ve[i-1].rank.second){
			ve[i].rank.second=ve[i-1].rank.second;
			ve[i].rank.first=ch;
		}
		else if(ve[i].c!=ve[i-1].c&&ve[i].rank.second>i+1){
			ve[i].rank.second=i+1;
			ve[i].rank.first=ch;
		}	
	}
	else if(ch=='M')
	for(int i=0;i<ve.size();i++){
		if(i==0&&ve[i].rank.second>1){
			ve[i].rank.second=1;
			ve[i].rank.first=ch;
			continue;
		}
		if(ve[i].m==ve[i-1].m&&ve[i].rank.second>ve[i-1].rank.second){
			ve[i].rank.second=ve[i-1].rank.second;
			ve[i].rank.first=ch;
		}
		else if(ve[i].m!=ve[i-1].m&&ve[i].rank.second>i+1){
			ve[i].rank.second=i+1;
			ve[i].rank.first=ch;
		}	
	}
	else
	for(int i=0;i<ve.size();i++){
		if(i==0&&ve[i].rank.second>1){
			ve[i].rank.second=1;
			ve[i].rank.first=ch;
			continue;
		}
		if(ve[i].e==ve[i-1].e&&ve[i].rank.second>ve[i-1].rank.second){
			ve[i].rank.second=ve[i-1].rank.second;
			ve[i].rank.first=ch;
		}
		else if(ve[i].e!=ve[i-1].e&&ve[i].rank.second>i+1){
			ve[i].rank.second=i+1;
			ve[i].rank.first=ch;
		}	
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d%d%d%d",&idd,&cc,&mm,&ee);
		node temp=node(cc+mm+ee,idd,cc,mm,ee,make_pair('a',N+1));
		ve.push_back(temp);
	}
	sort(ve.begin(),ve.end(),cmp);
	solve('A');	
	sort(ve.begin(),ve.end(),cmp1);
	solve('C');
	sort(ve.begin(),ve.end(),cmp2);
	solve('M');
	sort(ve.begin(),ve.end(),cmp3);
	solve('E');
	int q=0;
	for(int i=0;i<ve.size();i++){
		int k=ve[i].id;
		mp[k]=q++;
	}
	for(int i=0;i<M;i++){
		int check;
		scanf("%d",&check);
		if(mp.find(check)!=mp.end()){
			int k=mp[check];
			printf("%d %c\n",ve[k].rank.second,ve[k].rank.first);
		}
		else
		printf("N/A\n");
	}
	return 0;
}
