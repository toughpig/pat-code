#include<cstdio>
#include<cstring>
const int maxn=1010;

static int r;
struct bign{
  int num[maxn];
  int len;
  bign(){
    memset(num,0,maxn);
    len=0;
  }
};
bign change(char c[]){
  bign temp;
  int l=strlen(c);
  for(int i=0;i<l;i++){
    temp.num[l-i-1]=c[i]-'0';
  }
  temp.len=l;
  return temp;
}
bign sub(bign a,int b){
  int Q,R=0;
  bign temp;
  int tcnt=0;
  int cnt=a.len;
  int t;
  while(cnt){
    t=R*10+a.num[cnt-1];
    Q=t/b;
    R=t%b;
    temp.len++;
    temp.num[tcnt++]=Q;
    cnt--;
  }
  r=R;
  return temp;
}
void print(bign b){
  int t=b.len;
  if(t==1)
  	printf("%d",b.num[0]);
  if(b.num[0]!=0)
    printf("%d",b.num[0]);
  for(int i=1;i<t;i++)
    printf("%d",b.num[i]);
}
int main(){
  char ch[maxn];
  int b;
  scanf("%s %d",ch,&b);
  bign a=change(ch);
  bign q;
  q=sub(a,b);
  print(q);
  printf(" %d",r);
  return 0;
}

