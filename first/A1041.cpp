#include<cstdio>
#include<vector>
#include<map>
using namespace std;
map<int,int> m;
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int temp;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if(m.find(temp)!=m.end()){
			int k=m.find(temp)->second;
			m.find(temp)->second*=k*(-1);
			m.find(temp)->second-=1;
		}
		else{
			m[temp]=i;
		}
	}
	int minn=100000;
	int ans=-1;
	for(map<int,int>::iterator i=m.begin();i!=m.end();i++){
		if(i->second>=0&&i->second<minn){
			minn=i->second;
			ans=i->first;
		} 
	}
	if(ans!=-1){
		printf("%d",ans);
	}
	else
	printf("None");
	return 0;
}
