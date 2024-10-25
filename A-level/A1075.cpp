#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	int id,rank,tot;
	vector<int> score;
	int perfet;
	bool flag;
};

vector<node> stu(100000);
vector<int> full(100000);

int n,k,m;
int idd,num,sco;

bool cmp(node a,node b){
	if(b.flag==false) return true;
	if(a.tot!=b.tot) return a.tot>b.tot;
	else{
		if(a.perfet!=b.perfet) return a.perfet>b.perfet;
		else{
			return a.id<b.id;
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&k,&m);
	full.resize(k+1);
	stu.resize(n+1);
	for(int i=1;i<=k;i++){
		scanf("%d",&idd);
		full[i]=idd;
	}
	for(int i=1;i<=n;i++){
		stu[i].id=i;
		stu[i].tot=0;
		stu[i].score.resize(k+1);
		fill(stu[i].score.begin(),stu[i].score.end(),-1);
		stu[i].perfet=0;
		stu[i].flag=false;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&idd,&num,&sco);
		int temp=stu[idd].score[num];
		if(sco!=-1) stu[idd].flag=true;
		if(temp<sco&&temp!=-1){
			stu[idd].tot+=sco-temp;
			stu[idd].score[num]=sco;
			if(sco==full[num])
				stu[idd].perfet++;
		}
		else if(temp==-1&&temp<sco){
			stu[idd].tot+=sco-temp-1;
			stu[idd].score[num]=sco;
			if(sco==full[num])
				stu[idd].perfet++;
		}
		else if(temp==-1&&sco==-1)
			stu[idd].score[num]=0;
	}
	sort(stu.begin()+1,stu.end(),cmp);
	stu[1].rank=1;
	int cnt=1;
	printf("%d %05d %d",stu[1].rank,stu[1].id,stu[1].tot);
	for(int j=1;j<=k;j++){
		if(stu[1].score[j]==-1) printf(" -");
		else printf(" %d",stu[1].score[j]);
	}
	printf("\n");
	for(int i=2;i<=n;i++){
		if(stu[i].flag==false) break;
		cnt++;
		if(stu[i].tot==stu[i-1].tot) stu[i].rank=stu[i-1].rank;
		else stu[i].rank=cnt;
		printf("%d %05d %d",stu[i].rank,stu[i].id,stu[i].tot);
		for(int j=1;j<=k;j++){
			if(stu[i].score[j]==-1) printf(" -");
			else printf(" %d",stu[i].score[j]);
		}
		printf("\n");
	}
	return 0;
}
