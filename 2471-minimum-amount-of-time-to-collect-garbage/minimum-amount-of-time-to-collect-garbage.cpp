class Solution {
public:
    // time complexity: O(nm)
    // space complexity: O(n)
    int garbageCollection(vector<string>& garbage, vector<int>& travel){

        int ans = 0;
        int lastm_idx = 0;
        int lastp_idx = 0;
        int lastg_idx = 0;
        vector<int> m_count(garbage.size(), 0);
        vector<int> p_count(garbage.size(), 0);
        vector<int> g_count(garbage.size(), 0);

        for(int i = 0; i < garbage.size(); i++) {
            for(int j = 0; j < garbage[i].length(); j++) {
                switch(garbage[i][j]){
                    case 'M': m_count[i]++;
                              lastm_idx=i;
                              break;
                    case 'P': p_count[i]++;
                              lastp_idx=i;
                              break;
                    default : g_count[i]++;
                              lastg_idx=i;
                }
            }
        }
        for(int i = 0; i < m_count.size(); i++) {
            if(i > 0) {
                if (i <= lastm_idx) ans = ans + travel[i - 1];
                if (i <= lastp_idx) ans = ans + travel[i - 1];
                if (i <= lastg_idx) ans = ans + travel[i - 1];
            }
            ans = ans + m_count[i] + p_count[i] + g_count[i];
        }
        return ans;    
    }
};