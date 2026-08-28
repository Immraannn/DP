class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        // dp[i] = minimum number of coins required
        //         to make amount i
        //
        // Initially, we don't know the answer for any amount,
        // so we set it to INT_MAX (infinity).
        vector<int> dp(amount + 1, INT_MAX);

        // Base case:
        // To make amount 0, we need 0 coins.
        dp[0] = 0;

        // Calculate answers for amount 1, 2, 3, ..., amount
        for(int i = 1; i <= amount; i++) {

            // Try every available coin
            for(int coin : coins) {

                // We can use this coin only if
                // coin <= current amount i
                //
                // dp[i - coin] means:
                // "minimum coins needed to make the remaining amount"
                //
                // +1 means:
                // "we are using the current coin"
                if(coin <= i && dp[i - coin] != INT_MAX) {

                    // Choose the minimum between:
                    // 1. The answer we already have for dp[i]
                    // 2. Using this coin:
                    //       dp[i - coin] + 1
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If dp[amount] is still INT_MAX,
        // it means the amount cannot be formed.
        // Otherwise, return the minimum number of coins.
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
