//并查集 和 kruskal思想 
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=500000;
int cost[maxn];
int fa[500];
vector<int> lost;    //以A*1000+B hash出的边 
vector<int> remain;

int c1,c2,w,s,n,m;
int mm,oldmm;
vector<int> ans;

int findfa(int a){
	int k=a;
	int p=a;
	while(fa[a]!=a){
		a=fa[a];
	}
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
	if(faa!=fab) fa[faa]=fab;
}

bool cmp(int a,int b){
	return cost[a]<cost[b];
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&c1,&c2,&w,&s);
		c1=c1*1000+c2;
		if(s==1) remain.push_back(c1);
		else{
			lost.push_back(c1);
			cost[c1]=w;
		}
	}
	sort(lost.begin(),lost.end(),cmp);
	oldmm=-1;
	for(int i=1;i<=n;i++){              //对于每个节点 
		mm=0; 
		for(int j=1;j<=n;j++) fa[j]=j;    //并查集初始化
		for(int j=0;j<remain.size();j++){
			c1=remain[j]/1000;
			c2=remain[j]%1000;
			if(c1==i||c2==i) continue;
			unionn(c1,c2);
		}
		for(int j=0;j<lost.size();j++){
			c1=lost[j]/1000;
			c2=lost[j]%1000;
			if(c1==i||c2==i) continue;
			if(findfa(c1)!=findfa(c2)){  //kruskal
				mm+=cost[lost[j]];
				unionn(c1,c2);
			}
		}
		bool connected=true;
		int p=1;
		while(p==i) p++;
		for(int j=p+1;j<=n;j++){
			if(j==i) continue;
			int faa=findfa(p);
			int fab=findfa(j);
			if(faa!=fab){
				connected=false;
				break;
			}
		}
		if(connected==false&&oldmm==maxn){
			ans.push_back(i);
		}
		else if(connected==false){
			ans.clear();
			ans.push_back(i);
			oldmm=maxn;
		}
		else if(oldmm!=maxn&&connected){  //可以修复到连通 
			if(mm!=0&&mm>oldmm){
				oldmm=mm;
				ans.clear();
				ans.push_back(i);
			}
			else if(mm!=0&&mm==oldmm){
				ans.push_back(i);
			}
		}
	}
	if(oldmm==-1) printf("0");
	for(int i=0;i<ans.size();i++){
		if(i==0) printf("%d",ans[i]);
		else printf(" %d",ans[i]);
	}
	return 0;
}
