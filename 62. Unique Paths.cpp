/*
https://leetcode.com/problems/unique-paths/

Pattern:
    DP on Grid (space optimized)

Difficulty:
    Medium

Time Complexity:
    O(m*n)

Space Complexity:
    O(n)
*/

// ----------------------------------------
// My Code
// ----------------------------------------

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> g(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                g[j] = g[j]+g[j-1];
            }
        }
        return g[n-1];
    }
};

// ----------------------------------------
// Best Code
// ----------------------------------------

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        int total = m + n - 2, r = min(m, n) - 1;
        for (int i = 1; i <= r; i++)
            ans = ans * (total - r + i) / i;
        return (int)ans;
    }
};

/*
----------------------------------------
Differences
----------------------------------------
1. My code: 1D DP, O(m*n) time, O(n) space.
2. Best code: combinatorics formula, O(min(m,n)) time, O(1) space.
3. My code builds up path counts cell by cell.
   Best code directly computes the answer with a math formula, no grid needed.

----------------------------------------
Key Learnings
----------------------------------------
- A DP where dp[i][j] only depends on dp[i-1][j] and dp[i][j-1] can be
  collapsed to a 1D array (row reuse trick).
- Counting-paths-on-a-grid problems are often disguised combinatorics
  problems (choosing which steps go in which direction).

----------------------------------------
Interview Notes
----------------------------------------
General grid DP pattern (1D optimization):
    dp[j] (before update) = value from row above
    dp[j-1] (already updated this row) = value from left
    => dp[j] += dp[j-1] reuses one array for both directions.

Combinatorics trick, explained simply:
- To go from top-left to bottom-right, you must take exactly
  (m-1) "down" moves and (n-1) "right" moves, in some order.
- Total moves = (m-1) + (n-1).
- Every unique path is just a different arrangement (order) of these
  down/right moves. E.g. DDRR, DRDR, RRDD, ... are all different paths.
- So the answer is just: "out of all the move slots, how many ways can
  I choose which ones are 'down'?" That's the combination formula:
      C(total moves, down moves) = C(m+n-2, m-1)
- The code computes this C(total, r) iteratively without factorials
  (avoids overflow, integer division stays exact because it multiplies
  before dividing at each step).

Applies to: any "count paths on a grid with only 2 move directions"
problem (e.g. Unique Paths II with obstacles needs DP, not combinatorics,
since obstacles break the pure combinatorial counting).
*/
