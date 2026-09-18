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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        TreeNode* temp1=p;
        TreeNode* temp2=q;
        if(temp1==nullptr || temp2==nullptr)
        {
           if(temp1==nullptr && temp2==nullptr)
           return true;
           else
           return false;
        }
        
        if(temp1->val==temp2->val)
        {
            bool l=isSameTree(temp1->left,temp2->left);
            bool r=isSameTree(temp1->right,temp2->right);
            if(l==false || r==false)
            {
                return false;
            }
            else{
                return true;
            }
        }
        else{
            return false;
        }
    }
};
