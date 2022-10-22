//  Best Time to Buy and Sell Stock with Transaction Fee - Medium - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
class Solution {
public:
    int solve(int i, bool own, int fee, vector<int>&prices,vector<vector<int>>&dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][own]!=-1)return dp[i][own];
        if(own){
            int option1 = prices[i] + solve(i+1,!own, fee, prices,dp);
            int option2 = solve(i+1, own,fee, prices,dp);
            return dp[i][own]=max(option1, option2);
        }
        else{
            int option1 = -(prices[i]+fee) + solve(i+1, 1, fee, prices,dp);
            int option2 = solve(i+1, 0, fee, prices,dp);
            return dp[i][own]=max(option1,option2);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size()==0)return 0;
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0,0,fee,prices,dp);
    }
};
