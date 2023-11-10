class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n;
        vector<int> ans;
        unordered_set<int> vis;
        unordered_map<int, vector<int>> graph;
        
        n = adjacentPairs.size()+1;
        for(auto p:adjacentPairs) {
            int u = p[0];
            int v = p[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(auto pair:graph){
            int startidx = pair.first;
            vector<int> neighbors = pair.second;
            if(neighbors.size()==1){
                ans.push_back(startidx);
                vis.insert(startidx);
                dfs(startidx,vis,ans,graph);
                break;
            }
        }
        return ans;
    }
    void dfs(int node, unordered_set<int>& vis, vector<int>& ans, unordered_map<int, vector<int>>& graph) {
        vector<int> neighbors = graph[node];
        for(int i = 0; i < neighbors.size(); i++) {
            if(vis.find(neighbors[i])==vis.end()) {
                ans.push_back(neighbors[i]);
                vis.insert(neighbors[i]);
                dfs(neighbors[i],vis,ans,graph);
            }
        }
    }
};
// class Solution {
// public:
//     unordered_map<int, vector<int>> graph;
    
//     vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
//         for (auto& edge : adjacentPairs) {
//             graph[edge[0]].push_back(edge[1]);
//             graph[edge[1]].push_back(edge[0]);
//         }
        
//         int root = 0;
//         for (auto& pair : graph) {
//             if (pair.second.size() == 1) {
//                 root = pair.first;
//                 break;
//             }
//         }
        
//         vector<int> ans;
//         dfs(root, INT_MAX, ans);
//         return ans;
//     }
    
//     void dfs(int node, int prev, vector<int>& ans) {
//         ans.push_back(node);
//         for (int neighbor : graph[node]) {
//             if (neighbor != prev) {
//                 dfs(neighbor, node, ans);
//             }
//         }
//     }
// };