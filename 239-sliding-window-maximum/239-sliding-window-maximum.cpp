class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;//Starting index of Window
        int j=0;//ending index of Window
        list<int>l;//Stores all the candidates which can be maximum within the current window.
        vector<int> ans;//Stores the maximum element in every sliding window.
        while(j<nums.size()){
            // Remove all the elements which are less than the current element because they
            // are to the left of the current element. Hence they never be a candidate for
            // maximum element.
            while(l.back()<nums[j]&&l.size()>0){
                l.pop_back();
            }
            l.push_back(nums[j]);
            if(j-i+1<k){
                j++;
            }
            else if (j-i+1==k){
                // Calculating the ans and storing it in ans vector.
                ans.push_back(l.front());
                // Removing the ith element fron the candidate list if present.
                if(nums[i]==l.front()){
                    l.pop_front();
                }
                //Slide the Window.
                i++;
                j++;
            }
        }// end of while-loop.
        return ans;
    }
};