//直接搬来一年前的代码 
#include<iostream>
using namespace std;
int main(){
  	int n,m;
  	cin>>n>>m;
  	int num[n];
  	for(int k=0;k<n;k++)
   		cin>>num[k];
 	 int j=m%n;
  	if(j!=0){
   		for(int i=n-j;i<n-1;i++)
     		cout<<num[i]<<" ";
    	cout<<num[n-1];
	for(int i=0;i<n-j;i++)
    	cout<<" "<<num[i];
	}
  	else{
		for(int i=0;i<n-1;i++)
      		cout<<num[i]<<" ";
    	cout<<num[n-1];
  	}
  	return 0;  
}
