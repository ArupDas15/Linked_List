class Solution {
public:
    /*
    1. Sort the items array based on price.
    2. Store maxBeauty for every items.
    3. Iterate thorugh all the queries and perform 
       ans[i] = Binary Search(items,queries[i])
    */
    // Time Complexity: O((M+N)⋅logM)
    // Space Complexity: O(S_M)
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans(queries.size(), 0);
        sort(items.begin(),items.end(),[](vector<int>&a,vector<int>&b){return a[0] < b[0];});
        int maxBeauty = items[0][1];
        for(int i = 0; i < items.size(); i++) {
            maxBeauty = max(items[i][1], maxBeauty);
            items[i][1] = maxBeauty;
        }
        for(int i = 0; i < queries.size(); i++) {
            ans[i] = binarySearch(items,queries[i]);
        }
        return ans;
    }
    int binarySearch(vector<vector<int>> &items, int targetPrice) {
        int left = 0;
        int right = items.size() - 1;
        int maxBeauty = 0;
        while(left <= right) {
            int mid = (left + right) / 2;
            if (items[mid][0] > targetPrice) {
                right = mid - 1;
            } else {
                maxBeauty = max(maxBeauty, items[mid][1]);
                left = mid + 1;
            }
        }
        return maxBeauty;
    }
};