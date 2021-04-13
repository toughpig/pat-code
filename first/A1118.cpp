#include<cstdio>
#include<vector>
using namespace std;

const int maxn=105;
int fa[maxn];
bool vis[maxn];
bool vist[maxn]={false};

int n,num,temp,k,a1,a2;
vector<int> bird;

int findfa(int a){
	if(fa[a]==-1) return -1;
	while(fa[a]!=a) a=fa[a];
	return a;
}

int findfaa(int a){
	if(fa[a]==-1) return -1;
	int k=a;
	int p=a;
	while(fa[a]!=a) a=fa[a];
	while(fa[k]!=a){
		p=fa[k];
		fa[k]=a;
		k=p;
	}
	return a;
}

void unionn(int a,int b){
	int faa=findfa(a);
	int fab=findfa(b);
	if(faa<fab)
	fa[fab]=faa;
	else
	fa[faa]=fab;
}

int main(){
	fill(fa,fa+maxn,-1);
	fill(vis,vis+maxn,false);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		bird.clear();
		bird.resize(num);
		for(int j=0;j<num;j++){
			scanf("%d",&bird[j]);
			if(fa[bird[j]]==-1){
				fa[bird[j]]=bird[j];
			}
			if(j>0&&fa[bird[j]]!=fa[bird[j-1]]){
				unionn(findfaa(bird[j-1]),fa[bird[j]]);
			}
		}
	}
	int cnt=0,bcnt=0;
	for(int i=0;i<maxn;i++){
		if(fa[i]!=-1) bcnt++;
		int fat=findfa(i);
		if(fat!=-1&&vis[fat]==false){
			cnt++;
			vis[fat]=true;
		}
	}
	printf("%d %d\n",cnt,bcnt);
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d%d",&a1,&a2);
		if(findfaa(a1)==findfaa(a2)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
