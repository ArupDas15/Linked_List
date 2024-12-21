class Solution {
public:
    // Time complexity: O(n) Every node is visited at most 3 times.
    // Space complexity: O(n) if the tree is skewed.
    int dfs(vector<vector<int>>& adj, vector<vector<int>>& edges, vector<int>& values, int k, int& count, int cur, int parent) {
        int rem = values[cur] % k;
        for(int nbr : adj[cur]) {
            if (nbr != parent) {
                rem = rem + dfs(adj, edges, values, k, count, nbr, cur);
            }
        }
        if (rem % k == 0) {
            count += 1;
        }
        return rem%k;

    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        int count = 0;

        // Create an adjacency list.
        for (vector<int> edge : edges) {
            int a_i = edge[0];
            int b_i = edge[1];
            adj[a_i].push_back(b_i);
            adj[b_i].push_back(a_i);
        }
        // we are passing -1 since the root node (starting node which we have taken as 0) has no parent node
        dfs(adj, edges, values, k, count, 0, -1);        
        return count;
    }
};