class Solution {
public:
    int countOfSubsetSum(vector<int> arr, int n, int sum){
        int t[n+1][sum+1];
        // Table initialisation using base condition.
        for(int i=0;i<sum+1;i++){
            t[0][i]=0;
        }
        t[0][0]=1;
        // Choice Diagram Code implementation.
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        cout<<"sum= "<<sum<<"; "<<t[n][sum]<<endl;
        return t[n][sum];
	}
    int findTargetSumWays(vector<int>& nums, int target) {
        if (nums.size()<2 && target > nums[0])
            return 0;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum = sum + nums[i];
        }

        if((sum+target)%2!=0)
            return 0;
        return countOfSubsetSum(nums,nums.size(),abs((sum+target)/2));
    }
};