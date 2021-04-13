#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=200;
int arc[maxn][maxn];
bool vis[maxn];
int cnt[maxn];

int n,m,c1,c2,d,k,p;
int len;
int id,minn;
int num=0;

string str[3]={"TS simple cycle","TS cycle","Not a TS cycle"};

bool judge1(int s){
	for(int i=1;i<=s;i++){
		if(cnt[i]!=1) return false;
	}
	return true;
}

bool judge2(int s){
	bool a=false;
	bool v=true;
	for(int i=1;i<=s;i++){
		if(cnt[i]>1) a=true;
		if(cnt[i]<1) v=false;
	}
	return a&&v;
}

int main(){
	scanf("%d%d",&n,&m);
	fill(arc[0],arc[0]+maxn*maxn,-1);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&c1,&c2,&d);
		arc[c1][c2]=arc[c2][c1]=d;
	}
	id=-1;
	minn=1<<30;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		bool flag=false;
		bool cy=false;
		int index;
		len=0;
		int head;
		fill(vis,vis+maxn,false);
		fill(cnt,cnt+maxn,0);
		scanf("%d%d",&p,&c1);
		head=c1;
		vis[c1]=true;
		cnt[c1]++;
		for(int j=1;j<p-1;j++){
			scanf("%d",&c2);
			if(arc[c1][c2]==-1){
				flag=true;
			}
			else{
				len+=arc[c1][c2];
				cnt[c2]++;
			}
			c1=c2;
		}
		scanf("%d",&c2);
		
		if(c2==head){
			cy=true;
			len+=arc[c1][c2];
		}
		else{
			if(arc[c1][c2]==-1){
				flag=true;
			}
			else{
				cnt[c2]++;
				len+=arc[c1][c2];
			}
		}
		bool simp=judge1(n);
		bool tt=judge2(n);
		
		if(flag){
			index=2;
		}
		else{
			if(cy&&simp) index=0;
			else if(cy&&tt) index=1;
			else index=2;
		}
		
		if(index!=2){
			if(minn>len){
				minn=len;
				id=i+1;
				num=p;
			}
			else if(minn==len){
				if(index==0){
					id=i+1;
					minn=len;
					num=p;
				}
				else if(num>p){
					id=i+1;
					num=p;
				}
			}
		}
		
		if(flag)
		printf("Path %d: NA (%s)\n",i+1,str[index].c_str());
		else
		printf("Path %d: %d (%s)\n",i+1,len,str[index].c_str());
		
	}
	printf("Shortest Dist(%d) = %d",id,minn);
	return 0;
}
