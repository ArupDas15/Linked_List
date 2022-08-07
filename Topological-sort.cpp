/*
Topological sort - Medium - https://practice.geeksforgeeks.org/problems/topological-sort/1
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of a the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then console output will be 1 else 0.


Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).


Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ (N*(N-1))/2

Reference: https://www.youtube.com/watch?v=rZv_jHZva34&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=13

*/

//Using BFS
/*
class Solution
{
	public:
	//Function to return list containing vertices in Topological order using breadth first search. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>toposort;
	    vector<int>indegree(V,0);
	    for(int i = 0; i < V; i++)
	        for(auto v:adj[i])
	            indegree[v]++;
	   queue<int>q;
	   for(int i = 0; i < V; i++){
	       if(indegree[i]==0)
	           q.push(i);
	   }
	   while(!q.empty()){
	       int v = q.front();
	       q.pop();
	       for(auto i:adj[v]){
	            indegree[i]--;
	            if(indegree[i]==0){
	                q.push(i);
	            }
	       }
	       toposort.push_back(v);
	   }
	   return toposort;
	}
};
*/

// Topological Sort using DFS.
class Solution
{
	public:
	void dfsRec(vector<int> adj[], vector<bool> &visited, int source, stack<int> &st){
	    visited[source] = true;
	    for(int i: adj[source]){
	        if(!visited[i])
	            dfsRec(adj, visited, i, st);
	    }
	    st.push(source);
	}
	//Function to return list containing vertices in Topological order using depth first search. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>toposort;
	    stack<int>st;
	    vector<bool>visited(V,false);
	    for(int i = 0; i < V; i++){
	        if(!visited[i])
	            dfsRec(adj, visited, i, st);
	    }
	    while(!st.empty()){
	        toposort.push_back(st.top());
	        st.pop();
	    }
	   return toposort;
	}
};