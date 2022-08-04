/*
Detect cycle in an undirected graph - Medium - https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.

Example 1:

Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
Output: 1
Explanation: 

1->2->3->4->1 is a cycle.
Example 2:

Input: 
V = 4, E = 2
adj = {{}, {2}, {1, 3}, {2}}
Output: 0
Explanation: 
No cycle in the graph.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.

 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)


 

Constraints:
1 ≤ V, E ≤ 10^5

Reference: https://www.youtube.com/watch?v=A8ko93TyOns&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=7

------------------
MY NOTES
------------------
You should remeber the concept that while detecting a cycle you should consider only those nodes which are not the parent nodes of the current vertex.
A parent node for a vertex is a node immediately through which a node was discovered. For example: 1->2->3. Parent node(2) = 1, Parent node(3) = 2. 
In our solution we have insitialised the parent node of the source vertex with -1 which pushing the source vertex into the queue. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  bool checkcycle(vector<int> adj[], int source, vector<bool> &visited){
      visited[source] = true;
      // pair<node, previous node>
      queue<pair<int,int>>q;
      q.push({source,-1});
      while(!q.empty()){
          pair<int,int> vertex = q.front();
          q.pop();
          for(v:adj[vertex.first]){
              if(!visited[v] && v!=vertex.second)
                {
                    q.push({v,vertex.first});
                    visited[v] = true;
                }
                else if(visited[v] && v!=vertex.second)
                    return true;
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        for(int i =0 ; i<V;i++){
            if(!visited[i])
                if(checkcycle(adj, i, visited))
                    return true;
                else continue;
        }
        return false;
    }
};

//  Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  //  Driver Code Ends