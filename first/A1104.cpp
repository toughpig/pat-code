#include<cstdio>
#include<vector>
using namespace std;

const int maxn=100010;
double num[maxn];
double sum=0.0;
int n;

int main(){
	scanf("%d",&n);
	double temp;
	for(int i=1;i<=n;i++){
		scanf("%lf",&temp);
		sum+=temp*i*(n-i+1);
	}
	printf("%.2lf",sum);
	return 0;
}
