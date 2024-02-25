class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> temp_vec;
        bool last_vec = false;
        
        sort(intervals.begin(), intervals.end(), sortcol);
        for(int i = 0; i < intervals.size() and !last_vec; i++) {
            temp_vec.push_back(intervals[i][0]);
            int new_end = intervals[i][1];
            for(int j = i + 1; j < intervals.size(); j++) {
                if(intervals[j][0] <= new_end) {
                    new_end = max(new_end, intervals[j][1]);
                    if (j == intervals.size() - 1) {
                        last_vec = true;
                        cout<<"True";
                    }
                    continue;
                } else {
                    temp_vec.push_back(new_end);
                    ans.push_back(temp_vec);
                    temp_vec.clear();
                    i = j - 1;
                    break;
                }
            }
            if(temp_vec.size() == 1) {
                temp_vec.push_back(new_end);
                ans.push_back(temp_vec);
                temp_vec.clear();
            }
        }
        return ans;
    }
};