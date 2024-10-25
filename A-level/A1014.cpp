#include<cstdio>
#include<queue>
#include<map>
using namespace std;
const int maxn=1010;
queue<pair<int,int> > q[22];
int list[maxn];
int ask[maxn];
int N,M,K,Q;
int ans[maxn];
int last[maxn];

int main(){
	scanf("%d%d%d%d",&N,&M,&K,&Q);
	for(int i=1;i<=K;i++)
		scanf("%d",list+i);
	for(int i=1;i<=Q;i++)
		scanf("%d",ask+i);	
	int num=1;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(num<=K){
			q[j].push(make_pair(num,list[num]));
			num++;
		}
		}
	}
	bool flag=false;
	int tim=0;
	for(int i=1;i<=N;i++){
		if(i<=K)
		last[i]=0;
	}
//	int last=0;
	while(flag==false){
		flag=true;
		int minn=0x3fffffff;
		for(int i=0;i<N;i++){
			if(!q[i].empty()){
				flag=false;
				if(minn>q[i].front().second){
					minn=q[i].front().second;
				}
			}
		}
		if(flag==false){
			tim+=minn;
			for(int i=0;i<N;i++){
				if(!q[i].empty()){
					q[i].front().second-=minn;
					if(q[i].front().second==0){
//						printf("%d\n",q[i].front().first);
						ans[q[i].front().first]=tim;
						q[i].pop();
						if(num<=K){
							q[i].push(make_pair(num,list[num]));
							num++;
						}
						if(!q[i].empty()){
							last[q[i].front().first]=tim;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=Q;i++){
		int k=last[ask[i]];
		if(k>=540)
			printf("Sorry\n");
		else{
			k+=list[ask[i]];
			int h=k/60;
			int m=k%60;
			printf("%02d:%02d\n",8+h,m);
		}
	}
	return 0;
} 
