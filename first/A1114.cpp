#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

const int maxn=10100;

int fa[maxn];
int m[maxn];
int s[maxn];
int n,id,f,mo,k,mm,ss;
vector<int> child;

int findfa(int a){
	if(fa[a]==-1) return -1;
	int k=a;
	while(fa[a]!=a) a=fa[a];
	int p=fa[k];
	while(fa[k]!=a){
		fa[k]=a;
		k=p;
		p=fa[k];
	}
	return a;
}

void unionn(int a,int b){
	int faa=findfa(a);
	int fab=findfa(b);
	int minn=min(min(faa,fab),min(a,b));
	fa[faa]=minn;
	fa[fab]=minn;
	fa[a]=minn;
	fa[b]=minn;
}


struct node{
	int mem;
	float M,S;
	node(int a,int b,int c):mem(a),M(b),S(c){};
};

map<int,node> mp;

bool cmp(map<int,node>::iterator a,map<int,node>::iterator b){
	if(a->second.S/a->second.mem!=b->second.S/b->second.mem) return a->second.S/a->second.mem>b->second.S/b->second.mem;
	else{
		return a->first<b->first;
	}
}

int main(){
	fill(fa,fa+maxn,-1);
	fill(m,m+maxn,0);
	fill(s,s+maxn,0);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&id,&f,&mo,&k);
		if(fa[f]==-1) fa[f]=f;
		unionn(findfa(id),findfa(f));
		if(fa[mo]==-1) fa[mo]=mo;
		unionn(findfa(id),findfa(mo));
		child.clear();
		child.resize(k);
		for(int j=0;j<k;j++){
			scanf("%d",&child[j]);
			if(fa[child[j]]==-1)
				fa[child[j]]=child[j];
			unionn(findfa(id),findfa(child[j]));
		}
		scanf("%d%d",&mm,&ss);
		m[id]=mm;
		s[id]=ss;
	}
	for(int i=0;i<maxn;i++){
		if(findfa(i)==-1) continue;
		int fath=findfa(i);
		if(mp.find(fath)!=mp.end()){
			map<int,node>::iterator it=mp.find(fath);
			it->second.mem++;
			it->second.M+=m[i];
			it->second.S+=s[i];
		}
		else{
			mp.insert(make_pair(fath,node(1,m[fath],s[fath])));
		}
	}
//	sort(mp.begin(),mp.end(),cmp);
	printf("%d\n",mp.size());
	for(auto it=mp.begin();it!=mp.end();it++){
		int me=it->second.mem;
		printf("%d %d %.3f %.3f\n",it->first,me,it->second.M/me,it->second.S/me);
	}
	return 0;
}
