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
    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0,flag = 0,num = 0;
        // finding the root node value
        while(traversal[i] != '-' && i < traversal.size()){
            num = num*10+(traversal[i]-'0');
            i++;
        }
        TreeNode* root = new TreeNode(num);
        // decrementing so that "i" pointer stays on the last numeric value
        i--;
        h(root,i,traversal,0,flag);
        return root;
    }
private:
    void h(TreeNode* root,int& i,string& traversal,int depth,int& flag){
        if(i >= traversal.size()-1) return; // return when string ends
        
        pair<int,int> next_depth_info = cal_(i,traversal,flag);
        if(depth + 1 == next_depth_info.first){
            root->left = new TreeNode(next_depth_info.second);
            flag = 0;
            h(root->left,i,traversal,depth + 1,flag);
        }
        next_depth_info = {-10,-10}; // resetting to garbage value so that previously used value is not used again
        if(flag) next_depth_info = cal_(i,traversal,flag);
        if(depth + 1 == next_depth_info.first){
            root->right = new TreeNode(next_depth_info.second);
            flag = 0;
            h(root->right,i,traversal,depth + 1,flag);
        }
        // flagging indicates now we have to check for right child when the recursion call returns
        flag = 1;
        return;
    }

    pair<int,int> cal_(int& i,string& traversal,int& flag){
        // finding value when going forward i.e. for left child
        if(flag == 0){
            i++;
            int count = 0;
            while(traversal[i] == '-'){
                count++;
                i++;
            }
            int num = 0;
            bool f = false;
            while(traversal[i] != '-' && i < traversal.size()){
                // cout << i << endl;
                num = num * 10 + (traversal[i]-'0');
                i++;
                f = true;
            }
            if(f) i--;
            return {count,num};
        }
        // finding value after backtracking so that we do not mishandle the "i" pointer i.e. while parsing right child
        else{
            int temp = i;
            int count = 0;
            string t;
            int num = 0;
            // some extra work to reversely parse the integer value
            while(traversal[temp] != '-'){
                // cout << traversal[temp] << endl;
                t.push_back(traversal[temp]);
                temp--;
            }
            for(int j = t.size()-1;j >= 0;j--){
                num = num*10 + (t[j]-'0');
            }
            
            while(traversal[temp] == '-'){
                count++;
                temp--;
            }
            return {count,num};
        }
    }
};