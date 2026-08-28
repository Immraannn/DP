//top down memoization
int solve(int n, vector<int>& dp)
{
    // base case
    if(n <= 1)
        return n;
    // already calculated
    if(dp[n] != -1)
        return dp[n];
    // store and return
    dp[n] = solve(n-1, dp) + solve(n-2, dp);
    return dp[n];
}
int fib(int n)
{
    vector<int> dp(n+1, -1);
    return solve(n, dp);
}

//Bottom up -tabulation
int fib(int n)
{
    vector<int> dp(n+1);
    // base case
    dp[0] = 0;
    if(n >= 1)
        dp[1] = 1;
    // calculate
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

//O(1) space
int fib(int n)
{
    if(n <= 1)
        return n;
    int prev2 = 0;
    int prev1 = 1;
    for(int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
 return prev1;
}
