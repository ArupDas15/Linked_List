class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        sort(piles.begin(),piles.end());
        int k = 0;
    
        for(int i = 0, j = piles.size()-1;
            i< (piles.size() / 3) && j > (piles.size() / 3); i++){
            j--;
            cout<<piles[j]<<" ";
            ans+=piles[j];
            j--;
        }
        return ans;
    }
};