class Solution:
    # Time complexity: O(n)
    # Space complexity: O(n)
    def dfs(self, adj: List[List[int]], edges: List[List[int]], values: List[int], k: int, count: List[int], cur: int, parent: int) -> int:
        rem = values[cur] % k
        
        for nbr in adj[cur]:
            if nbr != parent:
                rem = rem + self.dfs(adj, edges, values, k, count, nbr, cur)
        if rem % k == 0: count[0] += 1
        return rem % k

    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        adj = [[] for _ in range(n)]
        count = [0]

        for edge in edges:
            a_i = edge[0]
            b_i = edge[1]
            adj[a_i].append(b_i)
            adj[b_i].append(a_i)
        self.dfs(adj, edges, values, k, count, 0, -1)
        return count[0]
