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
    bool issame(TreeNode* p, TreeNode* q)
    {
        if(p==nullptr || q==nullptr)
        {
            if(p==nullptr && q==nullptr)
            return true;
            else
            return false;
        }
        if(p->val==q->val)
        {
          bool l = issame(p->left,q->left);
          bool r = issame(p->right,q->right);
          if(l==true and r==true)
          return true;
          else 
          return false;
        }
        else{
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        TreeNode* temp = root;
        if(root==nullptr)
        {
            if(subRoot==nullptr)
            {
                return true;
            }
            else{
                return false;
            }
        }
        bool ans =issame(temp,subRoot);
        if(ans)
        {return true;}
        else
        {
          bool l=isSubtree(temp->left,subRoot);
          bool r=isSubtree(temp->right,subRoot);
          if(l==true || r==true)
          {
            return true;
          }
          else{
            return false;
          }
        }
    }
};
