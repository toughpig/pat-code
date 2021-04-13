#include<cstdio>
#include<stack>
#include<iostream>
using namespace std;
stack<int> t;
//bool cd[100]={false};
//void print(bool a){
//	if(a)
//		printf("YES\n");
//	else
//		printf("NO\n");
//			
//}
//void reset(bool a[]){
//	for(int i=0;i<100;i++)
//		a[i]=false;
//}
int main(){
	int N,M,K;
	int tbc[100]={-1};
	scanf("%d%d%d",&M,&N,&K);
	int k=K;
	int num;
	int now;
	bool flag;
//	int p=1;
	while(k--){
		while(!t.empty())
			t.pop();
	    flag=true;
		now=0;
		int p=1;
		for(int i=0;i<N;i++){
			scanf("%d",&num);
			tbc[i]=num;
		} 
	while(p<=N){
		t.push(p);
		if(t.size()>M){
			flag=false;
			break;
		}
		while(!t.empty()&&t.top()==tbc[now]){
			t.pop();
			now++;
		}
		p++;
	}
	if(t.empty()==true&&flag==true)
	printf("YES\n");
	else
	printf("NO\n");
}
	return 0;
}
