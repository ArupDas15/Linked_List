/*
Find the number of islands - Medium - https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1/

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands :- one is colored in blue 
and other in orange.
Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes the grid as an input parameter and returns the total number 
of islands.

Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints:
1 ≤ n, m ≤ 500

--------------
MY NOTES
--------------
This question is an alternative way of asking: find the number of connected components in an undirected/directed graph.
The approach I liked in this question is how we are checking for valid neighbors of a vertex. We considered all the eight neighbors while checking for the valid 
neighbors. Also, since the grid is not a square grid so we could not store the vertex of the graph in conventional way, rather we had to store the row and column 
of the vertex as a pair in the queue data structure. This was also the reason why we needed to use a 2D visited array. However we could have used two one-dimensional 
visited array for marking the row and column index of the visited vertex.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  bool isValid(int i, int j, int n, int m){
      if((i >= 0 && i<n) && (j>=0 && j < m))
        return true;
      return false;
  }

  void BFS(vector<vector<char>>& grid, pair<int,int> source, vector<vector<bool>>& visited){
      visited[source.first][source.second] = true;
      queue<pair<int,int>>q;
      q.push(source);
      int n = grid.size();
      int m = grid[0].size();
      int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
      int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
      while(q.empty() == false){
          pair<int,int> u = q.front();
          q.pop();
          int i = u.first;
          int j = u.second;
          for(int k = 0; k < 8; k++){
              if(isValid(i + di[k], j + dj[k], n, m) 
                 && !visited[i + di[k]][j + dj[k]] 
                 && grid[i + di[k]][j + dj[k]] == '1')
              {
                  q.push({i + di[k], j + dj[k]});
                  visited[i + di[k]][j + dj[k]] = true;
              }
          }
      }
      
  }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j < m; j++){
                if(grid[i][j] == '1'){
                    pair<int,int> element(i,j);
                    if(!visited[element.first][element.second]){
                        count++;
                        BFS(grid, element, visited);
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends
