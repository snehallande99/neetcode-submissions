/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maximumd(TreeNode* root, int maxd)
    {
        if (root == nullptr)
           return 0;
        TreeNode *l=root->left;
        TreeNode *r=root->right;
        if(l!=nullptr || r!=nullptr)
        {
            maxd++;
            int left = maximumd(root->left, maxd);
            int right = maximumd(root->right, maxd);
            return max(left, right);
        }
        else{
            return maxd;
        }
    }
    int maxDepth(TreeNode* root) {
      if (root == nullptr)
        return 0;
      return maximumd(root,1);
    }
};
