/* Tarjan’s Algorithm to find Strongly Connected Components
Reference: https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/
DFS search produces a DFS tree/forest Strongly Connected Components form subtrees of the DFS tree. 
If we can find the head of such subtrees, we can print/store all the nodes in that subtree (including the head) and that will be one SCC. 
There is no back edge from one SCC to another (There can be cross edges, but cross edges will not be used while processing the graph).

Time Complexity: O(V+E)
Space Complexity: O(V)
*/

#include<iostream> 
#include <list> 
#include <stack> 
#define NIL -1 
using namespace std; 


class Graph 
{ 
	int V; 
	list<int> *adj; 

	void SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[]); 
public: 
	Graph(int V); 
	void addEdge(int v, int w); 
	void SCC(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
} 


// A recursive function that finds and prints strongly connected 
// components using DFS traversal 
// u --> The vertex to be visited next 
// disc[] --> Stores discovery times of visited vertices 
// low[] -- >> earliest visited vertex (the vertex with minimum 
//             discovery time) that can be reached from subtree 
//             rooted with current vertex 
// *st -- >> To store all the connected ancestors (could be part 
//         of SCC) 
// stackMember[] --> bit/index array for faster check whether 
//                 a node is in stack 
void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st, 
                    bool stackMember[]) 
{ 
    // A static variable is used for simplicity, we can avoid use 
    // of static variable by passing a pointer. 
    static int time = 0; 

    // Initialize discovery time and low value 
    disc[u] = low[u] = ++time; 
    st->push(u); 
    stackMember[u] = true; 

    // Go through all vertices adjacent to this 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i; // v is current adjacent of 'u' 

        // If v is not visited yet, then recur for it 
        if (disc[v] == -1) 
        { 
            SCCUtil(v, disc, low, st, stackMember); 

            // Check if the subtree rooted with 'v' has a 
            // connection to one of the ancestors of 'u' 
            // Case1 (Tree Edge): If node v is not visited already, then after the DFS of v is complete, 
            // a minimum of low[u] and low[v] will be updated to low[u]. 
            low[u] = min(low[u], low[v]); 
        } 

        // Update low value of 'u' only if 'v' is still in stack 
        // (i.e. it's a back edge, not cross edge). 
        // Case 2 (Back Edge): When child v is already visited, then a minimum of low[u] and Disc[v] will be updated to low[u]. 
        else if (stackMember[v] == true) 
            low[u] = min(low[u], disc[v]); 
    } 

    // head node found, pop the stack and print an SCC 
    int w = 0; // To store stack extracted vertices 
    if (low[u] == disc[u]) 
    { 
        while (st->top() != u) 
        { 
            w = (int) st->top(); 
            cout << w << " "; 
            stackMember[w] = false; 
            st->pop(); 
        } 
        w = (int) st->top(); 
        cout << w << "\n"; 
        stackMember[w] = false; 
        st->pop(); 
    } 
} 

// The function to do DFS traversal. It uses SCCUtil() 
void Graph::SCC() 
{ 
    int *disc = new int[V]; 
    int *low = new int[V]; 
    bool *stackMember = new bool[V]; 
    stack<int> *st = new stack<int>(); 

    // Initialize disc and low, and stackMember arrays 
    for (int i = 0; i < V; i++) 
    { 
        disc[i] = NIL; 
        low[i] = NIL; 
        stackMember[i] = false; 
    } 

    // Call the recursive helper function to find strongly 
    // connected components in DFS tree with vertex 'i' 
    for (int i = 0; i < V; i++) 
        if (disc[i] == NIL) 
            SCCUtil(i, disc, low, st, stackMember); 
} 


int main() 
{ 
	cout << "SCCs in the graph \n"; 
	Graph g(5); 
	g.addEdge(1, 0); 
	g.addEdge(0, 2); 
	g.addEdge(2, 1); 
	g.addEdge(0, 3); 
	g.addEdge(3, 4); 
	g.SCC(); 

	return 0; 
} 
