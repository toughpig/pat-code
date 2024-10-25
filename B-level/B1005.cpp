//直接打表覆盖
#include<cstdio>

const int maxn=105;
int n;
bool cnted[maxn]={false};
bool ans[maxn]={false};//记录未被覆盖的数 
int cnt=0;
int temp;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if(cnted[temp]==false){
			ans[temp]=true;
			while(temp!=1){
				if(temp%2) temp=(temp*3+1)/2;
				else temp/=2;
				if(temp>=maxn) continue;  //防止数组越界，并且越界的数没用 
				cnted[temp]=true;
				if(ans[temp]==true){
					ans[temp]=false;
					break;   //temp已经算过 
				}
			}
		}
	}
	for(int i=maxn-1;i>=2;i--){
		if(ans[i]==true&&cnt==0){
			printf("%d",i);
			cnt++;
		}
		else if(ans[i]){
			printf(" %d",i);
		}
	}
	return 0;
} 
