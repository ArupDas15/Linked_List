class Solution {
public:
    // We will perform BFS on the source node and continue traversing 
    // until we reach the target node. The number of different routes we 
    // encounter is the answer.
    // Time Complexity: O(mn)
    // Space Complexity: O(mn)
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int m; // no. of routes
        int n; // no. of stops in a bus route
        int ans;
        queue<int> q;
        unordered_set<int> seen_stops;
        unordered_set<int> seen_routes;
        unordered_map<int, vector<int>> graph;

        ans = 0;
        m = routes.size();
        // Time Complexity: O(mn)
        for(int route_id = 0; route_id < m; route_id++) {
            for(auto stop : routes[route_id]) {
                graph[stop].push_back(route_id);
            }
        }
        q.push(source);
        seen_stops.insert(source);
        while(!q.empty()) {
            // Time Complexity: O(m)
            int cnt = q.size();
            
            for(int j = 0; j < cnt; j++) {
                // Time Complexity: O(n)
                int bus_stop = q.front();

                q.pop();
                if(bus_stop == target) {
                    return ans;
                }
                for(int route_id : graph[bus_stop]) {
                    if(seen_routes.find(route_id) == seen_routes.end()) {
                        // mark route_id as visited
                        seen_routes.insert(route_id); 
                        n = routes[route_id].size();
                        // visit all stops in the given route
                        for(int i = 0; i < n; i++) {
                            int stop = routes[route_id][i];

                            if(seen_stops.find(stop) == seen_stops.end()) {
                                // mark bus stop as visited
                                seen_stops.insert(stop);  
                                q.push(stop);
                            }
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
