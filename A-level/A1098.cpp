#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=110;
int orig[maxn];
int mid[maxn];
int inso[maxn];
int heso[maxn];
int N;
bool flag=false;

void swap(int a,int b){
	heso[a]+=heso[b];
	heso[b]=heso[a]-heso[b];
	heso[a]-=heso[b];
}

void print(int a[]){
	for(int i=1;i<=N;i++){
		printf("%d",a[i]);
		if(i!=N)
		printf(" ");
	}
}

void downadjust(int low,int high){
	int i=low;
	int j=2*i;
	while(j<=high){
		if(j+1<=high&&heso[j+1]>heso[j]){
			j=j+1;
		}
		if(heso[i]<heso[j]){
			swap(i,j);
			i=j;
			j=i*2;
		}
		else
		break;
	}
}

bool issame(int a[],int b[]){
	for(int i=1;i<=N;i++){
		if(a[i]!=b[i])
		return false;
	}
	return true;
}

bool insertsort(){
//	inso[1]=orig[1];
	int i=2;
	for(i;i<=N;i++){
		sort(inso+1,inso+i+1);
		if(issame(inso,mid)){
			flag=true;
		}
		if(flag){
			sort(inso+1,inso+i+2);
			printf("Insertion Sort\n");
			print(inso);
			return flag;
		}
	}
	return flag;
}

void heapsort(){
	flag=false;
	for(int i=N/2;i>=1;i--){
//		heso[i]+=heso[1];
//		heso[1]=heso[i]-heso[1];
//		heso[i]-=heso[1];
		downadjust(i,N);
	}
	int k=N;
	for(k;k>1;k--){
		if(k!=N&&issame(mid,heso)){
			flag=true;
		}
		swap(k,1);
		downadjust(1,k-1);
		
		if(flag){
//			swap(k-1,1);
//			downadjust(1,k-2);
			printf("Heap Sort\n");
			print(heso);
			return;
		}
	}
}

int main(){
//	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",orig+i);
		inso[i]=orig[i];
		heso[i]=orig[i];
	}
	for(int i=1;i<=N;i++){
		scanf("%d",mid+i);
	}
	
	insertsort();
	if(flag==false)
	heapsort();
	return 0;
}
 
