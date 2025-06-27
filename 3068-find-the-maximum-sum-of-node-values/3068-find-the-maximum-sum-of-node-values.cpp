class Solution {
public:
    // Main function that computes the maximum value sum
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // Memoization table to store intermediate results
        // memo[i][j] stores the result for index i and parity j (0 for odd count of XORs, 1 for even)
        vector<vector<long long>> memo(nums.size(), vector<long long>(2, -1));
        
        // Start recursion from index 0 with even parity (no XORs done yet)
        return maxSumOfNodes(0, 1, nums, k, memo);
    }

private:
    // Recursive function to calculate the max sum of nodes
    long long maxSumOfNodes(int index, int isEven, vector<int>& nums, int k, vector<vector<long long>>& memo) {
        // Base case: if we've processed all elements
        if (index == nums.size()) {
            // If the count of XOR operations is odd (isEven == 0), the result is invalid
            return isEven == 1 ? 0 : INT_MIN;
        }

        // Return memoized result if already computed
        if (memo[index][isEven] != -1) {
            return memo[index][isEven];
        }

        // Option 1: Do not apply XOR operation on current element
        long long noXorDone = nums[index] + maxSumOfNodes(index + 1, isEven, nums, k, memo);

        // Option 2: Apply XOR operation on current element, flip the parity
        long long xorDone = (nums[index] ^ k) + maxSumOfNodes(index + 1, isEven ^ 1, nums, k, memo);

        // Store and return the maximum of both options
        return memo[index][isEven] = max(xorDone, noXorDone);
    }
};