//格式输出，简单数据处理
#include<cstdio>

void print(int a){
	if(a<0){
		printf("-");
		print(a*-1);
		return;
	}
	if(a==0){
		printf("0");
		return;
	}
	if(a<1000){
		printf("%d",a);
		return;
	}
	print(a/1000);
	printf(",%03d",a%1000);
} 

int main(){
	int aa,bb;
	scanf("%d%d",&aa,&bb);
	print(aa+bb);
	return 0;
}
