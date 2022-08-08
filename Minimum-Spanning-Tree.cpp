/*
Minimum Spanning Tree - Medium - https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.


Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function  spanningTree() which takes number of vertices V and an adjacency matrix adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains a list of lists containing two integers where the first integer a[i][0] denotes that there is an edge between i and a[i][0][0] and second integer a[i][0][1] denotes that the distance between edge i and a[i][0][0] is a[i][0][1].

In other words , adj[i][j] is of form  { u , wt } . So,this denotes that i th node is connected to u th node with  edge weight equal to wt.

Expected Time Complexity: O(ElogV).
Expected Auxiliary Space: O(V2).
 

Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
Graph is connected and doesn't contain self loops & multiple edges.

Video Solution Reference: https://www.youtube.com/watch?v=oNTsS8lGDHw&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=20
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int u, v, weight;
        vector<int>key(V,INT_MAX);
        int Parent[V];
        bool mstSet[V]={false};
        Parent[0]=-1;
        key[0]=0;
        pq.push({0,0});
        // Run the loop till all the nodes have been visited i.e. until the pq is empty.
        // In the brute code we checked for mstSet[node] == false while computing the minimum
        // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
        // hence its better to keep running till all the nodes have been taken. 
        // try the following case: 
        // Credits: Srejan Bera
        // 6 7 
        // 0 1 5 
        // 0 2 10 
        // 0 3 100 
        // 1 3 50 
        // 1 4 200
        // 3 4 250
        // 4 5 50 
        // Reference: https://github.com/striver79/StriversGraphSeries/blob/main/primsAlgoCppEfficient
        while(!pq.empty()){
            u = pq.top().second;
            pq.pop();
            mstSet[u] = true;
            for(auto it: adj[u]){
                v = it[0];
                weight = it[1];
                if(mstSet[v] == false && weight < key[v]){
                    key[v]=weight;
                    Parent[v]=u;
                    pq.push({weight,v});
                }
            }
        }
        return accumulate(key.begin(),key.end(),0);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends