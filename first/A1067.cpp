#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=100010;
int num[maxn];
int temp;
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&temp);
		num[temp]=i;
	}
	int cnt=N;
	
	return 0;
} 
