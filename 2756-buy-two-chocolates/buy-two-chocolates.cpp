class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int buyChoco(vector<int>& prices, int money) {
        int smallest = INT_MAX;
        int second_smallest = INT_MAX - 1;
        long int amnt;

        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < smallest) {
                second_smallest = smallest;
                smallest = prices[i];
            } else if(prices[i] < second_smallest) {
                second_smallest = prices[i];
            }
        }
        
        amnt = (long)smallest + (long)second_smallest;
        return  amnt <= money ? 
                ((long)money) - amnt : money;
    }
};