class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long int sum = accumulate(skill.begin(),skill.end(),0);
        long long int ans = 0;

        long long int target = sum/(skill.size()/2);
        for(int i = 0, j = skill.size()-1; i<j; i++, j--) {
            if ((long long int )skill[i] + (long long int )skill[j] == target) {
                ans = ans + (skill[i]*skill[j]);
            } else {
                return -1;
            }
        }
        return ans;
    }
};