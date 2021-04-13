#include<cstdio>

const char num[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void print(int a){
	if(a==0) return;
	print(a/10);
	if(a/10!=0)
		printf(" ");
	printf("%s",num[a%10]);
}

int main(){
	char ch;
	int sum=0;
	while((ch=getchar())!='\n') sum+=ch-'0';
	if(sum==0)
		printf("zero");
	print(sum);
}
