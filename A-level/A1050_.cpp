#include<cstdio>
#include<stack>
#include<iostream>
using namespace std;
void reset(bool cd[]){
	for(int i=1;i<=50;i++)
		cd[i]=false;
}
void print(bool a){
	if(a)
	printf("YES\n");
	else
	printf("NO\n");
}
bool cd[55]={false};
int main(){
	int M,N,K;
	stack<int> s;
	scanf("%d%d%d",&M,&N,&K);
	for(int i=0;i<K;i++){
		while(!s.empty())
			s.pop();
		reset(cd);
		bool flag=true;
		int num=-1;
		int f=1;
		for(int j=0;j<N;j++){
			scanf("%d",&num);
			if(!s.empty()){
				if(s.top()>num){
					flag=false;
					break;
				}
				else if(s.top()==num){
					s.pop();
					continue;
				}
		}
		if(!s.empty()&&num>s.top()||s.empty()){
			while(f<=num){
				if(cd[f]==false){
				s.push(f++);
				cd[f]=true;
					if(s.size()>M){
						flag=false;
						break;
					}
				}
			}
			if(flag){
				s.pop();
			}
		}
}
		print(flag);
	
}
	return 0;
}

