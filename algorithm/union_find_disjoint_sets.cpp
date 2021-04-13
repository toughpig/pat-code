//并查集

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=10010;

int fa[maxn];
int depth[maxn];

int findfa(int a){
	if(fa[a]==a)
		return a;
	else
	{
		fa[a] = findfa(fa[a]);//路径压缩
		return fa[a];
	}
}

void join(int a,int b){
	int faa=findfa(a);
	int fab=findfa(b);
	fa[fab] = faa;
	//进一步缩小时间复杂度，可以按秩合并
}

int main(){
	for(int i=0;i<maxn;i++){
		fa[i]=i;
		//depth[i]=1;
	}
	return 0;
} 

 
