//  Best Time to Buy and Sell Stock III - HARD -https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/ (Atmost 2 transactions)
class Solution {
public:
    int dp[100001][2][3];
    int maxProfit(vector<int>& prices) {
        int k = 2, n = (int)prices.size();
        for(int days = n-1;days>=0;days--){
            for(int trans = 0;trans<=k;trans++){
                if(days==n-1){
                    dp[days][0][trans]=0;
                    dp[days][1][trans]=(trans>=1)?prices[days]:0;
                }
                else{
                    dp[days][0][trans]=max(-prices[days]+dp[days+1][1][trans],dp[days+1][0][trans]);
                    dp[days][1][trans]=max(((trans>=1)?prices[days]+dp[days+1][0][trans-1]:0),dp[days+1][1][trans]);
                }
            }
        }    
        return dp[0][0][k];
    }
};
