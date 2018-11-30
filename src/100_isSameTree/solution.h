/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        else if (p == NULL || q == NULL) return false;
        if (p->val == q->val) return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else return false;
    }
};


// 刚开始一直想着用遍历的方法来判断两棵树是否相同，后来看了别人的思路，意识到，对于树相关的问题，最直观、最简洁的方法还是用递归。
