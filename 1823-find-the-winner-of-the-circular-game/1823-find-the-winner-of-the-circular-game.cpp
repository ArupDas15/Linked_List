class Solution {
public:
    void solve(vector<int> Person, int sword_index, int k, int& ans){
      if(Person.size() == 1){
          ans = Person[0];
          return;
      }
      // Make the input smaller
      int execution_index = (sword_index + k) % Person.size();
      Person.erase(Person.begin() + execution_index);
      
      // Updating sword_index in the circular aaray.
      sword_index = execution_index;
      
      // Hypothesis
      solve(Person, sword_index, k, ans);
  }
    int findTheWinner(int n, int k) {
        vector<int>Person;
        for(int i = 1; i <= n; i++){
            Person.push_back(i);
        }
         k = k - 1;
        int sword_index = 0;
        int ans;
        solve(Person, sword_index, k, ans);
        return ans;
    }
};