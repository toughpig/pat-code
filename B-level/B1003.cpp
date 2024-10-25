//更简洁的写法，参考柳神
// #include <iostream>
// #include <map>
// using namespace std;
// int main() {
//     int n, p = 0, t = 0;
//     string s;
//     cin >> n;
//     for(int i = 0; i < n; i++) {
//         cin >> s;
//         map<char, int> m;
//         for(int j = 0; j < s.size(); j++) {
//             m[s[j]]++;
//             if (s[j] == 'P') p = j;
//             if (s[j] == 'T') t = j;
//         }
//         if(m['P'] == 1 && m['A'] != 0 && m['T'] == 1 && m.size() == 3 && p * (t-p-1) == s.length()-t-1)
//             printf("YES\n");
//         else
//             printf("NO\n");
//     }
//     return 0;
// }


//判断(A*n)+P+(A*k)+T+(A*(k*n))
#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

string str;
int n;

void judge(string s){
	int cntp=0,cntt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='P'&&s[i]!='A'&&s[i]!='T'){
			printf("NO\n");
			return;
		}
		if(s[i]=='P') cntp++;
		if(s[i]=='T') cntt++;
	}
	if(cntt!=1||cntp!=1){
		printf("NO\n");
		return;
	}
	int aa=0,pa=0,ta=0;
	int i;
	for(i=0;i<s.size();i++){
		if(s[i]=='A') aa++;
		else break;
	}
	if(i>=s.size()||s[i++]!='P'){
		printf("NO\n");
		return;
	}
	for(;i<s.size();i++){
		if(s[i]=='A') pa++;
		else break;
	}
	if(i>=s.size()||s[i++]!='T'){
		printf("NO\n");
		return;
	}
	for(;i<s.size();i++){
		if(s[i]=='A') ta++;
	}
	if(pa==0||aa*pa!=ta){
		printf("NO\n");
		return;
	}
	printf("YES\n");
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		str.clear();
		cin>>str;
		judge(str);
	}
	return 0;
} 
