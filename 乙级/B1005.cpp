//ֱ�Ӵ����
#include<cstdio>

const int maxn=105;
int n;
bool cnted[maxn]={false};
bool ans[maxn]={false};//��¼δ�����ǵ��� 
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
				if(temp>=maxn) continue;  //��ֹ����Խ�磬����Խ�����û�� 
				cnted[temp]=true;
				if(ans[temp]==true){
					ans[temp]=false;
					break;   //temp�Ѿ���� 
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
