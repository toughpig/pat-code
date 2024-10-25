#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,L,H;
struct node{
	int id,v,t;
	node(int _id,int _v,int _t):id(_id),v(_v),t(_t){};
};
int id,v,t;
int cnt=0;
vector<node> sage,noble,fool,small;
bool cmp(node a,node b){
	if(a.v+a.t!=b.v+b.t)
		return a.v+a.t>b.v+b.t;
	else if(a.v!=b.v)
		return a.v>b.v;
	else
		return a.id<b.id;
}

int main(){
	scanf("%d%d%d",&N,&L,&H);
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&id,&v,&t);
		node temp=node(id,v,t);
		if(v<L||t<L)
			continue;
		else if(v>=H&&t>=H)
			sage.push_back(temp);
		else if(t<H&&v>=H)
			noble.push_back(temp);
		else if(t<H&&v<H&&v>=t)
			fool.push_back(temp);
		else
			small.push_back(temp);
		cnt++;
	}
	sort(sage.begin(),sage.end(),cmp);
	sort(noble.begin(),noble.end(),cmp);
	sort(fool.begin(),fool.end(),cmp);
	sort(small.begin(),small.end(),cmp);
	printf("%d\n",cnt);
	for(int i=0;i<sage.size();i++){
		printf("%08d %d %d\n",sage[i].id,sage[i].v,sage[i].t);
	}
	for(int i=0;i<noble.size();i++){
		printf("%08d %d %d\n",noble[i].id,noble[i].v,noble[i].t);
	}
	for(int i=0;i<fool.size();i++){
		printf("%08d %d %d\n",fool[i].id,fool[i].v,fool[i].t);
	}
	for(int i=0;i<small.size();i++){
		printf("%08d %d %d\n",small[i].id,small[i].v,small[i].t);
	}
	return 0;
}
