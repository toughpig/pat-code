#include<cstdio>
int level[100010];
int post[10010];
	int in[10010];
void pre(int pol,int por,int inl,int inr,int index){
	if(inl>inr){
		return;
	}
	int i;
	for(i=inl;i<=inr;i++){
		if(in[i]==post[por])
		break;
	}
	level[index]=post[por];
	pre(pol,pol+i-inl-1,inl,i-1,2*index+1);
	pre(pol+i-inl,por-1,i+1,inr,index*2+2);
	
}
int main(){
	int N;
	scanf("%d",&N);
	
	for(int i=0;i<N;i++){
		scanf("%d",post+i);
	}
	for(int i=0;i<N;i++){
		scanf("%d",in+i);
	}
	pre(0,N-1,0,N-1,0);
	int k=0;
	for(int i=0;i<N;){
		if(level[k]!=0){
			printf("%d",level[k]);
			if(i<N-1)
			printf(" ");
			i++;
		}
		k++;
	}
	
	return 0;
}

