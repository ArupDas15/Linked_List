class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
    int rem;
    unordered_map<int,int> freq_count;
    for(int i=0;i<arr.size();i++){
        rem = ((arr[i]%k)+k)%k;
        freq_count[rem]=freq_count[rem]+1;
    }
        for(auto i:arr){
            rem = ((i%k)+k)%k;
            if (rem==0&&((freq_count[rem]&1)==0)){
                continue;
            }
            
            else if (freq_count[k-rem]==freq_count[rem]){
                continue;
            }
            else{
                return false;
            }
        }
            
        return true;
    }
};