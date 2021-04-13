#include<iostream>
#include<string>
using namespace std;


typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}node;

class Solution {
public:

// ******ָ��Ĵ����÷�*******
    void wrong_ptr_use(){
        node* root = new ListNode(1,nullptr);
        node* tmp = root;
        tmp->val = 8;
        root = root->next;
        root = new ListNode(3,nullptr);//�����ı�root��ָ��
        cout<<root->next->val;
    }

// 24. �������������еĽڵ�
// ����һ���������������������ڵĽڵ㣬�����ؽ���������� �㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;   //��·
        ListNode *ll = head, *rr = head->next;
        ListNode *tmp = rr->next;
        rr->next = ll;
        ll->next = swapPairs(tmp);
        return rr;
    }

// 2. �������
// �������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum;
        ListNode *ll = l1, *rr = l2;
        while(!ll || !rr){
            sum = ll->val + rr->val + carry;
            carry = sum/10;
            sum %= 10;
            ll->val = sum;
            ll = ll->next;
            rr = rr->next;
        }
        if(!ll) ll = rr;
        while(ll&&carry){
            sum = ll->val + carry;
            carry = sum/10;
            sum %= 10;
            ll->val = sum;
            ll = ll->next;
        }
        if(carry){
            ll = new ListNode(carry,nullptr);
        }
        return l1;
    }

// 19. ɾ������ĵ����� N �����
// ����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ll=head, *rr = head;
        while(n--&&rr){
            rr = rr->next;
        }
        if(!rr) return ll->next;
        while(rr->next){
            ll = ll->next;
            rr = rr->next;
        }
        if(!ll->next) return nullptr;
        ll->next = ll->next->next;
        return head;
    }
};

int main(){
    ListNode a(1,nullptr);
    ListNode b(2,&a);
    ListNode c(3,&b);

    ListNode d(1,nullptr);
    ListNode e(2,&d);
    ListNode f(3,&e);

    Solution ss;
    ListNode* ans = ss.addTwoNumbers(&c,&f);
    while(ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }

    string str = "asdfasdf";
    str.substr();

    return 0;

}