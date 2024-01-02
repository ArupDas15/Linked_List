class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int cnt = 0;
	    vector<vector<int>> ans;
	    unordered_map<int, int> mp;
        set<int> o_set; 

	    for(int i = 0; i < nums.size(); i++) {
	        if(mp.find(nums[i]) != mp.end()) {
	            mp[nums[i]] += 1;
	        } else {
		        mp[nums[i]] = 1;
            }
            o_set.insert(nums[i]);
	    }

    	while(cnt < nums.size()){
	    	vector<int> temp;		

	    	for (auto it = o_set.begin(); it != o_set.end(); ++it) {
		        int key = *it;

                if(mp[key] > 0) {
		    	    temp.push_back(key);
			        mp[key] -= 1;
			        cnt++;
		        }
		    }
		ans.push_back(temp);
	}
	return ans;       
    }
};