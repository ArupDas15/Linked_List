// class Solution {
// public:
//     vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
//         vector<int>graph[adjacentPairs.size()+1];
//         for(auto p:adjacentPairs) {
//             for(auto n:p) {
//                 graph[n].push_back(p);
//             }
//         }
//         for(int i=0;i<adjacentPairs.size()+1;i++){
//             if(graph[i].size()==1){

//             }
//         }
//     }
// };
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for (auto& edge : adjacentPairs) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int root = 0;
        for (auto& pair : graph) {
            if (pair.second.size() == 1) {
                root = pair.first;
                break;
            }
        }
        
        vector<int> ans;
        dfs(root, INT_MAX, ans);
        return ans;
    }
    
    void dfs(int node, int prev, vector<int>& ans) {
        ans.push_back(node);
        for (int neighbor : graph[node]) {
            if (neighbor != prev) {
                dfs(neighbor, node, ans);
            }
        }
    }
};