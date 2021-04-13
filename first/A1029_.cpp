#include<cstdio>
#include<vector>
using namespace std;

vector<int> a;
int n,m,temp;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		a.push_back(temp);
	}
	scanf("%d",&m);
	int mid=(n+m+1)/2;
	int cnt=0;
	int first=0;
	for(int i=0;i<m;i++){
		scanf("%d",&temp);
		for(int j=0;j<n;j++){
			if(a[first]<temp){
				cnt++;
				first++;
				if(cnt==mid) printf("%d",a[j]);
			}
			else{
				break;
			}
		}
		if(cnt==cnt) continue;
		else if(){
			
		}
	}
	return 0;
}
