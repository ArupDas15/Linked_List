/*
Strongly connected component (Tarjans's Algo) - Hard- https://practice.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo-1587115621/1
Given a Directed Graph with V vertices and E edges, Find the members of strongly connected components in the graph.
Your Task:
You don't need to read input or print anything. Your task is to complete the function tarjans() which takes the number of vertices V and adjacency list of the graph as input parameters and returns a list of list of integers denoting the members of strongly connected components in the given graph.
Note: A single strongly connected component must be represented in the form of a list of integers sorted in the ascending order. The resulting list should consist of a list of all SCCs which must be sorted in a way such that a lexicographically smaller list of integers appears first.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 ≤ V  ≤ 105
1 ≤ E  ≤ 105
0 ≤ u, v ≤ N-1
*/

#include<bits/stdc++.h>
using namespace std;

bool compare1(vector<int> v1, vector<int> v2)
{
    return v1.front()<v2.front();
}

class Solution
{
	public:
	// Notice here that unlike the approach of disc and low in articulation points and brdges we are not passing the parent information over here because
	// the objective is not to find critical vertices or edges in the graph rather it is to find strongly connected components. 
	void SCCUtil(int u, vector<int>&disc, vector<int>&low, stack<int> &st, vector<bool> &recStk, int &timer, vector<int>adj[], vector<vector<int>>&SCC_ans){ 
      // Initialize discovery time and low value 
      disc[u] = low[u] = ++timer; 
      st.push(u); 
      recStk[u] = true; 

      // Go through all vertices adjacent to the node u 
      for (auto v : adj[u]) // v is current adjacent of 'u'
      {   // If v is not visited yet, then recur for it 
        if (disc[v] == -1) 
        { 
            SCCUtil(v, disc, low, st, recStk, timer, adj, SCC_ans); 

            // Check if the subtree rooted with 'v' has a 
            // connection to one of the ancestors of 'u' 
            // Case1 (Tree Edge): If node v is not visited already, then after the DFS of v is complete, 
            // a minimum of low[u] and low[v] will be updated to low[u]. 
            low[u] = min(low[u], low[v]); 
        } 

        // Update low value of 'u' only if 'v' is still in stack 
        // (i.e. it's a back edge, not cross edge). 
        // Case 2 (Back Edge): When child v is already visited, then a minimum of low[u] and Disc[v] will be updated to low[u]. 
        else if (recStk[v] == true) 
            low[u] = min(low[u], disc[v]); 
      } 
    
      if (low[u] == disc[u]) 
      { 
        // head node found, pop the stack and print an SCC 
        int w = 0; // To store stack extracted vertices 
        vector<int>ans;
        while (st.top() != u) 
        { 
            w =  st.top(); 
            ans.push_back(w);
            recStk[w] = false; 
            st.pop(); 
        } 
        w =  st.top();
        ans.push_back(w);
        recStk[w] = false; 
        st.pop();
        sort(ans.begin(),ans.end());
        SCC_ans.push_back(ans);
      }
    } 
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        vector<int>disc(V,-1);
        vector<int>low(V,-1);
        vector<bool>recStk(V,false);
        stack<int>st; 
        vector<vector<int>> SCC_ans;
        int timer = 0;        
        // Call the recursive helper function to find strongly 
        // connected components in DFS tree with vertex 'i' 
        for (int i = 0; i < V; i++) {
            if(disc[i]==-1)//  We are using disc array as visited array also. 
                SCCUtil(i, disc, low, st, recStk, timer, adj, SCC_ans);
        }
        //sorting all the lists in final answer list.
        sort(SCC_ans.begin(),SCC_ans.end(),compare1);
        return SCC_ans;
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int V,E;
		cin>>V>>E;
		vector<int>adj[V];
		for(int i=0;i<E;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
		}
		Solution obj;
		vector<vector<int>>ptr=obj.tarjans(V,adj);
		for(int i=0;i<ptr.size();i++){
			for(int j=0;j<ptr[i].size();j++){
				if(j==ptr[i].size()-1)
					cout<<ptr[i][j];
				else cout<<ptr[i][j]<<" "; 
			}
			if(i<ptr.size()-1)
				cout<<",";
		}
		cout<<endl;
	}
	return 0;
}

/*
	OUTPUT
	------
1
10 15
5 4
6 6
3 9
9 5
2 1
3 0
9 9
1 3
4 5
8 5
7 3
3 8
9 5
5 3
8 6
0,1,2,3 4 5 8 9,6,7
*/
