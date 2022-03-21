class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
       long int chain[100000] ={0};
       vector<int> ans;
        int n = arr.size();
	   
        unordered_map<int,int>mp;
	   for(int i=0;i<n;i++)
	   {
	       if(mp.find(target-arr[i])!=mp.end())
	       {
	           ans.push_back(i);
                for(int j=0;j<n;j++){
                    // Every input would have exactly one solution, and we want to avoid using                     // the same element twice.
                    if (arr[j] == target - arr[i] && j!=i){
                        ans.push_back(j);
                    }
                }
	       }
	       mp[arr[i]]=i;
	   }
        return ans;
    }
};