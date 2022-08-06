class Solution {
public:
    // Retruns false if the graph is not biparitite
    bool bfs(vector<vector<int>>& graph, int s, vector<int>&color){
        queue<int> q;
        int u;
        color[s]=1;
        q.push(s);
        while(q.empty()==false){
            u = q.front();
            q.pop();
            for(int v:graph[u]){
                if(color[v]==-1){
                    q.push(v);
                    color[v]=(1-color[u]);
                    cout<<"Source: "<<u<<" (Color: )"<<color[u]<<", Adjacent vertex: "<<v<<"(Color: )"<<color[v]<<endl;
                }
                else if(color[v]==color[u])
                    return false;
            }
        }
    return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        // for(int i: color){
        //     cout<<i;
        // }
        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1){
                if(!bfs(graph, i, color))
                    return false;
            }
        }
        return true;
    }
};