#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;


struct node{
	int id;
	int cnt;
	node(int _id,int _cnt):id(_id),cnt(_cnt){};
	bool operator <(const node &a) const {
		if(cnt!=a.cnt) return cnt>a.cnt;
		else return id<a.id;
	}
};
set<node> Node;
int book[50001]={0};
bool vis[50001]={false};
int n,k,temp;


int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if(!Node.empty()) printf("%d:",temp);
		int cnt=0;
		for(set<node>::iterator i=Node.begin();i!=Node.end();i++){
			printf(" %d",(*i).id);
			cnt++;
			if(cnt==k) break;
		}
		if(cnt!=0) printf("\n");
		if(vis[temp]==false){
			Node.insert(node(temp,1));
			book[temp]=1;;
			vis[temp]=true;
		}
		else{
			auto it=Node.find(node{temp,book[temp]});
			Node.erase(it);
			Node.insert(node(temp,book[temp]+1));
			book[temp]++;
		}
	}
	return 0;
}
