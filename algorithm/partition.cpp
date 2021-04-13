#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:

// 17. 电话号码的字母组合
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
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

// 22. 括号生成
// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
// 输入：n = 3
// 输出：["((()))","(()())","(())()","()(())","()()()"]
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