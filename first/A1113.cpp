#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> num;

int main(){
	int n;
	scanf("%d",&n);
	if(n%2==1) printf("1 ");
	else printf("0 ");
	int temp;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		num.push_back(temp);
	}
	sort(num.begin(),num.end());
	int sum=0;
	for(int i=0;i<num.size()/2;i++)
		sum-=num[i];
	for(int i=num.size()/2;i<num.size();i++)
		sum+=num[i];
	printf("%d",sum);
	return 0;
}
