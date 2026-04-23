class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        // Step 1: Build graph
        vector<vector<int>> adjList(n);
        
        for(int i = 0; i < n; i++) {
            long long xi = bombs[i][0];
            long long yi = bombs[i][1];
            long long ri = bombs[i][2];
            
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                
                long long xj = bombs[j][0];
                long long yj = bombs[j][1];
                
                long long dx = xj - xi;
                long long dy = yj - yi;
                
                if(dx*dx + dy*dy <= ri*ri) {
                    adjList[i].push_back(j);
                }
            }
        }
        
        int ans = 0;
        
        // Step 2: BFS from each node
        for(int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            queue<int> q;
            
            q.push(i);
            visited[i] = true;
            
            int count = 0;
            
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                count++;
                
                for(int nei : adjList[node]) {
                    if(!visited[nei]) {
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }
            
            ans = max(ans, count);
        }
        
        return ans;
    }
};