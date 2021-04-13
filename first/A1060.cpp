#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
static int cnt=0;

string bo(string &tem,char &s,int &n,int m){
	if(tem[0]=='-'){
		s=tem[0];
		tem.erase(tem.begin());
	}
  while(tem.length()!=0&&tem[0]=='0'){
    tem.erase(tem.begin());
  }
  if(tem.length()!=0){
  	int len=0;
  	if(tem[0]!='.'){  
  	while(len<tem.length()&&tem[len]!='.'){
  		n++;
  		len++;
	  }
	  if(len<tem.length()){
	  	tem.erase(tem.begin()+len);
	  }
  }
  else{
  	tem.erase(tem.begin());
  	int k=tem.length();
  	while(tem.length()!=0&&tem[0]=='0'){
  		n--;
  		tem.erase(tem.begin());
	  }
	  if(tem.length()==0)
	  n=0;
	  
  }
}
int fl=tem.length()-m;
if(fl>=0){
	for(int j=0;j<fl;j++){
		tem.erase(tem.end()-1);
	}
}
else{
	for(int i=0;i<fl*(-1);i++){
		tem+="0";
	}
}

//  if(tem[0]=='.'){
//  	tem.erase(tem.begin());
//  	while(tem.length()!=0&&tem[0]=='0'){
//    tem.erase(tem.begin());
//    e1--;
//    }
//  }
//  else{
//    for(int i=0;i<n;i++){
//	
//    if(i<=tem.length()&&tem[i]!='.')
//	 {
//	 temp[i]=tem[i];
//	 e1++;
//}
//else if(tem[i]=='.'){
//	i--;
//}
//else{
//	temp[i]='0';
//}
//}
//if(tem[i]=='.'){
//	
//}
//}
  return tem;
}
int main(){
  string str1,str2;
  int N;
//  int dot1,dot2;
  cin>>N>>str1>>str2;
  int e1=0;
  int e2=0;
  char s1='\0';
  char s2='\0';
//  int pos=str1.find(" ");
//  str2=str1.substr(pos+1,str1.length()-pos-1);
//  str1.erase(pos,str1.length()-pos);
//  dot1=str1.find(".");
//  dot2=str2.find(".");
//  if(dot1) str1.erase(dot1+str1.begin());
//  if(dot2) str2.erase(dot2+str2.begin());
  bo(str1,s1,e1,N);
  bo(str2,s2,e2,N);
//  dot2-=cnt;
//  int flag=1;
//  if(dot1!=dot2)
//    flag=0;
//  else{
//    
//    if(str1!=str2)
//     flag=0;
//  }
  if(str1==str2&&e1==e2&&s1==s2){
  	printf("YES ");
    if(s1!='\0')
    printf("%c",s1);
    printf("0.%s",str1.c_str());
    if(e1!=0)
    printf("*10^%d",e1);
  }
  else{
  	printf("NO ");
    if(s1!='\0')
    printf("%c",s1);
    printf("0.%s",str1.c_str());
    if(e1!=0)
    printf("*10^%d ",e1);
    else
    printf(" ");
    printf("No ");
    if(s2!='\0')
    printf("%c",s2);
    printf("0.%s",str2.c_str());
    if(e2!=0)
    printf("*10^%d",e2);
  }
  return 0;
}

