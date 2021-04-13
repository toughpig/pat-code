#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100010;
double R;
double P;
struct node{
	double data;
	vector<int> child;
}Node[maxn]; 
using namespace std;
double sum=0;
//double pow(int d){
//	double p=P;
//	while(d--){
//		p*=R;
//	}
//	return p;
//}
void dfs(int index,int depth){
	if(Node[index].child.size()==0){
		sum+=Node[index].data*P*pow(R,depth);
	}
	else{
		for(int k=0;k<Node[index].child.size();k++){
			dfs(Node[index].child[k],depth+1);
		}
	}
}

int main(){
	int N;
	int temp;
	scanf("%d %lf %lf",&N,&P,&R);
	R/=100;
	R+=1;
	int sub;
	for(int i=0;i<N;i++){
		scanf("%d",&sub);
		if(sub==0){
			scanf("%lf",&Node[i].data);
		}
		else{
//			scanf("%d",sub);
			for(int j=0;j<sub;j++){
				scanf("%d",&temp);
				Node[i].child.push_back(temp);
			}
		}
	}
	dfs(0,0);
	printf("%.1lf",sum);
	return 0;
}
