/*
A vertex in an undirected connected graph is an articulation point (or cut vertices) if removing it (and the edges through it) disconnects the graph.
We need to find the articulation points in the given undirected graph.
--------------------------------------------------------------------------------------------------------------------------------------------------------
There are two observations to be made:
Observation 1: A root node (i.e. starting node) in a DFS traversal is an articulation point if it has two children. Hence the case child>1 && parent==-1. 
               Here child indicates the number of DFS calls made after visiting the root node.
Observation 2: A non-root node 'u' (denoted by parent!=-1) is an articulation point if there exists a child node 'v' such that low[v]>=disc[node], i.e. the node 
              'v' is unable to reach any of the ancestors of 'u'. If low[v]=disc[node], then it means we can almost reach 'v' from 'u' and no node before 'u'.
Time Complexity: O(V+E)
Space Complexity: O(V)

Reference: GFG: https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
	   Striver: https://www.youtube.com/watch?v=3t3JHswP7mw&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
*/
include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &vis, vector<int> &disc, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation) {
    vis[node] = 1; 
    disc[node] = low[node] = timer++;
    int child = 0; 
    for(auto it: adj[node]) {
        if(it == parent) continue;
        
        if(!vis[it]) {
            dfs(it, node, vis, disc, low, timer, adj, isArticulation); 
            low[node] = min(low[node], low[it]); 
	    child++; 
            if(low[it] >= disc[node] && parent != -1) {
                isArticulation[node] = 1; 
            }
        } else {
            low[node] = min(low[node], disc[it]); 
        }
    }
    
    if(parent == -1 && child > 1) {
        isArticulation[node] = 1; 
    }
}
int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> disc(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0);
	vector<int> isArticulation(n, 0); 
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, vis, disc, low, timer, adj, isArticulation); 
	    }
	}
	
	for(int i = 0;i<n;i++) {
	    if(isArticulation[i] == 1) cout << i << endl;
	}
	
	return 0;
}
/*	Biconnected Component - Variation of articulation points
	**READ THIS**: https://www.cdn.geeksforgeeks.org/biconnectivity-in-a-graph/
	A connected graph is Biconnected if it is connected and doesn’t have any Articulation Point. We mainly need to check two things in a graph. 
	1. The graph is connected. 
	2. There is no articulation point in graph.
	We start from any vertex and do DFS traversal. In DFS traversal, we check if there is any articulation point. If we don’t find any articulation point, 
	then the graph is Biconnected. Finally, we need to check whether all vertices were reachable in DFS or notby cehcking if there is any unvisited vertex 
	left by traversing the visited array(i.e. if(visited[i]==flase for i between 0 to V then the graph is not conected.)). If all vertices were not reachable, 
	then the graph is not even connected. 
*/
