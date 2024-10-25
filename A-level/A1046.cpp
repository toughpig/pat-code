#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100010;
int dist[maxn];
int N,M;

int clock[maxn];
//int clockrev[maxn];

void getclock(int n){
	clock[n]=dist[n];
	for(int i=n-1;i>=1;i--){
		clock[i]=dist[i]+clock[i+1];
	}
}

void print(int a,int b){
	printf("%d\n",min(min(clock[1]-clock[a],clock[a])+min(clock[1]-clock[b],clock[b]),min(abs(clock[a]-clock[b]),abs((clock[1]-clock[a])-(clock[1]-clock[b])))));
}

int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",dist+i+1);
	}
	scanf("%d",&M);
	getclock(N);
//	for(int i=1;i<=N;i++)
//	printf("%d\n",clock[i]);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		print(a,b);
	}
	return 0;
}
