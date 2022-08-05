/*
Detect cycle in a directed graph - Medium - https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:


Output: 0
Explanation: no cycle in the graph

Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 10^5

-----------
MY NOTES
-----------
We cannot use the algorithm we used for detecting cycle in undirected graph as it is because you can reach the same node through different nodes in a directed graph and still not have a cycle simply because the directions are not bi-directional.
Hence we use the concept of back edge i.e. if a node points to its ancestor i.e. say its parent, itself or other predecessors then we can conclude that the graph contains a cycle. 
So for detecting cycle in an undirected graph we must check if there is any back edge in the graph.

Reference: Just see the video by Sandeep Jain Sir in the article: https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  // Note: If you had not passed visited and recStk vectors through &(references) it would have still worked but it would have thrown TLE error after 263rd test case. 
  // Passing by reference makes it faster. 
  bool DFSRec(vector<int> adj[], int s, vector<bool> &visited, vector<bool> &recStk){
          visited[s]=true;
          recStk[s]=true;
          
          for(v:adj[s]){
            if(!visited[v]&&DFSRec(adj,v,visited,recStk)){
              return true;
            }
            // Check if there exists a back edge.
            else if(recStk[v])return true;
          }
      recStk[s]=false;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        vector<bool>recStk(V,false);
        for(int i = 0; i < V; i++ ){
            if(!visited[i] && DFSRec(adj, i, visited, recStk))
                return true;
        }
        return false;
    }
};
int main(){
	int t;
	cin>>t;
	while(t--){
		int V,E;
		vector<int>adj[V];
		for(int i=0;i<V;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
		}
		Solution ob;
		cout<<ob.isCyclic(V,adj)<<"\n";
	}
	return 0;
}
