#include<cstdio>
#include<queue>
using namespace std;
struct mouse{
	int k;int w;
}mc[1001];
queue<int> q;
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	int od[101];
	for(int i=0;i<N;i++){
		scanf("%d",&mc[i].w);
	} 
	for(int i=0;i<N;i++){
		scanf("%d",od+i);
		q.push(od[i]);
	}
	int temp=N;
	while(q.size()!=1){
		int g;
		if(temp%M==0)
			g=temp/M;
		else
			g=temp/M+1;
		for(int i=0;i<g;i++){
			int maxn=q.front(); 
			for(int j=0;j<M;j++){
				if(i*M+j>=temp){
					break;
				}
				int e=q.front();
				if(mc[maxn].w<mc[e].w){
					maxn=e;
				}
				mc[e].k=g+1;
				q.pop();
			}
			q.push(maxn);
		}
			temp=g;
		
	}
	int win=q.front();
	mc[win].k=1;
	for(int i=0;i<N;i++){
		printf("%d",mc[od[i]].k);
		if(i<N-1)
		printf(" ");
	}
	return 0;
}
