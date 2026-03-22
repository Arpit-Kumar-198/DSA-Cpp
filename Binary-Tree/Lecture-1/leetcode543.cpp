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
/*    int height(TreeNode* root){
        if(root == NULL || (!root->left && !root->right)) return 0;
        
        int ans = 0;
        if(root->left) ans = max(ans,1+height(root->left));
        if(root->right) ans = max(ans,1+height(root->right));
        return ans;
    }
    int helper(TreeNode* root){
        if(root == NULL || (!root->left && !root->right)) return 0;

        if(root->left && root->right) 
            return 2+height(root->left)+height(root->right);
        else if(root->left && !root->right) return 1+height(root->left);
        else if(!root->left && root->right) return 1+height(root->right);
        return 0;
    }
*/
    int height(TreeNode* root, int &ans){
        if(root==NULL) return 0;
        int leftHeight = height(root->left,ans);
        int rightHeight = height(root->right,ans);
        ans = max(ans,leftHeight+rightHeight);
        return 1+max(leftHeight,rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        /*
            if(root == NULL) return 0;
            int ans = helper(root);
            ans = max(ans,diameterOfBinaryTree(root->left));
            ans = max(ans,diameterOfBinaryTree(root->right));
            return ans;
        */
        int ans = 0;
        height(root, ans);
        return ans;
    }
};