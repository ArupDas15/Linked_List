class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int t[amount + 1];
	    // sort(coins.begin(), coins.end());
	    t[0] = 0;
	    for(int i = 1; i < amount + 1; i++){
	        t[i] = INT_MAX;
            for(int c = 0; c < coins.size(); c++){
	            if(i-coins[c] >= 0){
	                if(t[i-coins[c]] != INT_MAX)
	                    t[i] = min(t[i],t[i-coins[c]]+1);
	            }
	            // else break;
	        }
	    }
	    return t[amount] == INT_MAX? -1 : t[amount];
    }
};