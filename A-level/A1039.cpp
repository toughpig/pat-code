#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=26*26*26*10;
vector<int> course[maxn];

int myhash(char ch[]){
	int id=0;
	for(int i=0;i<3;i++){
		id=id*26+ch[i]-'A';
	}
	id=id*10+ch[3]-'0';
	return id;
}

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	while(K--){
		int index, num;
		scanf("%d%d",&index,&num);
		while(num--){
			char ch[5];
			scanf("%s",ch);
			int s=myhash(ch);
			course[s].push_back(index);
		}
	}
	while(N--){
		char name[5];
		scanf("%s",name);
		printf("%s",name);
		int temp=myhash(name);
		printf(" %d",course[temp].size());
		sort(course[temp].begin(),course[temp].end());
		for(int i=0;i<course[temp].size();i++)
			printf(" %d",course[temp][i]);
		printf("\n");
		
		
	}
  
  return 0;
}

