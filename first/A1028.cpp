#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct stu{
	int id;
	char na[10];
	int g;
}st[maxn];
bool cmp1(stu a,stu b){
	return a.id<b.id;
}
bool cmp2(stu a,stu b){
	int k=strcmp(a.na,b.na);
	if(k==0)
		return a.id<b.id;
	else if(k<0)
	return true;
	else return false;
}
bool cmp3(stu a,stu b){
	int k=a.g-b.g;
	if(k==0)
		return a.id<b.id;
	else if(k<0)
	return true;
	else return false;
}

int N,C;
int main(){
	scanf("%d%d",&N,&C);
	for(int i=0;i<N;i++){
		scanf("%d %s %d",&st[i].id,&st[i].na,&st[i].g);
	}
	if(C==1)
		sort(st,st+N,cmp1);
	if(C==2)
		sort(st,st+N,cmp2);
	if(C==3)
		sort(st,st+N,cmp3);
	for(int i=0;i<N;i++){
		printf("%06d %s %d\n",st[i].id,st[i].na,st[i].g);
	}
	return 0;
}
