class Solution {
public:
    // Time complexity: O(n⋅logn) for sort.
    // Space complexity: O(n) for arrival array.
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int ans = 0;
        vector<float> arrival(dist.size(), 0);

        for(int i = 0; i < dist.size(); i++) {
            arrival[i] = ((float) dist[i]) / ((float) speed[i]);
        }
        sort(arrival.begin(), arrival.end());
        for(int i = 0; i < arrival.size(); i++) {
            if(arrival[i] > i) ans++;
            else break;
        }
        return ans;
    }
};
