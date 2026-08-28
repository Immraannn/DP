//Tabu O(n),O(n)
int maximumNonAdjacentSum(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return arr[0];
    vector<int> dp(n);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        int pick = arr[i] + dp[i - 2];
        int notPick = dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
}
//O(1)space
int maximumNonAdjacentSum(vector<int>& arr) {
    int n = arr.size();

    if (n == 0) return 0;
    if (n == 1) return arr[0];

    int prev2 = arr[0];
    int prev1 = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        int pick = arr[i] + prev2;
        int notPick = prev1;
        int curr = max(pick, notPick);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
