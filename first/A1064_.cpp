#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn =1010;
int bst[maxn];
int a[maxn];
int N;
int index=0;
void inorder(int root){
	if(root>N)
	return;
	inorder(2*root);
	bst[root]=a[index++];
	inorder(root*2+1);
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",a+i);
	}
	sort(a,a+N);
	inorder(1);
	for(int i=1;i<=N;i++){
		printf("%d",bst[i]);
		if(i<N)
		printf(" ");
	}
	return 0;
}
 
