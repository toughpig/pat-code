#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

typedef long long ll;
long long a,aa,b,bb;

ll gdb(ll a,ll b){
	if(b==0) return a;
	else return gdb(b,a%b);
}

void stand(long long &c,long long &cc){
	if(cc<0){
		cc*=-1;
		c*=-1;
	}
	else if(c==0||cc==0){
		return;
	}
	ll p=gdb(fabs(c),cc);
	c/=p;
	cc/=p;
}

void print(pair<int,int> a){
	if(a.second==0){
		 printf("Inf");
		 return;
	}
	else if(a.first==0) {
		printf("0");
		return;
	}
	else{
		if(a.first<0){
			printf("(-");
			print(make_pair(a.first*-1,a.second));
			printf(")");
		}
		else{
			if(a.second==1){
				printf("%d",a.first);
			}
			else{
				if(a.first>=a.second){
					printf("%d %d/%d",a.first/a.second,a.first%a.second,a.second);
				}
				else{
					printf("%d/%d",a.first,a.second);
				}
			}
		}
	}
}

int main(){
	scanf("%lld/%lld %lld/%lld",&a,&aa,&b,&bb);
	stand(a,aa);
	stand(b,bb);
	ll q=aa*bb/gdb(aa,bb);
	ll p=gdb(aa,bb);
	ll c,cc;
////////////////////////////////////
	print(make_pair(a,aa));
	printf(" + ");
	print(make_pair(b,bb));
	printf(" = ");
	c=q/aa;
	c=c*a;
	int temp=q/bb*b;
	c+=temp;
	cc=q;
	stand(c,cc);
	print(make_pair(c,cc));
	printf("\n");
///////////////////////////////
	print(make_pair(a,aa));
	printf(" - ");
	print(make_pair(b,bb));
	printf(" = ");
	c=q/aa*a-q/bb*b;
	cc=q;
	stand(c,cc);
	print(make_pair(c,cc));
	printf("\n");
//////////////////////////////
	print(make_pair(a,aa));
	printf(" * ");
	print(make_pair(b,bb));
	printf(" = ");
	c=a*b;
	cc=aa*bb;
	stand(c,cc);
	print(make_pair(c,cc));
	printf("\n");
/////////////////////////////////	
	print(make_pair(a,aa));
	printf(" / ");
	print(make_pair(b,bb));
	printf(" = ");
	c=a*bb;
	cc=b*aa;
	stand(c,cc);
	print(make_pair(c,cc));
	printf("\n");
	return 0;
}
