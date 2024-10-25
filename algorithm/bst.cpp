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

// 783. 二叉搜索树节点最小距离
// 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
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