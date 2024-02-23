class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
	vector<int>dp(n,INT_MAX);
	dp[src]=0;
	for(int i=0;i<=k;i++){
		vector<int>temp=dp;
		for (auto node:flights){
			int u = node[0];
			int v = node[1];
			int w = node[2];
            if(dp[u]!=INT_MAX)temp[v]=min(temp[v],dp[u]+w);
		}
		dp=temp;
	}
	if(dp[dst]==INT_MAX)return -1;
	return dp[dst];
}
};