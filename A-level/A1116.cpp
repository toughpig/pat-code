#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100010;

int rankk[maxn]={0};
bool vist[maxn]={false};
int n,temp,k;
bool prime[maxn]={false};

int main(){
	fill(prime+2,prime+maxn,true);
	for(int i=2;i<maxn;i++){
		for(int j=2;j*i<maxn;j++){
			prime[i*j]=false;
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&temp);
		rankk[temp]=i;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&temp);
		if(rankk[temp]==0) printf("%04d: Are you kidding?\n",temp);
		else{
			if(vist[temp]==true) printf("%04d: Checked\n",temp);
			else{
				vist[temp]=true;
				if(rankk[temp]==1) printf("%04d: Mystery Award\n",temp);
				else if(prime[rankk[temp]]==true) printf("%04d: Minion\n",temp);
				else printf("%04d: Chocolate\n",temp);
			}
		}
	}
	return 0;
}
