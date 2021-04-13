typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}tnode;

class Solution
{
public:

// 783. �����������ڵ���С����
// ����һ�������������ĸ��ڵ� root ������ ������������ͬ�ڵ�ֵ֮�����С��ֵ ��
    int minDiffInBST(TreeNode *root)
    {
        int ans = 0, last = -1;
        inOrder(root, ans, last);
        return ans;
    }

    void inOrder(TreeNode *root, int &ans, int &last)
    {
        if (!root)
            return;
        inOrder(root->left, ans, last);
        solve(root->val, ans, last);
        inOrder(root->right, ans, last);
    }

    void solve(int a, int &ans, int &last)
    {
        if (last == -1)
            ;
        else if (ans == 0 || a - last < ans)
            ans = a - last;
        last = a;
    }
};