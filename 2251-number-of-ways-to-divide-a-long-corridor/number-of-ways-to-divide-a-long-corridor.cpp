class Solution {
public:
    const int MOD = 1e9 + 7;
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int numberOfWays(string corridor) {
        int count = 0;
        long long int ans = 1;
        int seat = 0;
        
        for(char ch : corridor) {
            if(ch == 'S') {
                count++;
            }
        }
        if(count % 2 != 0 or count == 0) {
            return 0;
        }
        for(int i = 0; i < corridor.length()-1; i++) {
            if(corridor[i] == 'S') {
                seat++;
                if(seat == 2) {
                    int plant_cnt = 1;

                    i++;
                    while(i < corridor.length() && corridor[i] != 'S') {
                        i++;
                        plant_cnt++;
                    }
                    if(i == corridor.length()) {
                        break;
                    }
                    ans = (ans * plant_cnt) % MOD;
                    i--;
                    seat = 0;
                }
            }
        }
        return ans;
    }
};