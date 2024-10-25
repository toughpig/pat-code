#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1010; 
vector<int> user[maxn];
queue<int> q;
int N,L;
int n,k;
int flag[maxn]={0};
bool inq[maxn];
int cnt=0;

int main(){
	scanf("%d%d",&N,&L);
	int num,fo;
	for(int i=1;i<=N;i++){
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			scanf("%d",&fo);
			user[fo].push_back(i);
		}
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		fill(flag,flag+maxn,0);
		fill(inq,inq+maxn,false);
		cnt=0;
		q.push(k);
		inq[k]=true;
		flag[k]=1;
		while(!q.empty()){
			int temp=q.front();
			q.pop();		
			cnt++;
			if(flag[temp]==L+1){
				continue;
			}
			for(int j=0;j<user[temp].size();j++){
				int sub=user[temp][j];
				if(inq[sub]==false){
					flag[sub]=flag[temp]+1;
					q.push(sub);
					inq[sub]=true;
				}
			}
		}
		printf("%d\n",cnt-1);
		
	}	
	return 0;
} 
