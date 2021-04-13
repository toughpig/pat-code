#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1010;
struct moon{
	float held;
	float price;
}cake[maxn];
bool cmp(moon a,moon b){
	return a.price/a.held>=b.price/b.held;
}
int main(){
	int N;
	float demand;
	scanf("%d%f",&N,&demand);
	for(int i=0;i<N;i++){
		scanf("%f",&cake[i].held);
	}
	for(int i=0;i<N;i++){
		scanf("%f",&cake[i].price);
	}
	float profit=0.0;
	sort(cake,cake+N,cmp);
	float k=0.0;
	int cnt=0;
	while(k<=demand&&cnt<N){			//供不应求，坑 
		if(k+cake[cnt].held<=demand){
			k+=cake[cnt].held;
			profit+=cake[cnt].price;
			cnt++;
		}
		else{
			float p=demand-k;
			float q=cake[cnt].held;
			profit+=(p*(cake[cnt].price/q));
			break;
		}
	}
	printf("%.2f",profit);
	return 0;
} 
