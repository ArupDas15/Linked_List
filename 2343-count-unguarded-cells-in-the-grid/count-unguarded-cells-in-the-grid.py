class Solution:
    def __init__(self):
        # Direction arrays: dirx and diry for the four directions (Up, Right, Down, Left)
        self.dirx = [-1, 0, 1, 0]  # x-coordinate changes for Up, Right, Down, Left
        self.diry = [0, 1, 0, -1]  # y-coordinate changes for Up, Right, Down, Left

    def dfs(self, grid, direction, x, y):
        # Check if the current cell is out of bounds or contains a guard (2) or a wall (3)
        if x < 0 or x >= len(grid) or y < 0 or y >= len(grid[0]) or grid[x][y] == 2 or grid[x][y] == 3:
            return
        
        # Mark the current cell as guarded
        grid[x][y] = 1

        # Perform DFS in the specified direction
        if direction == 0:
            self.dfs(grid, direction, x - 1, y)  # Up
        elif direction == 1:
            self.dfs(grid, direction, x, y + 1)  # Right
        elif direction == 2:
            self.dfs(grid, direction, x + 1, y)  # Down
        else:
            self.dfs(grid, direction, x, y - 1)  # Left

    def countUnguarded(self, m, n, guards, walls):
        # Create a grid of size m x n, initialized to 0 (unguarded)
        grid = [[0] * n for _ in range(m)]
        count = 0

        # Mark the guard cells with 2
        for guard in guards:
            grid[guard[0]][guard[1]] = 2
        
        # Mark the wall cells with 3
        for wall in walls:
            grid[wall[0]][wall[1]] = 3
        
        # Iterate over each guard and perform DFS in all 4 directions
        for guard in guards:
            for i in range(4):
                x = guard[0] + self.dirx[i]
                y = guard[1] + self.diry[i]
                # Perform DFS in the direction specified by i
                self.dfs(grid, i, x, y)
        
        # Count the number of unguarded cells (cells with value 0)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    count += 1

        # Return the count of unguarded cells
        return count
