#include<cstdio>
#include<stack>
using namespace std;
stack<int> s;
int cnt=0;
void print(int a){
	if(a<0){
		printf("-");
		print(-1*a);
		return;
	}
	if(a<=999){
		printf("%d",a);
		return;
	}
//	  printf("%d",a);
	if(a>999){
//		int ab=a%1000;
		while(a!=0){
			s.push(a%1000);
			a=a/1000;
//			cnt++;
		}
		
	}
	if(!s.empty()){
		int temp=s.top();
		s.pop();
		printf("%d",temp);
	}
//	printf("%d",temp);
	while(!s.empty()){
		int temp=s.top();
		s.pop();
		printf(",%03d",temp);
	}
}
int main(){
	int m,n;
	scanf("%d%d",&n,&m);
	print(n+m);
	return 0;
}
