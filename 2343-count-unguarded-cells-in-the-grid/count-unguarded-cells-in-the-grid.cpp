class Solution {
public:
    /* ALGORITHM
    1. First we will create a 2D vector grid of size m*n initialised to 0 
       (indicating ungruarded) and mark guard cells with 2 and wall cells with 3.
       We will follow below convention:
       0 - indicates the cell is unguarded.
       1 - indicates the cell is guarded.
       2 - indicates a guard is present.
       3 - indicates a wall is present.
    2. Create a direction array, dirx = {-1, 0, 1, 0} and diry = {0, 1, 0, -1}.
    3. Then, we will iterate over all the guards and for each guard we will do the following stuffs
        3.1. we will do a dfs call in all 4 directions and mark unguarded calls as guarded if we do not
             encounter a guard or a wall. 
             if dir == 0  move up
             else if dir == 1 move right
             else if dir == 2 move down
             else if dir == 3 move left
    4. Iterate over all the elements in grid and return the count of all the unguarded cells.
    */
    // Time Complexity: O(g*(m+n) + O(m*n))
    // space complexity: O(m*n)
    vector<int> dirx = {-1, 0, 1, 0}; // x-coordinate changes for Up, Right, Down, Left
    vector<int> diry = {0, 1, 0, -1}; // y-coordinate changes for Up, Right, Down, Left
    void dfs(vector<vector<int>> &grid, int direction, int x, int y) {
        if ((x < 0) or (x >= grid.size()) or (y < 0) or (y >= grid[0].size()) or (grid[x][y] == 2) or (grid[x][y] == 3)) {
            return;
        }
        // Mark the given cell as guarded.
        grid[x][y] = 1;
        // Do DFS in UPWARD DIRECTION
        if (direction == 0) dfs(grid, direction, x-1, y);
        // Do DFS in RIGHT DIRECTION
        else if (direction == 1) dfs(grid, direction, x, y+1);
        // Do DFS in DOWNWARD DIRECTION
        else if (direction == 2) dfs(grid, direction, x+1, y);
        // Do DFS in LEFTWARD DIRECTION
        else dfs(grid, direction, x, y-1);
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid (m, vector<int> (n, 0));
        int count = 0;

        // Mark guard cells
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }
        // Mark wall cells
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 3;
        }
        // Iterate over each guard
        for (auto& guard : guards) {
            for (int i = 0; i < 4; i++) {
                int x = guard[0] + dirx[i];
                int y = guard[1] + diry[i];
                // Do DFS() in all 4 directions.
                dfs(grid, i, x, y);
            }
        }
        // Count all unguarded cells
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) count++;
            }
        }
        // Return the count
        return count;
    }
};