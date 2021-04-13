//ʮλ�������36���ƣ�ת��Ϊʮ����48631067547955363834-1������Maxn����long long��Χ�ڣ�
//�������Ҷ�Ӧ����ƥ��ʱ�����������Maxn��ƥ��111�Ľ���ʱ��radix��2~Maxn+1��Χ�ڶ��ֲ��ң�
//tempsum��һ�ϴ���Ϊradixʱ�����������ʵ����ƥ����λ��ʱ����������pow(Maxn,2)ʱ�Ѿ�����
//long long�����ķ�Χ��Ϊ����long long���������Ҫ�ж�radix�ϴ󣬸���midֵ
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
		if(sum<0) return -1;    //��������long long������Χ������Ŀ���������ֵ��radix���ù��� 
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
	}                           //aa���36^11-1,��long long������Χ�� 
	ll high=aa+1,low;
	char h='0';
	for(int i=0;i<temp.size();i++){
		if(temp[i]>h) h=temp[i];
	}
	low=todigi(h)+1;
	ll mid;
	ll tempsum;
	if(temp.size()==1){       //��һλ����ƥ��ʱradix��Ψһ���뵥������ 
		if(todigi(temp[0])!=aa) printf("Impossible");
		else printf("%lld",todigi(temp[0])+1);
		return 0;
	}
	while(high>=low){
		mid=(high+low)/2;
		tempsum=todeci(temp,mid);
		if(tempsum==aa) break;
		else if(tempsum==-1||tempsum>aa){ //����ؼ����ж�radix���󣬰������ 
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
