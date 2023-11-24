class Solution {
public:
    // time complexity: O(nlog n)
    // space complexity: O(log n)
    int maxCoins(vector<int>& piles) {
        int ans = 0;

        sort(piles.begin(),piles.end());
        for(int j = piles.size()-1;
            j > (piles.size() / 3); ){
            j--;
            ans+=piles[j];
            j--;
        }
        return ans;
    }
};