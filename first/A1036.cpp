#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
//struct stu{
//	string name;
//	char gender;
//	string id;
//	int grade;
//	stu(string na,char ch,string idd,int g):name(na),gender(ch),id(idd),grade(g){};
//}*fe;
//stu *ma;
//vector<stu> temp;
char fena[15],feid[15],mana[15],maid[15];

int main(){
	int N;
	scanf("%d",&N);
	int maxn=-1;
	int minn=101;
	for(int i=0;i<N;i++){
		char na[15];
		char idd[15];
		char ch;
		int g;
		scanf("%s %c %s %d",na,&ch,idd,&g);
//		temp.push_back(stu(na,ch,idd,g));
		if(ch=='F'&&maxn<g){
//			fe->gender='F';
			strcpy(fena,na);
			strcpy(feid,idd);
			maxn=g;
		}
		if(ch=='M'&&minn>g){
			strcpy(maid,idd);
			strcpy(mana,na);
			minn=g;
	}
}
	if(minn!=101&&maxn!=-1){
		printf("%s %s\n%s %s\n%d",fena,feid,mana,maid,maxn-minn);
	}
	else{
		if(maxn==-1)
		printf("Absent\n");
		else
		printf("%s %s\n",fena,feid);
		if(minn==101)
		printf("Absent\n");
		else
		printf("%s %s\n",mana,maid);
		printf("NA");
	}
	return 0;
}
