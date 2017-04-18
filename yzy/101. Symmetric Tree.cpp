/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //101. Symmetric Tree
class Solution {
public:
   /* bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        else
            return function(root -> left, root -> right);
    }
    
    bool function(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
            return true;
        else if(!p || !q)
            return false;
        
        if(p -> val != q -> val)
            return false;
        return function(p -> left, q -> right) && function(p -> right, q -> left);
    }
    */
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>p, q;
        if(!root)
            return true;
        p.push(root -> left);
        q.push(root -> right);
        TreeNode* left;
        TreeNode* right;
        while(!p.empty() && !q.empty())
        {
            left = p.front();
            p.pop();
            right = q.front();
            q.pop();
            if(left == NULL && right == NULL)
                continue;
            else if(left == NULL || right == NULL)
                return false;
            
            if(left -> val != right -> val)
                return false;
            p.push(left -> left);
            p.push(left -> right);
            q.push(right -> right);
            q.push(right -> left);
        }
        return true;
    }
};