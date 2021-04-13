#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=10010;

int cluster[maxn];
int rec[maxn];
int findfa(int a){//找根 
	int x=a;
	while(x!=rec[x])
		x=rec[x];
	while(a != rec[a]) {
        int z = a;
        a = rec[a];
        rec[z] = x;
    }
	return x;
}

void uni(int a,int b){//A->B
	int fa=findfa(a);//此处若rec[findfa(a)]=findfa(b) ;会发生数据冒险；出错 
	int fb=findfa(b);
	if(fa!=fb)
	rec[fa]=fb;
}

bool cmp(int a,int b){
	return a>b;
}
int isroot[maxn]={0};

int main(){
	int cnt=0;
	fill(cluster,cluster+maxn,-1);
	for(int i=0;i<maxn;i++)
		rec[i]=i;
	int N,k,nn;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d:",&k);
//		getchar();
		for(int j=0;j<k;j++){
			scanf("%d",&nn);
			if(cluster[nn]==-1)
				cluster[nn]=i;
			uni(i,findfa(cluster[nn]));
		}
	}
	for(int i=0;i<N;i++){
//		if(findfa(i)==i)
//			cnt++;
		isroot[findfa(i)]++;
		
	}
	for(int j=0;j<N;j++){
		if(isroot[j]!=0)
		cnt++;
	}
	sort(isroot,isroot+N,cmp);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		printf("%d",isroot[i]);
		if(i<cnt-1)
			printf(" ");
	}
	return 0;
} 

 
