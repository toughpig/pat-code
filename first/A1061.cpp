#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
string week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
	string str1,str2,str3,str4;
	cin>>str1>>str2>>str3>>str4;
	char ch;
	int ch1;
	int pos;
	int ii,jj;
//	bool flag=false;
	for(ii=0;ii<str1.size()&&ii<str2.size();ii++){
		if(str1[ii]>'G'||str1[ii]<'A')
			continue;
//		for(jj=0;jj<str2.size();jj++){
//			if(str2[jj]==str1[ii]){
//				ch=str1[ii];
//				ii++;
//				jj++;
//				flag=true;
//				break;
//			}
//		}
//		if(flag==true)
//			break;
		else if(str1[ii]==str2[ii]){
			ch=str1[ii];
			ii++;
			break;
		}
		
	}
//	flag=false;
	for(ii+=0;ii<str1.size()&&ii<str2.size();ii++){
		if(str1[ii]==str2[ii]&&str1[ii]>='A'&&str1[ii]<='N'){
			ch1=str1[ii]-'A'+10;
			break;
		}
		else if(str1[ii]==str2[ii]&&str1[ii]>='0'&&str1[ii]<='9'){
			ch1=str1[ii]-'0';
			break;
		}
	}
//	flag=false;
	for(int i=0;i<str3.size()&&i<str4.size();i++){
		if(str3[i]==str4[i]&&(str3[i]>='a'&&str3[i]<='z'||(str3[i]>='A'&&str3[i]<='Z'))){
			pos=i;
			break;
		}
	}
//	printf("%c%c%d\n",ch,ch1,pos);
	printf("%s %02d:%02d",week[ch-'A'].c_str(),ch1,pos);
	return 0;
}
