#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int myAtoi(string s) {
        int len = s.length();
        if(len==0) return 0;
        int ll = 0;
        while(ll<len&&s[ll]==' ') ll++;
        int flag = 1;
        if(ll==len) return 0;
        if(s[ll]=='-'){
            flag = -1;
            ll++;
        }
        else if(s[ll]=='+'){
            ll++;
        }
        else{
            if(s[ll]<'0'||s[ll]>'9')
                return 0;
        }
        while(ll<len&&s[ll]=='0') ll++;
        if(ll==len) return 0;
        int ans = 0;
        while(ll<len&&(s[ll]>='0'&&s[ll]<='9')){
            ans = ans*10 + s[ll]-'0';
            ll++;
            if(flag==1&&ans>=(1<<31-1)) return 1<<31-1;
            if(flag==-1&&ans<0) return 1<<31;
        }
        return flag*ans;
    }

int main(){
    cout<<myAtoi("  -42")<<endl;
}