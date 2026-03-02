# define N 2
class Solution {
struct trienode {
    int number;
    trienode* child[N];
    trienode() {
        for(int i = 0; i < N; i++) {
            child[i] = NULL;
        }
    }
};
trienode* root;
// Time complexity to build trie Data structure: O(32*n) = O(n)
// Space Complexiy: O(Total number of characters * aplhabet_Size)
// if M is average key lengtah and N is total number of keys with alphabet size R
// then space complexity = O(N*M*R) 
// Here every number create a node of length 32 characters O(32N)
void TrieInsert(string s, int no) {
    trienode* curr = root;
    int idx;
    for(int i = 0; i< s.length(); i++) {
        int idx = s[i] == '0'? 0 : 1;
        if(!curr->child[idx]) 
            curr->child[idx]=new trienode();
        curr = curr->child[idx];  
    }    
    curr->number = no;
}

string convert2String(int num, int size) {
    string sol;
    int len=0;
    while(num>0) {
        sol.push_back(num%2 + '0');
        num=num/2;  
        len++;
    }
    for(;len < size;len++) {
        sol.push_back('0');
    }
    reverse(sol.begin(), sol.end());
    return sol;
}
void int2String(vector<int>& nums, vector<string>& nums_str) {
    int max_num=*max_element(nums.begin(),nums.end());
    int maxbits=max_num>1?log2(max_num)+1:1;
    for(int i = 0; i < nums.size(); i++) {
        nums_str.push_back(convert2String(nums[i], maxbits));
    }
}
// Time complexity: O(n) where n is the length of the word to search
int searchMaxInTrie(string candidate) {
    trienode* curr = root;
    int idx;
    for(int i = 0; i < candidate.length(); i++) {
        // invert candidate and check in trie for maximal result.
        idx = candidate[i] == '0'? 1 : 0; 
        if(curr->child[idx]) {
            curr=curr->child[idx];
        } else {
            curr=curr->child[!idx];
        }
    }
    return curr->number;
}
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new trienode();// initialise trie.
        vector<string> nums_str;
        // convert int vector nums to vector of binary string nus_str
        int2String(nums, nums_str);
        for(int i = 0 ; i < nums.size(); i++) {
            TrieInsert(nums_str[i], nums[i]);
        }
        int maxXor = 0;
        for(int i = 0; i < nums.size(); i++) {
            maxXor = max(maxXor, nums[i]^searchMaxInTrie(nums_str[i]));
        }
        return maxXor;
    }
};