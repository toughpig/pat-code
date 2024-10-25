//一年前写的代码，头铁的一批 
#include<iostream>
#include<cstdio> 
using namespace std;
//int main(){
//	int i;
//	scanf("%d",&i);
//	if(i<10)
//    	for(int k=1;k<=i;k++)
//      		cout<<k;
//	if(i>=10&&i<100){
//		for(int k=1;k<=i/10;k++)
//      		cout<<'S';
//    	for(int k=1;k<=i%10;k++)
//      		cout<<k;
//    }
//  	if(i>=100&&i<1000){
//    	for(int k=1;k<=i/100;k++)
//      		cout<<'B';
//    	for(int k=1;k<=(i/10)%10;k++)
//      		cout<<'S';
//    	for(int k=1;k<=i%10;k++)
//      		cout<<k;
//  	}
//  	return 0;
//}
//---------------------------
const char sign[2]={'B','S'};
void print(int a,int b){
	if(a==0) return;
	for(int i=0;i<a;i++) printf("%c",sign[b]);
}
int main(){
	int num;
	scanf("%d",&num);
	print(num/100,0);
	print(num%100/10,1);
	for(int i=0;i<num%10;i++) printf("%d",i+1);
	return 0;
}

