#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

//bool cmp(int a,int b){
//	return a>b;
//}
map<int,int> Map;

int main(){
	int N,M;
	scanf("%d %d",&M,&N);
	while(N--){
		int temp;
		for(int i=0;i<M;i++){
			scanf("%d",&temp);
//			if(Map.find(temp)!=Map.end())
//				Map[temp]=Map[temp]+1;
//			else
				Map[temp]++;
		}
	}
//	sort(Map.begin(),Map.end(),cmp);
	map<int ,int>::iterator it=Map.begin();
	int maxn=it->first;
	while(it!=Map.end()){
		if(Map[maxn]<it->second)
			maxn=it->first;
		it++;
	}
	printf("%d",maxn);
	return 0;
} 
