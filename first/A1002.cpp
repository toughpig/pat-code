#include<cstdio>
#include<vector>
#include<stdlib.h>
using namespace std;

struct node{
	int e;
	double a;
};

vector<struct node> po[3];

int main(){
	int A,B;
	int E;
	double C;
	node* nn=(node*)malloc(sizeof(node));
	scanf("%d",&A);
	for(int i=0;i<A;i++){
		scanf("%d %lf",&nn->e,&nn->a);
		po[0].push_back(*nn);
	}
	scanf("%d",&B);
	for(int i=0;i<B;i++){
//		node *nn=(node*)malloc(sizeof(node));
		scanf("%d %lf",&nn->e,&nn->a);
		po[1].push_back(*nn);
	}
	vector<node>::iterator it0=po[0].begin();
	vector<node>::iterator it1=po[1].begin();
	node *newn=(node*)malloc(sizeof(node));
	while(it0!=po[0].end()&&it1!=po[1].end()){
		if((*it0).e==(*it1).e){
			newn->e=(*it0).e;
			newn->a=(*it0).a+(*it1).a;
			if(newn->a!=0)
			po[2].push_back(*newn);
			it0++;
			it1++;
		}
		else{
			(*it0).e>(*it1).e?po[2].push_back(*(it0++)):po[2].push_back(*(it1++));
		}
	}
	while(it0!=po[0].end())
		po[2].push_back(*(it0++));
	while(it1!=po[1].end())
		po[2].push_back(*(it1++));
	printf("%d",po[2].size());
	for(int j=0;j<=po[2].size()-1;j++){
		printf(" %d %.1lf",po[2][j].e,po[2][j].a);
	}
	return 0;
}
