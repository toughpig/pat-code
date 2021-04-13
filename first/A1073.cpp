#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
string str;
int sub;
int main(){
	int sig=0;
	getline(cin,str);
	bool flag=false;
	if(str[0]=='-'){
		flag=true;
	}
	str.erase(str.begin());
	int cnt=0;
	for(int i=0;i<str.size();i++){
		if(str[i]<='9'&&str[i]>='0'||str[i]=='.'){
			cnt++;
		}
		else
		break;
	}
	string valu=str.substr(0,cnt);
	int h=0;
	for(h=0;h<str.size();h++){
		if(str[h]=='E'){
			h++;
			break;
		}
	}
	str.erase(0,h);
	sscanf(str.c_str(),"%d",&sub);
	if(sub>=0){
		int k=0;
		for(k;k<valu.size();k++){
			if(valu[k]=='.')
				break;
		}
		for(int j=0;j<sub;j++){
			if(k+j==valu.size()-1)
				valu[k+j]='0';
			else if(k+j==valu.size())
				valu+="0";
			else{
				valu[k+j]=valu[k+j+1];
				valu[k+j+1]='.';
			}
		}
		if(flag)
			printf("-");
		for(int i=0;i<valu.size();i++){
			printf("%c",valu[i]);
		}
	}
	else{
		if(flag)
			printf("-");
		valu[1]=valu[0];
		printf("0.");
		for(int i=0;i<(-1)*sub-1;i++){
			printf("0");
		}
		
		for(int i=1;i<valu.size();i++)
			printf("%c",valu[i]);
	}
	return 0;
}
