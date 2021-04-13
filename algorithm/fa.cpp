#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int getFather(vector<int>& num, int index)
{
    int len = num.size();
    if(len<=index) return -1;
    if(num[index]==index) return index;
    else
    {
        int fa = num[index];
        while(fa!=index)
        {
            num[index] = getFather(num,fa);
            index = fa;
            fa = num[index];
        }
        return fa;
    }
}

void unite(vector<int>& num, int a, int b)
{
    int len = num.size();
    if(a>=len || b>=len) return;
    int fa = getFather(num,a);
    int fb = getFather(num,b);
    if(fa!=fb)
    {
        num[fb] = fa;
    }
}


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main()
{
    vector<int> fa;

    struct ListNode* root = new ListNode(1,nullptr);
    ListNode* tmp = root;
    tmp->val = 8;
    root = root->next;
    root = new ListNode(3,nullptr);
    cout<<root->next->val;

    return 0;
}