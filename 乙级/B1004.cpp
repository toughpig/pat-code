//输入时直接判断最高与最低，因为成绩distinct
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

struct node{
	string name,id;
	int score;
	node(string a,string b,int c):name(a),id(b),score(c){}
};

int main(){
	int mark,n;
	char na[11],idd[11];
	node head=node("none","node",-1);
	node tail=node("node","none",101);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s%s%d",na,idd,&mark);
		if(head.score<mark) head=node(na,idd,mark);
		if(tail.score>mark) tail=node(na,idd,mark);
	}
	printf("%s %s\n%s %s",head.name.c_str(),head.id.c_str(),tail.name.c_str(),tail.id.c_str());
	return 0;
} 
