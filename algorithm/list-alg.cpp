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

// ******指针的错误用法*******
    void wrong_ptr_use(){
        node* root = new ListNode(1,nullptr);
        node* tmp = root;
        tmp->val = 8;
        root = root->next;
        root = new ListNode(3,nullptr);//仅仅改变root的指向
        cout<<root->next->val;
    }

// 24. 两两交换链表中的节点
// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;   //短路
        ListNode *ll = head, *rr = head->next;
        ListNode *tmp = rr->next;
        rr->next = ll;
        ll->next = swapPairs(tmp);
        return rr;
    }

// 2. 两数相加
// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
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

// 19. 删除链表的倒数第 N 个结点
// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
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