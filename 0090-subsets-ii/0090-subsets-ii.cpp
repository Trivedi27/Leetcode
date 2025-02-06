class Solution {
public:

    void subsets(vector<int>& nums, int i, vector<int>& sub,vector<vector<int>>& subs){
        subs.push_back(sub);
        for(int j = i; j < nums.size(); j++){
            if(j > i and nums[j] == nums[j - 1]) continue; // this is the only condition which we need to add in our solution of subset 1 problem
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
};