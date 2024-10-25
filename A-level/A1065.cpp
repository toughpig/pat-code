#include<cstdio>
typedef long long LL;
int main(){
	LL a,b,c;
	LL N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		printf("Case #%d: ",i+1);
		LL d=a+b;
		if(a>0&&b>0&&d<0)
			printf("true\n");
		else if(a<0&&b<0&&d>=0)
			printf("false\n");
		else{
			if(d>c)
				printf("true\n");
			else
				printf("false\n");
		}
	}
	return 0;
}
