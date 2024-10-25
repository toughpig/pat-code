#include<cstdio>
#include<iostream>
int main(){
	int a,b,c,aa,bb,cc;
	scanf("%d.%d.%d",&a,&b,&c);
	scanf("%d.%d.%d",&aa,&bb,&cc);
	int carry=0;
	c+=cc;
	carry=c/29;
	c=c%29;
	b+=bb;
	b+=carry;
	carry=b/17;
	b%=17;
	a+=aa+carry;
	printf("%d.%d.%d",a,b,c);
	return 0;
}
