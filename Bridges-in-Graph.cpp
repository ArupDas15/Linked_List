// Reference: Watch Jenny's lecture first: https://www.youtube.com/watch?v=CsGP_s_3GWg 
// then watch Striver's video for code: https://www.youtube.com/watch?v=2rjZH0-2lhk&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=25

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &vis, vector<int> &discovery_time, vector<int> &lowest_finish_time, int &timer, vector<int> adj[]){
	vis[node] = 1;
	discovery_time[node] = lowest_finish_time[node] = timer++;
	for(auto it: adj[node]){
	    // If the adjacent node is a parent node then as per the Bridge detecting algorithm you do not visit the parent
	    // node before backtracking neither do you check its finishing time, so we skip the parent node.
		if(it == parent)
			continue;
		// Perform a dfs operation on the adjacent node if it is not visited.
		if(!vis[it]){
			dfs(it, node, vis, discovery_time, lowest_finish_time, timer, adj);
			// Update the finishing time of the parent node (i.e. the current
			// node) after comparing the finishing time of the adjacent node
			// which is computed via the dfs().
			lowest_finish_time[node] = min(lowest_finish_time[node], lowest_finish_time[it]);
			if(lowest_finish_time[it] > discovery_time[node])
				cout<<"Bridge: " <<node+1<< " "<< it+1 << endl;
		}
		else
			lowest_finish_time[node] = min(lowest_finish_time[node], discovery_time[it]);
	}// end of for-loop.
}// end of dfs().

int main(){
	int n, m;
	cin >> n;
	cin >> m;
	vector<int> adj[n];

  for(int i = 0; i < m; i++){
		int u, v;
		cin>> u;		
		cin>> v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
		cout<<"Edge created: "<<u<<" "<<v<<endl;
	}

  vector<int> discovery_time(n, -1);
	vector<int> lowest_finish_time(n, -1);
	vector<int> vis(n, 0);
	int timer = 0;
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			// Since there is no parent node for a source node so we assign the parent node of source node as -1.
			dfs(i, -1, vis, discovery_time, lowest_finish_time, timer, adj);
		}
	}
	return 0;
}

/*
OUTPUT
------------
12 14
1 2
Edge created: 1 2
1 4
Edge created: 1 4
2 3
Edge created: 2 3
3 4
Edge created: 3 4
4 5
Edge created: 4 5
5 6
Edge created: 5 6
6 7
Edge created: 6 7
6 9
Edge created: 6 9
7 8
Edge created: 7 8
8 9
Edge created: 8 9
8 10 
Edge created: 8 10
10 11
Edge created: 10 11
10 12
Edge created: 10 12
11 12
Edge created: 11 12
Bridge: 8 10
Bridge: 5 6
Bridge: 4 5
*/
