#include<cstdio>
#include<cstdlib>
#include<cmath>

int main(){
	int a=INT_MAX;
	long long bb=(48631067547955363834+2)/2;
	bb*=bb;
	printf("%d\n%0xd\n%d\n%d\n%d\n%lld",a,a,a+1,a+2,a*2+3,bb);
	return 0;
}
