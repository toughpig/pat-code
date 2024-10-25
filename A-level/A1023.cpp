#include<cstdio>
#include<cstring>
struct bign{
  int num[21];
  int len;
  bign(){
    memset(num,0,21);
    len=0;
  }
};
bign change(char c[]){
  int l=strlen(c);
  bign temp;
  for(int i=0;i<l;i++){
    temp.num[i]=c[l-i-1]-'0';
  }
  temp.len=l;
  return temp;
}
bign doub(bign k){
  int le=k.len;
  int j,o=0;
  int cnt=0;
  bign temp;
  while(le--){
    int sum;
    sum=k.num[cnt]*2+o;
    j=sum%10;
    o=sum/10;
    temp.len++;
    temp.num[cnt++]=j;
  }
  if(o!=0){
    temp.len++;
    temp.num[cnt++]=o;
  }
  return temp;
}
void print(bign u){
  for(int i=u.len-1;i>=0;i--){
    printf("%d",u.num[i]);
  }
}
int main(){
  char ch[21];
  scanf("%s",ch);
  bign a=change(ch);
  bign aa=doub(a);
  if(aa.len!=a.len)
    printf("No\n");
  else{
    int flag[10]={0};
    for(int i=a.len-1;i>=0;i--)
      flag[a.num[i]]++;
    for(int i=aa.len-1;i>=0;i--)
      flag[aa.num[i]]--;
    int k;
    for(k=0;k<10;k++)
      if(flag[k]!=0){
        printf("No\n");
        break;
      }
    if(k==10)
      printf("Yes\n");
    
  }
  print(aa);
  return 0;
  
}

