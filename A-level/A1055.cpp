#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
#include<cstring>
#include<stack>
using namespace std;
vector<int> ve;
const int maxn=100020;
int num[maxn];
const int block=ceil(sqrt(maxn));
const int cnt=floor(sqrt(maxn));
int b[block]={0};

int findnum(int i,int q){
	int s=0;
	for(int j=cnt*(i+1)-1;j>=cnt*i;j--){
		s+=num[j];
		if(s>q)
			return j;
	}
}

int findmid(){
	int len=ve.size();
	int k;
	if(len%2==0)
		k=len/2;
	else
		k=(len+1)/2;
	int sum=0;
	int i;
	for(i=0;i<block;i++){
		sum+=b[i];
		if(sum>=k)
			break;
	}
	int q=sum-k;
	return findnum(i,q);
}

void push(int a){
	ve.push_back(a);
	b[a/cnt]++;
	num[a]++;
}

void pop(){
	if(ve.empty()){
		printf("Invalid\n");
		return;
	}
	else{
		int k=ve[ve.size()-1];
		num[k]--;
		printf("%d\n",k);
		b[k/cnt]--;
		ve.pop_back();
		return;
	}
}

void popmid(){
	if(ve.empty()){
		printf("Invalid\n");
		return;
	}
	else{
		int k=findmid();
		printf("%d\n",k);
	}
}

int main(){
	fill(num,num+maxn,0);
	int N;
	scanf("%d\n",&N);
	char ch[15];
	int val;
	for(int i=0;i<N;i++){
		scanf("%s",ch);
		if(strcmp(ch,"PeekMedian\0")==0)
			popmid();
		else if(strcmp(ch,"Pop\0")==0)
			pop();
		else{
			scanf("%d\n",&val);
			push(val);
		}
	}
	return 0;
}
