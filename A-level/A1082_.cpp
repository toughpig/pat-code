#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string shu[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string wei[5]={"Shi","Bai","Qian","Wan","Yi"};
bool flagling=false;
bool flagwei=true;

void print(char ch,int pos){
	if(ch=='0'&&pos%4==1&&pos>4){
		if(flagwei==false){
		printf(" %s",wei[pos/4+2].c_str());
		flagling=false;
	}
		else{
			flagling=true;
		}
	}
	else if(ch=='0'&&pos%4!=1){
		flagling=true;
	}
	else if(ch!='0'&&pos%4==1&&pos>4){
		if(flagling==true) printf(" ling");
		printf(" %s",shu[ch-'0'].c_str());
		printf(" %s",wei[pos/4+2].c_str());
		flagling=false;
		flagwei=true;
	}
	else if(ch!='0'&&pos%4!=1){
		if(flagling==true) printf(" ling");
		printf(" %s",shu[ch-'0'].c_str());
		int k=pos%4;
		if(k==0)
			k=4;
		printf(" %s",wei[k-2].c_str());
		flagling=false;
		flagwei=false;
	}
	else if(ch!='0'&&pos%4==1&&pos<=4){
		if(flagling==true) printf(" ling");
		printf(" %s",shu[ch-'0'].c_str());
		flagling=false;
		flagwei=false;
	}
}

int main(){
	string str;
	cin>>str;
	int p;
	sscanf(str.c_str(),"%d",&p);
	if(p==0){
		printf("ling");
		return 0;
	}
	int i=0;
	int len=str.length();
	if(str[0]=='-'){
		printf("Fu");
		i++;
		while(str[i]==0) i++;
	}
//	else{
//		int pos=len-i;
//		char ch=str[i];
//	if(ch!='0'&&pos%4==1&&pos>4){
//		if(flagling==true) printf(" ling");
//		printf("%s",shu[ch-'0'].c_str());
//		printf(" %s",wei[pos/4+2].c_str());
//		flagling=false;
//		flagwei=true;
//	}
//	else if(ch!='0'&&pos%4!=1){
//		if(flagling==true) printf(" ling");
//		printf("%s",shu[ch-'0'].c_str());
//		int k=pos%4;
//		if(k==0)
//			k=4;
//		printf(" %s",wei[k-2].c_str());
//		flagling=false;
//		flagwei=false;
//	}
//	else if(ch!='0'&&pos%4==1&&pos<=4){
//		if(flagling==true) printf(" ling");
//		printf("%s",shu[ch-'0'].c_str());
//		flagling=false;
//		flagwei=false;
//	}
//	i++;
//	}
	else{
		while(str[i]==0) i++;
	int q=len-i;
	printf("%s",shu[str[i]-'0'].c_str());
	int k;
	if(q==4||q==8)
		k=4;
	else
		k=q%4;
	if(k==1&&q>4) printf(" %s",wei[q/4+2].c_str());
	else if(k!=1)
		printf(" %s",wei[k-2].c_str());
	i++;
	}
	for(;i<str.size();i++){
		print(str[i],len-i);
	}
	return 0;
}
