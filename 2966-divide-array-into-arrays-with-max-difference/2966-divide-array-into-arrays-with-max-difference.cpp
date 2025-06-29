class Solution {
public:

// TC=O(N log N).
// SC=O(1)

// NOTE: 1. Order of elements don't matter.
//       2. We want min. diff. between the max in min ele. in each array of size=3.
//       3. Sorting will ensure that we group ele. with min. diff. together.

    vector<vector<int>> divideArray(vector<int>& nums, int k) {

       sort(nums.begin(),nums.end());        // O(N log N)

       vector<vector<int>>ans,ans1;

       int n=nums.size();

  
       for(int i=0;i<=n-3;i+=3){            // O(N/3)~ O(N)
          
          if(nums[i+2]-nums[i]>k)
          return ans1;

          else{
             ans.push_back({nums[i],nums[i+1],nums[i+2]});
          }
       }

       return ans; 
    }
};