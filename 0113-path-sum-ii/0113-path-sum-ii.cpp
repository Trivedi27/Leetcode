/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     Tree/**
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        if(root == nullptr) return {};
        int sum = 0;
        dfs(root,targetSum,sum,path,result);
        return result;
    }
    void dfs(TreeNode * root , int targetSum , int sum , vector<int>&path ,vector<vector<int>>&result){
        if(root == nullptr) return ;
        if(root->left == nullptr && root->right == nullptr && sum + root->val == targetSum){
            path.push_back(root->val);
            result.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        dfs(root->left,targetSum , sum+root->val,path,result);
        dfs(root->right , targetSum , sum + root->val, path, result);
        path.pop_back();
    }
};Node *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
    }
};