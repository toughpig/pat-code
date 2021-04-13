#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=1000;
int n,row,col;
int matrix[maxn][maxn];

vector<int> num;
bool cmp(int a,int b){
	return a>b;
}

int x[4]={0,1,0,-1};
int y[4]={1,0,-1,0};

void step(int &forward,int &ro,int &co,int cnt){
	ro+=x[forward];
	co+=y[forward];
	if(ro>=row||ro<0||co>=col||co<0||matrix[ro][co]!=-1){
		ro-=x[forward];
		co-=y[forward];
		forward=(forward+1)%4;
		ro+=x[forward];
		co+=y[forward];
	}
	matrix[ro][co]=num[cnt];
}

int main(){
	scanf("%d",&n);
	int k;
	for(k=ceil(sqrt(n));k<=n;k++){
		if(n%k==0) break;
	}
	row=k;
	col=n/k;
	int temp;
	fill(matrix[0],matrix[0]+maxn*maxn,-1);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		num.push_back(temp);
	}
	sort(num.begin(),num.end(),cmp);
	int ro=0,co=0;
	int cnt=0;
	int forward=0;
	matrix[0][0]=num[0];
	while(cnt<n-1){
		cnt++;
		step(forward,ro,co,cnt);
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(j==0) printf("%d",matrix[i][j]);
			else printf(" %d",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
