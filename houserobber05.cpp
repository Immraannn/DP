//MEMO
class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        // Base case
        if(i < 0)
            return 0;
        // Already calculated
        if(dp[i] != -1)
            return dp[i];
        // Don't rob current
        int notRob = solve(i - 1, nums, dp);
        // Rob current
        int rob = nums[i] + solve(i - 2, nums, dp);
        return dp[i] = max(rob, notRob);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, -1);

        return solve(n - 1, nums, dp);
    }
};
//Tsbulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> dp(n, 0);
        // Base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        // Fill DP table
        for(int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        return dp[n-1];
    }
};
//O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        // prev2 = dp[i-2]
        int prev2 = nums[0];
        // prev1 = dp[i-1]
        int prev1 = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++) {
            // Current dp[i]
            int curr = max(prev1, nums[i] + prev2);
            // Move forward
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
