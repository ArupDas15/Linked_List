class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> umap;
        vector<int>res;
        int n=nums1.size(),m=nums2.size();
        for(int i=0;i<n;i++){
				umap[nums1[i]] = 1;	
			}
			for(int i=0;i<m;i++){
			    if (umap.find(nums2[i])!= umap.end()){
                    if(umap[nums2[i]]==1) {
                        res.push_back(nums2[i]);
                        umap[nums2[i]]=2;
                    }
                }
            }
        return res;
    }
};