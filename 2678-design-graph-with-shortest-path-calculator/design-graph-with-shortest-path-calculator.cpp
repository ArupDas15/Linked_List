class Graph {
public:
    vector<vector<pair<int, int>>> adjList;
    Graph(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        for(vector<int> e : edges) {
            adjList[e[0]].push_back({e[1], e[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adjList[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(adjList.size(), INT_MAX);
        dist[node1] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,node1});
        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(int i = 0; i < adjList[node].size(); i++) {
                int neighbor = adjList[node][i].first;
                int edgewt = adjList[node][i].second;
                if(d+edgewt<dist[neighbor]) {
                    dist[neighbor]=d+edgewt;
                    pq.push({dist[neighbor],neighbor});
                }
            }
        }
        if(dist[node2]==INT_MAX)return -1;
        return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */