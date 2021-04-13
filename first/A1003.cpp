#include<cstdio>
//#include<set>
#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
//set<int> s;
const int maxn=510;
const int inf=0x3fffffff;
int arc[maxn][maxn];
int dist[maxn];
int a[maxn];
vector<int> path[maxn];
int N,R,S,E;
int data;
bool visited[maxn]={false};

int main(){
	int k,f,c;
	scanf("%d%d%d%d",&N,&R,&S,&E);
	for(int i=0;i<maxn;i++){
		dist[i]=inf;
		for(int j=0;j<maxn;j++){
			arc[i][j]=inf;
		}
	}
	for(int i=0;i<N;i++){
		scanf("%d",a+i);
	}
	for(int i=0;i<R;i++){
		scanf("%d %d %d",&k,&f,&c);
		arc[k][f]=c;
		arc[f][k]=c;                         //无向图必须初始化下三角 ！！！ 
	}
	for(int j=0;j<N;j++){
		dist[j]=arc[S][j];
		path[j].push_back(S);
	}
	dist[S]=0;
	visited[S]=true;
//	s.insert(S);
	while(visited[E]==false){
		int min=E;
		for(int j=0;j<N;j++){
			if(visited[j]==false&&dist[j]<=dist[min]){
//				visited[j]=true;
//				s.insert(j);
				min=j;
			}
		}
		if(min==E||dist[min]==inf)
			break;
		visited[min]=true;
//		s.insert(min);
		for(int k=0;k<N;k++){
			if(visited[k]==false&&arc[min][k]<inf&&dist[min]+arc[min][k]<dist[k]){
				dist[k]=dist[min]+arc[min][k];
				path[k].clear();
				path[k].push_back(min);
			}
			else if(visited[k]==false&&arc[min][k]<inf&&dist[min]+arc[min][k]==dist[k])
					path[k].push_back(min);
				
			
		}
	}
	int cnt=0;
	if(dist[E]<inf)
		cnt=1;
	int mid=E;
// 	int m;
	int maxnn[maxn]={0};
	maxnn[E]=a[E];
	q.push(mid);
	while(!q.empty()){

		mid=q.front();
		q.pop();
		while(mid==S&&!q.empty()){
		  mid=q.front();
		  q.pop();
		}
		if(mid==S)
		break;
		if(path[mid].size()>=2){
			cnt+=path[mid].size()-1;
		}
		for(int i=path[mid].size()-1;i>=0;i--){
			int temp=path[mid][i];
			q.push(temp);
			if(a[temp]+maxnn[mid]>maxnn[temp]){
				maxnn[temp]=a[temp]+maxnn[mid];
			}
		}
		}
	

	printf("%d %d",cnt,maxnn[S]);
	return 0;
}
