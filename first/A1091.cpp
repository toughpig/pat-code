#include<cstdio>
#include<queue>
using namespace std;
struct node{
	int x,y,z;
}block;
int M,N,L,T;
int c[1286][128][60];
bool inq[1286][128][60]={false};

queue<node> q;

int x[6]={1,-1,0,0,0,0};
int y[6]={0,0,1,-1,0,0};
int z[6]={0,0,0,0,1,-1};

bool judge(int i,int j,int k){
	if(i<0||i>=M||j<0||j>=N||k<0||k>=L)
	return false;
	if(c[i][j][k]==0||inq[i][j][k]==true)
	return false;
	return true;
}
int bfs(int i,int j,int k){
	block.x=i;
	block.y=j;
	block.z=k;
	int cnt=1;
	q.push(block);
	inq[i][j][k]=true;
	while(!q.empty()){
	node temp;
	block=q.front();
	q.pop();
	for(int u=0;u<6;u++){
		temp.x=block.x+x[u];
		temp.y=block.y+y[u];
		temp.z=block.z+z[u];
		if(judge(temp.x,temp.y,temp.z)){
			cnt++;
			q.push(temp);
			inq[temp.x][temp.y][temp.z]=true;
			}
		}
	}
	if(cnt>=T)
	return cnt;
	else
	return 0;
}
int main(){
	int ans=0;
	scanf("%d%d%d%d",&M,&N,&L,&T);
	for(int i=0;i<L;i++){
		for(int j=0;j<M;j++){
			for(int p=0;p<N;p++){
				scanf("%d",&c[j][p][i]);
			}
		}
	}
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			for(int p=0;p<L;p++){
				if(judge(i,j,p)){
					ans+=bfs(i,j,p);
				}
			}
		}
	}	
	printf("%d",ans);
	
	
	return 0;
}
 
