//Top-Down — Memoization
class Solution {
public:
    int solve(int n, vector<int>& cost, vector<int>& dp)
    {
        // base case
        if(n <= 1)
            return cost[n];

        // already calculated
        if(dp[n] != -1)
            return dp[n];

        // store and return
        dp[n] = cost[n] + min(solve(n-1, cost, dp),
                              solve(n-2, cost, dp));

        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();

        vector<int> dp(n, -1);

        return min(solve(n-1, cost, dp),
                   solve(n-2, cost, dp));
    }
};
//bottom up-Tabulation

class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();

        vector<int> dp(n);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);
    }
};
//O(1)
class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();

        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i = 2; i < n; i++)
        {
            int curr = cost[i] + min(prev1, prev2);

            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};
