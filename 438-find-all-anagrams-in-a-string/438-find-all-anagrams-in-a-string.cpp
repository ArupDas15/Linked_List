class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<char,int>um;
        for(int i=0;i<p.length();i++){
            um[p[i]]++;    
        }
        int count=um.size();
        int i=0,j=0,k=p.length();
        while(j<s.length()){
            //calculation
            if(um.find(s[j])!=um.end()){
                    um[s[j]]--;
                    if(um[s[j]]==0)
                        count--;
                }
            if(j-i+1<k){
                
                j++;
            }
            else if(j-i+1==k){
                if(count==0){
                    ans.push_back(i);
                }
                if(um.find(s[i])!=um.end()){
                    if(um[s[i]]==0){
                        count++;
                    }
                    cout<<s[i];
                    um[s[i]]++;
                }
                i++;
                j++;
            }
                
        }
        
        return ans;
    }
};