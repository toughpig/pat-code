#include<cstdio>
using namespace std;
int temp=0,sum=-1;
int tempindex=0,left=0,right;
int main(){
	int N;
	scanf("%d",&N);
	right=N-1; 
	int a[N];
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
		temp+=a[i];
		if(temp>sum){
			sum=temp;
			left=tempindex;
			right=i;
		}
		else if(temp<0){
//			if(temp-a==sum&&i-tempindex-1<right-left){
//				left=tempindex;
//				right=i-1;
//			}
			tempindex=i+1;
			temp=0;
		}
	}
	if(sum<0)
		sum=0;
	printf("%d %d %d",sum,a[left],a[right]);
	return 0;
}
