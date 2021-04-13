#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,r;

bool isprime(int n){
	if(n==1) return false;
	for(int k=floor(sqrt(n));k>=2;k--){
		if(n%k==0)
			return false;
	}
	return true;
}

void print(int n,int r){
	if(isprime(n)==false){
		printf("No\n");
		return;
	}
	int cnt=0;
	int c[1000];
	while(n){
		c[cnt++]=n%r;
		n/=r;
	}	
	int sum=0;
	for(int i=0;i<cnt;i++){
		sum=sum*r+c[i];
	}
	if(isprime(sum))
		printf("Yes\n");
	else
		printf("No\n");
	return;
}

int main(){
	while(1){
		scanf("%d",&n);
		if(n<0)
			break;
		scanf("%d",&r);
		print(n,r);
	}
	return 0;
}
