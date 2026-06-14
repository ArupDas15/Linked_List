class Solution {
public:
    void DFS(vector<vector<int>>& graph, int node, vector<int>& color, int expected_color, bool& set_status) {
        if(color[node] == 0) {
            color[node] = expected_color;
            expected_color = expected_color * -1;
            for(int nei : graph[node]) {
                if (color[nei] == 0) {
                   DFS(graph, nei, color, expected_color, set_status);
                   if (!set_status) {
                    // if a conflict was found deep in that subtree - STOP all other recursive DFS calls
                    return;
                   } 
                } else {
                    // check for conflict
                    if (color[nei] == color[node]) {
                        set_status =  false;
                        // prevent unnecessary traversal
                        return;
                    }
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // Mark all unvisited nodes with 0.
        // We will use 2 colors denoted by states -1 and 1.
        vector<int> color(n, 0);

        for(int i = 0; i < n; i++) {
            // check if a node is unvisited.
            if (color[i] == 0) {
                // Run DFS from node i
                int expected_color = -1;
                bool set_status = true;
                DFS(graph, i, color, expected_color, set_status);
                if (set_status == false) return false;
            }
        }  
        return true;
    }
};