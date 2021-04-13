//素数 埃式筛法 经肉眼测试，埃式筛法在10^7时有明显延迟 
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100000000;
bool isprime[maxn];

void getprime(int top){
	fill(isprime,isprime+maxn,true);
	isprime[0]=isprime[1]=false;
	for(int i=2;i<=top;i++){
		if(isprime[i]){
			for(int j=2*i;j<=top;j+=i){
				isprime[j]=false;
			}
		}
	}
}

int n,cnt=0;

int main(){
	scanf("%d",&n);
	getprime(n);
	for(int i=2;i<=n-2;i++){
		if(isprime[i]&&isprime[i+2]) cnt++;
	}
	printf("%d",cnt);
	return 0;
}
