/*
https://leetcode.com/problems/burst-balloons/

Pattern:
    Interval DP

Difficulty:
    Hard

Time Complexity:
    O(n^3)

Space Complexity:
    O(n^2)

See "312. Burst Balloons.md" in this folder for a full explanation of why
the recurrence has no contradiction between the subproblems and the gain
term (choosing k as the LAST balloon burst in [i, j] is the key idea).
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // padded array: arr[0] and arr[n+1] act as virtual walls of value 1
        vector<int> arr(n + 2, 1);
        for (int i = 0; i < n; i++) arr[i + 1] = nums[i];

        // dp[i][j] = max coins obtainable by bursting all balloons in [i, j]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 1; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;

                // k = last balloon burst in [i, j]
                // once k is picked, [i, k-1] and [k+1, j] are burst first
                // (independently), leaving i-1 and j+1 as k's neighbours
                for (int k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j],
                        dp[i][k - 1] + dp[k + 1][j] +
                        arr[i - 1] * arr[k] * arr[j + 1]);
                }
            }
        }

        return dp[1][n];
    }
};
