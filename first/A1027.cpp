#include<cstdio>
void printt(int a){
	if(a<=9)
	printf("%d",a);
	else{
	char temp=a-10+'A';
	printf("%c",temp);
}
}
void print(int a){
	int h=a/13;
	int l=a%13;
	printt(h);
	printt(l);
}
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("#");
	print(a);
	print(b);
	print(c);
	return 0;
}
