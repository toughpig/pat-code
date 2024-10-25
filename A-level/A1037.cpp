#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100010;
int a[maxn],b[maxn];
LL sum=0;
bool cmp(LL a,LL b){
	return a<b;
}

int main(){
	int nc,np;
	scanf("%d",&nc);
	for(int i=0;i<nc;i++){
		scanf("%ld",a+i);
	}
	scanf("%d",&np);
	for(int i=0;i<np;i++){
		scanf("%ld",b+i);
	}
	sort(a,a+nc,cmp);
	sort(b,b+np,cmp);
	int mid1=0,mid2=0;
	for(int i=0;i<nc;i++){
		if(a[i]>=0){
			mid1=i;
			break;
		}
	}
	if(a[nc-1]<0)
		mid1=nc;
	for(int i=0;i<np;i++){
		if(b[i]>=0){
			mid2=i;
			break;
		}
	}
	if(b[np-1]<0)
		mid2=np;
	int k1=0;
	int p1=nc-1;
	int k2=0;
	int p2=np-1;
	while(k1<mid1&&k2<mid2){
		sum+=a[k1]*b[k2];
		k1++;
		k2++;
	}
	while(p1>=mid1&&p2>=mid2){
		sum+=a[p1]*b[p2];
		p1--;
		p2--;
	}
	printf("%ld",sum);
	return 0;
}
