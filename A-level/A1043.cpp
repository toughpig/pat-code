#include<cstdio>
#include<vector>
using namespace std;
vector<int> ans;
bool flag=true;
const int maxn=1010;
int a[maxn];
int N;
void isst(int s,int e,bool m){
	int i,j;
	if(s>e){
		return;
	}
	else{
		if(m==false){
			for(i=s+1;i<=e;i++){
				if(a[i]>=a[s])
					break;
			}
			for(j=i;j<=e;j++){
				if(a[j]<a[s]){
					flag=false;
					break;
				}
			}
		}
		else{
			for(i=s+1;i<=e;i++){
			if(a[i]<a[s])
				break;
		}
		for(j=i;j<=e;j++){
				if(a[j]>=a[s]){
					flag=false;
					break;
				}
			}
		}
		isst(s+1,i-1,m);
		isst(i,e,m);
		ans.push_back(a[s]);
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",a+i);
	}
	isst(0,N-1,a[0]<=a[1]);
	if(N==1){
		printf("YES\n%d",a[0]);
	}
	else if(flag==false)
		printf("NO");
	else{
		printf("YES\n");
		for(int i=0;i<ans.size();i++){
			printf("%d",ans[i]);
			if(i<ans.size()-1)
				printf(" ");
		}
	}
	
	return 0;
}

