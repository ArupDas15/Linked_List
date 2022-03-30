class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for(auto i : nums) ++counts[i];
        
        vector<vector<int>> buckets(nums.size() + 1);
        for(auto & k : counts) 
            buckets[k.second].push_back(k.first);
        
        reverse(begin(buckets),end(buckets));
        for (int i = 0; i < buckets.size(); i++){
            // Sorting the elements in a vecotr in dreasing order.
            sort(buckets[i].begin(),buckets[i].end(),greater<int>());
        }
        
        vector<int> res;
        for(auto & bucket: buckets) 
            for(auto i : bucket) {
                res.push_back(i);
                if(res.size() == k) return res;
            }
      
        return res;
    }
};