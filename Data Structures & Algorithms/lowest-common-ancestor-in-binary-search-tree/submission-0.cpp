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
    TreeNode* is_anc(TreeNode* root, TreeNode* p, TreeNode* q)
    {
       if(root==nullptr)
       return nullptr;

       if(root->left==nullptr && root->right==nullptr)
       {
        if(root->val==p->val || root->val==q->val)
       return root;
       else
       return nullptr;
       }
       else{
          TreeNode* l= is_anc(root->left, p, q);
          TreeNode* r= is_anc(root->right, p, q);
          if(r!=nullptr && l!=nullptr)
          {
            return root;
          }
          else if(r!=nullptr){
            if(root->val==p->val || root->val==q->val)
            return root;
            else
            return r;
          }
          else if(l!=nullptr){
            if(root->val==p->val || root->val==q->val)
            return root;
            else
            return l;
          }
          else{
            if(root->val==p->val || root->val==q->val)
            return root;
            else
            return nullptr;
          }
       }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return is_anc(root,p,q);
    }
};
