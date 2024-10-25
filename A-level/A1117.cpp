#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n,temp;
int ans=0;
vector<int> num;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		num.push_back(temp);
	}
	sort(num.begin(),num.end());
	for(int i=0;i<num.size();i++){
		int k=num[i];
		auto it=lower_bound(num.begin(),num.end(),k);
		auto itt=upper_bound(num.begin(),num.end(),k);
		int pos=num.end()-it;
		if(pos>=k)
			ans=min(*itt-1,pos);
		
	}
	printf("%d",ans);
	return 0;
}
