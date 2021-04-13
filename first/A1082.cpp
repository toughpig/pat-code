#include<cstdio>
#include<string>
using namespace std;
string wei[5]={"fu","Shi","Bai","Qian","Wan","Yi"};
string shu[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int n,n1,n2,n3;
vector<string> temp;
int main(){
	scanf("%d",&n);
	string fuhao;
	fuhao.clear();
	if(n<0){
		fuhao=wei[0];
		n*=-1;
	}
	n3=n/100000000;
	n%=1<<8;
	n2=n/10000;
	n%=1<<4;
	n1=n;
	printf("%s",fuhao.c_str());
	temp.clear();
	print(n3,3);
	if(temp.empty()){
		print(n2,2);
	}
	else if(n2<1000){
		temp.clear()
		printf(" %s",shu[0].c_str());
		print(n2,2);
	}
	else{
		temp.clear();
		print(n2,2);
	}
	return 0;
}
