#include<cstdio>
static int cnt;
int level[100];
int record[100];
 void post(int next[],int record[],int k,int f){
		for(int j=0;j<f;j++){
			record[next[j]]=k;
		}
	}

int win(int s,int M,int e,int a[],int w[]){
	int len=M;
	if(e-s+1<M)
	len=e-s+1;
	int maxn=a[s];
	for(int i=0;i<len;i++){
		if(w[a[i+s]]>w[maxn])
		maxn=a[i+s];
	}
	return maxn;
}
void rank(int N,int M,int a[],int k,int w[]){
	cnt=k;
	int f;
	if(N%M==0)
		f=N/M;
	else
		f=N/M+1;
	int next[f];
	for(int i=0;i<f;i++){
		next[i]=win(i*M,M,N-i*M,a,w);
	}
	level[k-1]=f+1;
	post(next,record,k,f);
	if(N>M)
		rank(f,M,next,k+1,w);
	
}


int main(){
	int N,G;
	scanf("%d %d",&N,&G);
	int w[N];
	int order[N];
	int n=N;
	for(int i=0;i<N;i++){
		record[i]=1;
		scanf("%d",&w[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&order[i]);
	}
	rank(N,G,order,2,w);
	level[cnt]=1;
	for(int i=0;i<N;i++){
		printf("%d",level[record[i]]);
		if(i<N-1)
		printf(" ");
	}
	return 0;
} 
