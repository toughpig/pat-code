//Ä£Äâ online
#include<cstdio>

int k,nowpos,dest;
int ans=0;

void count(int a,int b){
	int len=b-a;
	if(len>0) ans+=len*6;
	else ans-=len*4;
	ans+=5;
}

int main(){
	scanf("%d",&k);
	nowpos=0;
	for(int i=0;i<k;i++){
		scanf("%d",&dest);
		count(nowpos,dest);
		nowpos=dest;
	}
	printf("%d",ans);
	return 0;
} 
