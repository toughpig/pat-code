//数据处理，排序，查找映射
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

const int maxn=1000000;
int exist[maxn];

struct node{
	int id,rank,rankid;
	int score[4];
	int ra[4];
	node(int idd,int kk):id(idd),rank(kk){}
};

vector<node> Node;
int n,m,name,C,M,E;
static int tag;

const char clas[4]={'A','C','M','E'};

bool cmp(node a,node b){
	if(a.score[tag]!=b.score[tag]) return a.score[tag]>b.score[tag];
	else return a.id<b.id;
}

int main(){
	scanf("%d%d",&n,&m);
	fill(exist,exist+maxn,-1);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&name,&C,&M,&E);
		Node.push_back(node(name,1<<30));
		Node[i].score[0]=C+M+E;
		Node[i].score[1]=C;
		Node[i].score[2]=M;
		Node[i].score[3]=E;
	}
	for(tag=0;tag<=3;tag++){
		sort(Node.begin(),Node.end(),cmp);
		int cnt=1;
		Node[0].ra[tag]=1;
		if(Node[0].rank>Node[0].ra[tag]){
				Node[0].rank=Node[0].ra[tag];
				Node[0].rankid=tag;
		}
		for(int i=1;i<n;i++){
			cnt++;
			if(Node[i].score[tag]==Node[i-1].score[tag]){
				Node[i].ra[tag]=Node[i-1].ra[tag];
			}
			else{
				Node[i].ra[tag]=cnt;
			}
			if(Node[i].rank>Node[i].ra[tag]){
				Node[i].rank=Node[i].ra[tag];
				Node[i].rankid=tag;
			}
		}
		if(tag==3){
			for(int i=0;i<n;i++){
				exist[Node[i].id]=i;
			}
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d",&name);
		if(exist[name]==-1) printf("N/A\n");
		else printf("%d %c\n",Node[exist[name]].rank,clas[Node[exist[name]].rankid]);
	}
	return 0;
} 
