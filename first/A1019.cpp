#include<cstdio>
#include<string>
#include<vector>
using namespace std;
typedef long L;
L n,radix;
vector<L> ans;
int main(){
	scanf("%d%d",&n,&radix);
	while(n!=0){
		ans.push_back(n%radix);
		n/=radix;
	}
	for(int i=0;i<ans.size()/2;i++){
		if(ans[i]!=ans[ans.size()-1-i]){
			printf("No\n");
			for(int j=0;j<ans.size();j++){
				printf("%ld",ans[ans.size()-1-j]);
				if(j<ans.size()-1)
					printf(" ");
			}
			return 0;
		}
	}
	printf("Yes\n");
	for(int i=0;i<ans.size();i++){
		printf("%ld",ans[ans.size()-1-i]);
		if(i<ans.size()-1)
			printf(" ");
		}
	return 0;
} 
