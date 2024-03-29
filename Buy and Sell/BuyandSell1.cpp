// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ - EASY
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int ans=0, cheapest = prices[0];
        for(int i=1;i<prices.size();i++){
            ans=max(ans,prices[i]-cheapest);
            cheapest=min(cheapest,prices[i]);
        }
        return ans;
    }
};
