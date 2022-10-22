// Best Time to Buy and Sell Stock with Cooldown - MEDIUM - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
class Solution {
public:
    int solve(int i, bool own, bool cool, vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][own][cool]!=-1)return dp[i][own][cool];
        if(own){
            // You are selling your stock so cool down will apply.
            int option1 = prices[i] + solve(i+1, 0, 1, prices,dp);
            // You are not selling your stock(you are still owning the stock) so cool down will not apply.
            int option2 = solve(i+1, 1, 0, prices,dp);
            return dp[i][own][cool]=max(option1, option2);
        }
        else{
            // if cool down is applicable then profit is 0 else you can buy the stock so you are loosing the money at prices[i].
            int option1 = (cool) ? 0 : (-prices[i] + solve(i+1, 1, 0, prices,dp));
            // you are not buying the stock so you dont care about cool down. Even if there was cool down since you are not making a purchase cool down is set to 0.
            int option2 = solve(i+1, 0, 0, prices,dp);
            return dp[i][own][cool]=max(option1,option2);
        }
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)return 0;
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(0,0,0,prices,dp);
    }
};
