class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map <int,int> um;
        int maxLen=INT_MIN;
        int i=0,j=0;
        while(j<fruits.size()){
            um[fruits[j]]++;
            if(um.size()==2)
                maxLen=max(maxLen,j-i+1);
            else if(um.size()>2){
                while(um.size()>2){
                    um[fruits[i]]--;
                    if(um[fruits[i]]==0)
                        um.erase(fruits[i]);
                    i++;
                }
            }
            j++;
        }
        if(um.size()<2)
            return fruits.size();
        return maxLen;
    }
};