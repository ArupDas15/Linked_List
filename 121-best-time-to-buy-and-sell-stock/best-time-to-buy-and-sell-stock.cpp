class Solution {
public:
    /*ALGORITHM
    1. create a veriable minbp for denoting minimum stock buying price
    2. initialise minbp = prices[0], profit = 0
    3. Run a  loop from 1 to prices.size()
        3.1. cur_profit = prices[i] - minbp
        3.2. profit = max(profit, cur_profit)
        3.3. minbp = min(minbp, prices[i])
    4. return profit
    Time Complexity: O(n)
    Space complexity: O(n)
    */
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minbp = prices[0];

        for(int i = 1; i < prices.size(); i++) {
            int cur_profit = prices[i] - minbp;
            profit = max(profit, cur_profit);
            minbp = min(minbp, prices[i]);
        }
        return profit;
    }
};