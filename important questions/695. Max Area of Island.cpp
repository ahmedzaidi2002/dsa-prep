/*
https://leetcode.com/problems/max-area-of-island/

Pattern:
    DFS on Grid

Difficulty:
    Medium

Time Complexity:
    O(m*n)

Space Complexity:
    O(m*n) recursion stack
*/

// ----------------------------------------
// My Code
// ----------------------------------------

class Solution {
public:

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int m,n;

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c, int sz){
        vis[r][c] = 1;
        for(int i=0;i<4;i++){
            int nr = dx[i]+r;
            int nc = dy[i]+c;
            if(nr>=0 and nr<m and nc>=0 and nc<n and !vis[nr][nc] and grid[nr][nc]==1){
                sz = dfs(grid,vis,nr,nc,sz+1);
            }
        }
        return sz;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    int curr = dfs(grid,vis,i,j,1);
                    ans = max(curr,ans);
                }
            }
        }
        return ans;
    }
};

// ----------------------------------------
// Best Code
// ----------------------------------------

class Solution {
public:
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};

    int m, n;

    int dfs(vector<vector<int>>& grid, int r, int c) {

        grid[r][c] = 0;
        int area = 1;

        for (int k = 0; k < 4; k++) {

            int nr = r + dx[k];
            int nc = c + dy[k];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                grid[nr][nc] == 1) {

                area += dfs(grid, nr, nc);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    ans = max(ans, dfs(grid, i, j));

        return ans;
    }
};

/*
----------------------------------------
Differences
----------------------------------------
1. DFS returns area (1 + neighbours) instead of threading sz as a param.
2. Marks visited by grid[r][c]=0 instead of a separate visited matrix -> saves O(m*n) space.
3. ans = max(ans, dfs(...)) directly, no temp variable.
4. Direction arrays are const.

----------------------------------------
Key Learnings
----------------------------------------
- Prefer DFS returning a value over mutating state through params.
- Reuse input grid as visited marker when mutation is allowed.
- Each recursive call should answer one clear question.
- Mark constant data as const.

----------------------------------------
Interview Notes
----------------------------------------
General grid DFS pattern:
    answer(cell) = contribution(cell) + sum(answer(valid neighbours))

Applies to: Number of Islands, Flood Fill, Surrounded Regions,
Pacific Atlantic Water Flow, Word Search, Connected Components.
*/
