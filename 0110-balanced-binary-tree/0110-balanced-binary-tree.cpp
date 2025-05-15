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
    int check_height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1+max(check_height(root->left),check_height(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int diff = abs(check_height(root->left)-check_height(root->right));
        if(diff>=2){
            return false;
        }else{
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
};
