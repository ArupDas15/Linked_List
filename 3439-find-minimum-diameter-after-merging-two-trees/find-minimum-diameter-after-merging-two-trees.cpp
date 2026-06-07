class Solution {
public:
    pair<int, int> bfs(vector<vector<int>>&adj, int startnode) {
        int n = adj.size();
        queue<int>q;
        vector<int> dist(n,-1);
        dist[startnode] = 0;
        q.push(startnode);
        int farthestnode=startnode;
        int max_dist=0;
        int level = 0;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            // Update farthest if current distance is larger
            if (dist[curr] > max_dist) {
                max_dist = dist[curr];
                farthestnode = curr;
            }
            for(int nei : adj[curr]){
                // if neighbor is not visited
                if (dist[nei] == -1) {
                    dist[nei] = dist[curr] + 1;
                    q.push(nei);
                }
            }
        }
        return {farthestnode, max_dist};
    }
    int getDiameter(vector<vector<int>>& adj) {
        // Base case: Single node tree
        if (adj.size() < 2) return 0;
        // BFS() returns diameter endpoints and diameter: start_node, end_node, distance
        pair <int,int> NodeA = bfs(adj, 0);
        pair<int,int> NodeB = bfs(adj, NodeA.first);
        return NodeB.second;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>>adjl1 (edges1.size()+1);
        vector<vector<int>>adjl2 (edges2.size()+1);
        for(auto& edge:edges1) {
            int a = edge[0];
            int b = edge[1];
            adjl1[a].push_back(b);
            adjl1[b].push_back(a);
        }
        for(auto& edge:edges2) {
            int u = edge[0];
            int v = edge[1];
            adjl2[u].push_back(v);
            adjl2[v].push_back(u);
        }
        int D1 = getDiameter(adjl1);
        int D2 = getDiameter(adjl2);
        return std::max({D1, D2, ((D1+1)/2)+((D2+1)/2)+1});
    }
};