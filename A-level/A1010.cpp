//十位数，最高36进制，转换为十进制48631067547955363834-1，记作Maxn，在long long范围内，
//但是在找对应进制匹配时可能溢出，如Maxn来匹配111的进制时，radix在2~Maxn+1范围内二分查找，
//tempsum以一较大数为radix时可能溢出，事实上在匹配三位数时，当计算至pow(Maxn,2)时已经超出
//long long正数的范围，为负的long long数，因此需要判断radix较大，更改mid值
#include<cstdio>
#include<string>
using namespace std;

typedef long long ll;

char a[11],b[11];
ll flag,radix;

ll todigi(char ch){
	if(ch>='0'&&ch<='9') return ch-'0';
	else return ch-'a'+10;
}

ll todeci(string str,ll radi){
	ll sum=0;
	int k;
	for(int i=0;i<str.size();i++){
		k=todigi(str[i]);
		sum=sum*radi+k;
		if(sum<0) return -1;    //此数超过long long正数范围，比题目给出的最大值大，radix设置过大。 
	}
	return sum;
}

int main(){
	scanf("%s%s%ld%ld",a,b,&flag,&radix);
	ll aa;
	string temp;
	if(flag==1){
		aa=todeci(a,radix);
		temp=b;
	}
	else{
		aa=todeci(b,radix);
		temp=a;
	}                           //aa最大36^11-1,在long long正数范围内 
	ll high=aa+1,low;
	char h='0';
	for(int i=0;i<temp.size();i++){
		if(temp[i]>h) h=temp[i];
	}
	low=todigi(h)+1;
	ll mid;
	ll tempsum;
	if(temp.size()==1){       //在一位数字匹配时radix不唯一，须单独考虑 
		if(todigi(temp[0])!=aa) printf("Impossible");
		else printf("%lld",todigi(temp[0])+1);
		return 0;
	}
	while(high>=low){
		mid=(high+low)/2;
		tempsum=todeci(temp,mid);
		if(tempsum==aa) break;
		else if(tempsum==-1||tempsum>aa){ //本题关键，判断radix过大，包括溢出 
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	if(low>high) printf("Impossible");
	else printf("%lld",mid);
	return 0;
} 
