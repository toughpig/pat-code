#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ve;
int N,M,temp;
vector<int> ans;
bool flag=true;
int k=0;
int kk=-1;


void print(){
	for(int i=0;i<ans.size();i++){
		printf("%d",ans[i]);
		if(i<ans.size()-1)
			printf(" ");
	}
}

void pay(int index,int m){
	if(flag==false) return;
//	for(int i=index;i<ve.size();i++){
//		if(ve[i]==m){
//			ans.push_back(ve[i]);
//			k+=ve[i];
//			if(ans.size()==1){
//				kk=m;
//				ans.clear();
//				k=0;
//				break;
//			}
//			else{
//				flag=false;
//				print();
//				return;
//			}
//		}
//	}
	for(int i=index;i<ve.size();i++){
		k+=ve[i];
		if(k>m){
			k-=ve[i];
			return;
		}
		ans.push_back(ve[i]);
		if(k==m){
			print();
			flag=false;
			return;
		}
		else{
			pay(i+1,m-k);
		k-=ve[i];
		ans.pop_back();
		}
	}

}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d",&temp);
		ve.push_back(temp);
	}
	sort(ve.begin(),ve.end());
	pay(0,M);
	if(flag&&kk==-1)
		printf("No Solution");
	else if(flag==true&&kk!=-1)
		printf("%d",M);
	
	return 0;
}

