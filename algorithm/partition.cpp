#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:

// 17. �绰�������ĸ���
// ����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰� ����˳�� ���ء��������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        string num[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        fix(ans,"",0,digits,num);
        return ans;
    }

    void fix(vector<string>& ans, string tmp, int index, string dig, string* num){
        if(index==dig.size()){
            ans.push_back(tmp);
            return;
        }
        for(auto i:num[dig[index]-'2']){
            tmp += i;
            fix(ans,tmp,index+1,dig,num);
            tmp.pop_back();
        }
    }

// 22. ��������
// ���� n �����������ŵĶ������������һ�������������ܹ��������п��ܵĲ��� ��Ч�� ������ϡ�
// ���룺n = 3
// �����["((()))","(()())","(())()","()(())","()()()"]
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fix(ans,"(",1,0,n);
        return ans;
    }

    void fix(vector<string>& ans,string tmp,int ll,int rr,int n){
        if(ll==rr&&ll==n){
            ans.push_back(tmp);
            return;
        }
        else if(ll==rr){
            fix(ans,tmp+"(",ll+1,rr,n);
        }
        else{
            if(ll==n) fix(ans,tmp+")",ll,rr+1,n);
            else{
                fix(ans,tmp+"(",ll+1,rr,n);
                fix(ans,tmp+")",ll,rr+1,n);
            }
        }
    }
};