#include<iostream>
#include<string>
using namespace std;
string a[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main(){
    void print(int i);
	char c[101];
	int i=0;
	int total=0;
    while(cin>>c[i++]){
    	if(c[i-1]=='\n')
     		break;
		total+=c[i-1]-48;
	}
	print(total);
	return 0;
}
void print(int i){
	if(i/10!=0){
    	print(i/10);
    	cout<<" ";
	}
	cout<<a[i%10];
}
  
