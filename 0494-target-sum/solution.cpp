class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         // Step 1: calculate total sum of array
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Step 2: check feasibility
        if ((total + target) % 2 != 0 || abs(target) > total) return 0;

        // Step 3: new target for subset sum problem
        int newTarget = (total + target) / 2;

        // Step 4: initialize dp array of size newTarget + 1 with 0
        vector<int> dp(newTarget + 1, 0);

        // Step 5: base case: one way to form sum 0 (by choosing nothing)
        dp[0] = 1;

        // Step 6: iterate over each number
        for (int num : nums) {
            // Step 7: update dp array from right to left
            for (int j = newTarget; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        // Step 8: final answer
        return dp[newTarget];
    }
};
