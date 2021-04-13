#include<string>
#include<cstdio>
#include<map>
using namespace std;

string low[13]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep","oct","nov","dec"};
string high[12]={"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main(){
  int N;
  map<string, int> m1,m2;
  for(int i=0;i<13;i++){
    m1[low[i]]=i;
    if(i<12)
    m2[high[i]]=i+1;
  }
  scanf("%d",&N);
  while(N--){
    char ch[5];
    string ans1;
    string ans2;
    int sum=0;
    scanf("%s",ch);
    if(m2.find(ch)!=m2.end()){
      sum=m2[ch]*13;
      scanf("%s",ch);
      sum+=m1[ch];
      printf("%d\n",sum);
    }
    else if(m1.find(ch)!=m1.end()){
      sum=m1[ch];
      printf("%d\n",sum);
    }
    else{
      sscanf(ch,"%d",&sum);
      if(sum>=13){
        ans2=high[sum/13-1];
        ans1=low[sum%13];
        printf("%s",ans2.c_str());
        if(sum%13){
          printf(" %s\n",ans1.c_str());
        }
        else
        printf("\n");
      }
      else{
        ans1=low[sum];
        printf("%s\n",ans1.c_str());
      }
    }
    
    
  }
  return 0;
}
